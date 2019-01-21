#include "游戏服务器.h"
#include <atomic> 
#include "E:\\中国象棋\\象棋走棋规则\\象棋走棋规则\\棋谱生成.h"
#pragma comment(lib,"E:\\中国象棋\\象棋走棋规则\\Release\\象棋走棋规则.lib") 

class ChessServ : public protocolDemo, public CPP_Server {
public:
	string GenerateRetMsg(string &_Head,string &Body) {
		string f_l = GenerateFIRSTBYTES(_Head.length());
		string s_l = GenerateSECONDBYTES(Body.length());
		return f_l + s_l + _Head + Body;
	}
};

ChessServ Serv;

#include <thread>
#include <mutex>
#include <map>
using namespace std;

// 连接的socket玩家Id ，没有Id桌子为-1

//在线用户列表
map<int, S_PlayInfo> UserLineList;
mutex Mutex_UserLineList;

struct S_ChessTable_EX {
	S_ChessTable cht;
	mutex Mutex; //操作桌子的锁
public:void BroadCastVisitors(Head &H, string &body);
public:void BroadCastPlay(Head &H, string &body);
	set<int> visitors; //根据ID区别 做消息发言
};

//函数要在锁里面
void S_ChessTable_EX::BroadCastVisitors(Head &H,string &body){
	string Senddata = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), body);
	set<int>::iterator it;
	for (it = visitors.begin(); it != visitors.end();) {
		int Id = *it;
		S_PlayInfo spi =  FindLineList(Id);
		if (!Serv.Send(spi.sock, Senddata)) {
			visitors.erase(it++);
		}
		else {
			it++;
		}
	}
}
//函数要在锁里面
void S_ChessTable_EX::BroadCastPlay(Head &H, string &body) {
	string Senddata = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), body);
	S_PlayInfo spi0 = FindLineList(cht.sss[0].UserId);
	S_PlayInfo spi1 = FindLineList(cht.sss[1].UserId);
	if (!Serv.Send(spi0.sock, Senddata)) {
		cht.sss[0].Status = GAMESTATUS_OUTLINE; //断线
	}
	if (!Serv.Send(spi1.sock, Senddata)) {
		cht.sss[1].Status = GAMESTATUS_OUTLINE; //断线
	}
}

void BroadCastAllLoginUser(Head &H,string &Data) {
	Mutex_UserLineList.lock();
	string SendData = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), Data);
	map<int, S_PlayInfo>::iterator it =  UserLineList.begin();
	for (; it != UserLineList.end(); it++) {
		SOCKET s = it->second.sock;
		Serv.Send(s,SendData);
	}
	Mutex_UserLineList.unlock();
}


S_ChessTable_EX CTEs[10]; //10个桌子

void ServOpen(int port) {
	Serv.Open(port);
	Serv.SetServfun(ServFunction);
	Serv.Acpt();
	InitTable();
}

void InitTable() {
	thread t(BrokenLineProcess);
	t.detach();
	for (int i = 0; i < 10; i++) {
		memset(&CTEs[i].cht,0x00,sizeof(CTEs[i].cht));
		CTEs[i].cht.TableId = i;
		CTEs[i].cht.sss[0].UserId = -1;
		CTEs[i].cht.sss[1].UserId = -1;
		CTEs[i].cht.SerialNumber = -1;
		CTEs[i].cht.MoveResult = MOVE_RESULT_NORESULT;
	}
}

//断线map  UserId 断线时间
map<int, S_PlayInfo> BrokenLineList;
mutex Mutex_BrokenLineList;
void BrokenLineProcess() {
	while (1) {
		int TimeNow = time(NULL);
		Mutex_BrokenLineList.lock();
		map<int, S_PlayInfo>::iterator it = BrokenLineList.begin();
		for (; it != BrokenLineList.end();) {
			int UserId = it->first;
			S_PlayInfo spi = it->second;
			if (TimeNow - spi.LineBrokenTime >= 30) { //超过30秒 在桌子上移除并且
				BrokenLineList.erase(it++);
				GameOver(spi.sock, UserId, 0x02); //断网
				LeaveTable(spi.sock, UserId); //离开桌子 ，桌子上移除
				DeleteLineList(UserId); //从在线列表移除
			}
			else if (spi.GameStatus != GAMESTATUS_OUTLINE) { //判定为重新登入
				BrokenLineList.erase(it++);
			}
			else {
				it++;
			}
		}
		Mutex_BrokenLineList.unlock();
		Sleep(1000);
	}
}

void AddBrokenLineList(int UserId, S_PlayInfo _spi){
	Mutex_BrokenLineList.lock();
	_spi.LineBrokenTime = time(NULL);
	BrokenLineList[UserId] = _spi;
	Mutex_BrokenLineList.unlock();
}
void DeleteBrokenLineList(int UserId) {
	Mutex_BrokenLineList.lock();
	BrokenLineList.erase(UserId);
	Mutex_BrokenLineList.unlock();
}


void  HandleSocket(SOCKET s) {
	int UserId = -1;
	while (1) {

		uint f_l = 0;
		if (!Serv.RecvFIRSTBYTES(s, f_l)) {
			break;
		}
		uint s_l = 0;
		if (!Serv.RecvSECONDBYTES(s, s_l)) {
			break;
		}
		string f_s;
		if (!Serv.RecvFIRST(s, f_l, f_s)) {
			break;
		}

		string s_s;
		if (!Serv.RecvSECOND(s, s_l, s_s)) {
			break;
		}
		Head H;
		memcpy(&H, f_s.c_str(), sizeof(Head));
		switch (H.Type) {
		case	HEAD_VISITORLOGIN: //游客登入
			if (UserId != -1) {
				SendError(s, string("您已登入，不能重复登入"));
				break;
			}
			UserId = VisitorLogin(s);
			break;
		case	HEAD_USERSELECTSEAT: { //用户选择座位
			S_SelectSeat sss;
			memcpy(&sss, s_s.c_str(), sizeof(S_SelectSeat));
			UserSelectSeat(s, UserId, sss.SeatId, sss.TableId);
			break;
		}
		case	HEAD_SENDREADY: { //用户准备
			UserReady(s,UserId);
			break;
		}
		case	HEAD_KAIJU:
			break;
		case	HEAD_MOVECHESS: {
			//用户走子
			S_ChessTable sct;
			memcpy(&sct, s_s.c_str(), s_s.length());
			MoveChess(s,UserId, sct);
			break;
		}
		case	HEAD_GAMEOVER: { //一般是在超时的时候 超时
			int Type;
			memcpy(&Type, s_s.c_str(), s_s.length());
			GameOver(s,UserId, Type);
			break;
		}
		case	HEAD_LEAVETABLE: {
			LeaveTable(s, UserId);
			break;
		}
		case HEAD_BROKENLINERECONNECTION: {
			memcpy(&UserId, s_s.c_str(), sizeof(int));
			if (!BreakReconnect(s, UserId)) UserId = -1;
			break;
		}
		case HEAD_GIVEUP: //认输
		{
			int Type;
			memcpy(&Type, s_s.c_str(), s_s.length());
			GameOver(s, UserId, Type);
			break;
		}
		case HEAD_SUEFORPEACE: //求和
		{
			S_SueForPeace sfp;
			memcpy(&sfp, s_s.c_str(), s_s.length());
			SueForPeace(s,UserId, sfp);
			break;
		}
		case HEAD_TAKEBACK: //悔棋
		{
			break;
		}
	//	case	HEAD_REGISTERLOGIN:
	//		break;
	//	case	HEAD_USERREGISTER:
	//		break;
		case	HEAD_ROOMINFO:
			SendRoomInfo(s);
			break;
		case	HEAD_PICTURELIST:
			SendPicture(s);
			break;
		case	HEAD_USERWATCHTABLE:
			break;
		case	HEAD_MESSAGE: {
			S_Message sm;
			memcpy(&sm,s_s.c_str(), s_s.length());
			Message(s, UserId, sm);
			break;
		}
		case HEAD_NETWORKPACKAGE: {
			string Senddata = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), s_s);
			Serv.Send(s,Senddata);
			break;
		}
		}
	}
	//在线列表删除
	//断线的机制
	S_PlayInfo spi =  FindLineList(UserId);
	if (spi.NowTableId != -1 ){ //还在桌子上
		if (spi.GameStatus == GAMESTATUS_GAMEING) { //如果在游戏发送断线通知
			spi.GameStatus = GAMESTATUS_OUTLINE; //
			//发送断线指令
			UpdateLineList(UserId, spi);
			UserOutLine(UserId);
			AddBrokenLineList(UserId, spi);
		}
		else { // 不在游戏但是在桌子
			LeaveTable(s, UserId);
			DeleteLineList(UserId);
		}
	}
	else { //没有在 桌子上
		DeleteLineList(UserId);
	}
	return;
}

int VisitorMax = 0;
mutex MutexVisitor;
int VisitorLogin(SOCKET s) {
	S_PlayInfo spi;
	memset(&spi, 0x00, sizeof(spi));
	MutexVisitor.lock();
	string Name = "游客";
	VisitorMax++;
	char buff[10];
	snprintf(buff, 10, "%d", VisitorMax);
	Name += buff;
	spi.id = VisitorMax;
	MutexVisitor.unlock();

	snprintf(spi.Name, sizeof(spi.Name), "%s", Name.c_str());
	snprintf(spi.HeadPictureName, sizeof(spi.HeadPictureName), "%s头像%d.jpeg", HEADPICSAVEPATH, VisitorMax%4+1);
	spi.FleeTimes = 0;
	spi.sock = s;
	spi.LostCount = 0;
	spi.NowTableId = -1;
	spi.Total = 0;
	spi.WinCount = 0;
	spi.GameStatus = GAMESTATUS_LOGIN;
	spi.NowSerialNumber = -1;
	spi.NowSeatId = -1;
	//发送回去 
	Head H;
	H.Id = spi.id;
	H.Type = HEAD_VISITORLOGIN;
	string body((char*)&spi, sizeof(S_PlayInfo));
	string HeadPicFile(HEADPICSAVEPATH);
	HeadPicFile += spi.HeadPictureName;
	fileSql fs;
	string HeadPicData = fs.Readfile(HeadPicFile);
	body += HeadPicData;
	string dataSend = Serv.GenerateRetMsg( string((char*)&H,sizeof(Head)), body);
	Serv.Send(s,dataSend);

	//加入在线列表
	AddLineList(spi.id, spi);
	SendError(s, spi.Name+ string(",您已登入成功"));
	return spi.id;
}

void SendRoomInfo(SOCKET s) {
	//遍历table
	Head H;
	H.Type = HEAD_ROOMINFO;
	S_TableInfo sti[10];
	int CTsSize = sizeof(sti);
	memset(sti, 0x00, CTsSize);
	char data[sizeof(sti)];
	for (int i = 0; i < 10; i++) {
		int Id1= CTEs[i].cht.sss[0].UserId;
		sti[i].spi[0] = FindLineList(Id1);
		int Id2 = CTEs[i].cht.sss[1].UserId;
		sti[i].spi[1] = FindLineList(Id2);
	}
	memcpy(data, sti, CTsSize);
	string SendData = Serv.GenerateRetMsg(string((char*)&H,sizeof(Head)), string(data, CTsSize));
	Serv.Send(s,SendData);
}

void GetTableInfo(SOCKET s,int UserId) {
	S_PlayInfo _spi = FindLineList(UserId);
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}

	int TableId = _spi.NowTableId;
	S_TableInfo sti;
	int Id1 = CTEs[TableId].cht.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = CTEs[TableId].cht.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);
	Head H; H.Type = HEAD_GETTABLEINFO;
	string SendData = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), string((char*)&sti, sizeof(S_TableInfo)));
	Serv.Send(s, SendData);
}


void SendPicture(SOCKET s) {
	for (int i = 1; i <= 4; i++) {
		Head H;
		H.Id = -1;
		H.Type = HEAD_PICTURELIST;
		string body;
		string HeadPicFile(HEADPICSAVEPATH);
		HeadPicFile += "头像";
		HeadPicFile = HeadPicFile + char(48 + i) +".jpeg";
		fileSql fs;
		string HeadPicData = fs.Readfile(HeadPicFile);
		char PicName[50];
		snprintf(PicName, 50, "%s", HeadPicFile.c_str());
		string PicNameS(PicName,50);
		body += PicNameS + HeadPicData;
		string dataSend = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), body);
		Serv.Send(s, dataSend);
		//Sleep(10);
	}
}

//用户选择座位
void UserSelectSeat(SOCKET s, int UserId, int SeatId, int TableId) {
	//验证是不是合法
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId != -1) {
		SendError(s, string("您已经登入桌子,请先退出桌子"));
		return;
	}
	if (SeatId != 0 && SeatId != 1) {
		SendError(s, string("选择座位失败"));
		return;
	}
	////////////////////////////
	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht;
	if (sct.sss[SeatId].UserId != -1) {
		SendError(s, string("该座位已经有人"));
		Mutex.unlock();
		return;
	}
	else {
		sct.sss[SeatId].Status = GAMESTATUS_INTABLE;
		sct.sss[SeatId].UserId = UserId;
		_spi.NowTableId = TableId;
		_spi.NowSeatId = SeatId;
		_spi.GameStatus = GAMESTATUS_INTABLE;
	}
	//广播 用户登入房间
	Head H;
	H.Type = HEAD_ENTERTABLE;
	S_EnterTable EnterTable;
	EnterTable.UserId = UserId;
	snprintf(EnterTable.Name,sizeof(EnterTable.Name),"%s",_spi.Name) ;
	UpdateLineList(UserId, _spi);
	string data = string((char*)&EnterTable, sizeof(S_EnterTable));
	CTEs[TableId].BroadCastPlay(H, data);
	CTEs[TableId].BroadCastVisitors(H, data);
	//再广播tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);

	//向所有的用户广播 选择桌子消息
	H.Type = HEAD_GETTABLEINFO;
	BroadCastAllLoginUser(H,string((char*)&sti,sizeof(S_TableInfo)));
    Mutex.unlock();

}


//用户准备 修改CTEs的值  返回红黑ID 红黑状态 ，
void UserReady(SOCKET s, int UserId) {
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}
	//验证合法

	int TableId = _spi.NowTableId;

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht; //修改游戏状态
	sct.sss[_spi.NowSeatId].Status = GAMESTATUS_READY;
	_spi.GameStatus = GAMESTATUS_READY;
	UpdateLineList(UserId, _spi);
	Head H;
	H.Type = HEAD_SENDREADY;
	S_GameReady sgr;
	sgr.UserId = UserId;
	snprintf(sgr.Name, sizeof(sgr.Name), "%s", _spi.Name);
	//分别向桌子里面的人发送
	CTEs[TableId].BroadCastPlay(H, string((char*)&sgr, sizeof(S_GameReady)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&sgr, sizeof(S_GameReady)));

	//再广播tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);
	//向所有的用户广播 用户准备消息
	H.Type = HEAD_GETTABLEINFO;
	BroadCastAllLoginUser(H, string((char*)&sti, sizeof(S_TableInfo)));

	if (sct.sss[0].Status == GAMESTATUS_READY && sct.sss[1].Status == GAMESTATUS_READY) {
		sct.SerialNumber = GetSeriesNum();
		sti.spi[0].GameStatus = GAMESTATUS_GAMEING;
		sti.spi[1].GameStatus = GAMESTATUS_GAMEING;
		sti.spi[0].NowSerialNumber = sct.SerialNumber;
		sti.spi[1].NowSerialNumber = sct.SerialNumber;
		_spi.GameStatus = GAMESTATUS_GAMEING;
		UpdateLineList(UserId, _spi);
		UpdateLineList(Id1, sti.spi[0]);
		UpdateLineList(Id2, sti.spi[1]);
		BroadCastAllLoginUser(H, string((char*)&sti, sizeof(S_TableInfo)));
		sct.sss[0].Status = GAMESTATUS_GAMEING;
		sct.sss[1].Status = GAMESTATUS_GAMEING;
		map<string, ChessPieceStatus>  temp;
		InitRedOpening(temp);
		ChessStatusToStruct(temp, sct.HongChessStatus);
		Head H; //开局确定红方黑方 返回红黑ID 红黑状态 下一轮走棋方
		H.Type = HEAD_KAIJU;
		//下一轮走棋方
		if (time(NULL) % 2 == 0) {
			sct.sss[0].Color = RED;
			sct.sss[1].Color = BLACK;
			sct.NextSeat = 0;
		}
		else {
			sct.sss[0].Color = BLACK;
			sct.sss[1].Color = RED;
			sct.NextSeat = 1;
		}
	
		//通知用户开局 
		sct.MoveResult = MOVE_RESULT_NORESULT;
		CTEs[TableId].BroadCastPlay(H, string((char*)&sct, sizeof(sct)));
		CTEs[TableId].BroadCastVisitors(H, string((char*)&sct, sizeof(sct)));
	}
	Mutex.unlock();
}


//求和
void SueForPeace(SOCKET s, int UserId, S_SueForPeace sfp) {
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}
	int TableId = _spi.NowTableId;

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht; //修改游戏状态
	//发送给对方
	int enemySeatId = (_spi.NowSeatId + 1) % 2;
	Head H;
	H.Type = HEAD_SUEFORPEACE;
	S_PlayInfo _spiEnemy = FindLineList(sct.sss[enemySeatId].UserId); 
	snprintf(sfp.Name,sizeof(sfp.Name),"%s", _spiEnemy.Name);
	string Senddata = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), string((char*)&sfp, sizeof(S_SueForPeace)));
	Serv.Send(_spiEnemy.sock, Senddata);
	Mutex.unlock();
	if (sfp.Type == PEACERAGREE) {
		GameOver(s,UserId,WINTYPE_PEACE);
	}
}

void MoveChess(SOCKET s, int UserId, S_ChessTable &sct) {
	//验证合法
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}


	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht; //修改游戏状态
	//发现下棋方是自己
	if (_spi.NowSeatId == _sct.NextSeat) {
		memcpy(_sct.HongChessStatus, sct.HongChessStatus, sizeof(sct.HongChessStatus));
		_sct.MoveResult = sct.MoveResult;
		Head H;
		H.Type = HEAD_MOVECHESS;
		//分别向桌子上的人发送
		CTEs[TableId].BroadCastPlay(H, string((char*)&_sct, sizeof(sct)));
		CTEs[TableId].BroadCastVisitors(H, string((char*)&_sct, sizeof(sct)));
		//判断是不是游戏结束
		if (_sct.MoveResult == MOVE_RESULT_GAME_HEISHENG || _sct.MoveResult == MOVE_RESULT_GAME_HONGSHENG) {
			Mutex.unlock();
			GameOver(s, UserId, 0x00);
			return;
		}
	}
	else {
		SendError(s, string("您不能走棋"));
		Mutex.unlock();
		return;
	}
	_sct.NextSeat = (_sct.NextSeat + 1) % 2;
	Mutex.unlock();
}

//游戏结束
void GameOver(SOCKET s,int UserId,int Type) {
	//判断谁是赢家 ，谁是输家 更新table状态 为 Intable
	//验证合法
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht;
	S_PlayInfo spi1 = FindLineList(_sct.sss[0].UserId);
	S_PlayInfo spi2 = FindLineList(_sct.sss[1].UserId);
	Head H;
	H.Type = HEAD_GAMEOVER;
	//分别向桌子上的人发送
	S_GameOver sgo;
	switch (Type) {
	case WINTYPE_JUESHA: { //正常
		sgo.WinType = 0x00;
		if (_sct.MoveResult == MOVE_RESULT_GAME_HONGSHENG) {
			sgo.WinFang = RED;
			if (_sct.sss[0].Color == RED) {
				snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi1.Name);
				snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi2.Name);
			}
			else {
				snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi2.Name);
				snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi1.Name);
			}
		}
		else if (_sct.MoveResult == MOVE_RESULT_GAME_HEISHENG) {
			sgo.WinFang = BLACK;
			if (_sct.sss[0].Color == BLACK) {
				snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi1.Name);
				snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi2.Name);
			}
			else {
				snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi2.Name);
				snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi1.Name);
			}
		}
		else {
			Mutex.unlock();
			return;
		}
		break;
	}
	case WINTYPE_GIVEUP: { //认输
		sgo.WinType = WINTYPE_GIVEUP;
		int LoseSeat = _spi.NowSeatId;
		int WinSeat = (_spi.NowSeatId + 1) % 2;
		if (WinSeat == 0) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi1.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi2.Name);
		}
		else if (WinSeat == 1) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi2.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi1.Name);
		}
		sgo.WinFang = _sct.sss[WinSeat].Color;
		break;
	}
	case WINTYPE_TIMEOUT: { //超时
		sgo.WinType = 0x01;
		int LoseSeat = _sct.NextSeat;
		int WinSeat = (_sct.NextSeat + 1) % 2;
		if (WinSeat == 0) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi1.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi2.Name);
		}
		else if (WinSeat == 1) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi2.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi1.Name);
		}
		sgo.WinFang = _sct.sss[WinSeat].Color;
		break;
	}
	case WINTYPE_OUTLINE: { //断网
		sgo.WinType = 0x02;
		if (spi1.GameStatus == GAMESTATUS_OUTLINE) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi2.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi1.Name);
			sgo.WinFang = _sct.sss[spi2.NowSeatId].Color;
		}
		else if (spi2.GameStatus == GAMESTATUS_OUTLINE) {
			snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", spi1.Name);
			snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spi2.Name);
			sgo.WinFang = _sct.sss[spi1.NowSeatId].Color;
		}
		else {
			Mutex.unlock();
			return;
		}
		break;
	}
	case WINTYPE_RUNAWAY: { //强行退出
		S_PlayInfo spitemp = FindLineList(UserId);
		sgo.WinType = WINTYPE_RUNAWAY;
		int WinSeat = (_spi.NowSeatId + 1) % 2;
		int LoseSeat = _spi.NowSeatId;
		sgo.WinFang = _sct.sss[WinSeat].Color;
		S_PlayInfo winspi = FindLineList(_sct.sss[WinSeat].UserId);
		snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", winspi.Name);
		snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spitemp.Name);
		break;
	}
	case WINTYPE_PEACE: {
		S_PlayInfo spitemp = FindLineList(UserId);
		sgo.WinType = WINTYPE_PEACE;
		int WinSeat = (_spi.NowSeatId + 1) % 2;
		int LoseSeat = _spi.NowSeatId;
		sgo.WinFang = _sct.sss[WinSeat].Color;
		S_PlayInfo winspi = FindLineList(_sct.sss[WinSeat].UserId);
		snprintf(sgo.WinName, sizeof(sgo.WinName), "%s", winspi.Name);
		snprintf(sgo.LoseName, sizeof(sgo.LoseName), "%s", spitemp.Name);
	}
	}
	CTEs[TableId].BroadCastPlay(H, string((char*)&sgo, sizeof(sgo)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&sgo, sizeof(sgo)));
	_sct.MoveResult = MOVE_RESULT_NORESULT; //初始化为 noresult
	_spi.GameStatus = GAMESTATUS_INTABLE;
	UpdateLineList(UserId, _spi);
    Mutex.unlock();
}

void Message(SOCKET s, int UserId, S_Message &sm) {
	S_PlayInfo _spi = FindLineList(UserId);
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	Head H;
	H.Type = HEAD_MESSAGE;
	snprintf(sm.Name, sizeof(sm.Name), "%s", _spi.Name);
	CTEs[TableId].BroadCastPlay(H, string((char*)&sm, sizeof(S_Message)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&sm, sizeof(S_Message)));
	Mutex.unlock();
}
bool BreakReconnect(SOCKET s, int UserId) {
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return false;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	mutex &Mutex = CTEs[TableId].Mutex;
	if (_spi.id == -1) { // 已经超时
		SendError(s, string("请重新登入"));
		return false;
	}
	else {
		Mutex.lock();
		DeleteBrokenLineList(UserId);
		//群发用户重新登入消息
		Head H;
		H.Type = EVENT_USERREONLINE;
		S_UserReConnect surc; 
		surc.UserId = UserId;
		snprintf(surc.Name, sizeof(surc.Name), "%s", _spi.Name);
		_spi.sock = s;
		_spi.GameStatus = GAMESTATUS_GAMEING;
		UpdateLineList(UserId, _spi);
		CTEs[TableId].BroadCastPlay(H, string((char*)&surc, sizeof(S_UserReConnect)));
		CTEs[TableId].BroadCastVisitors(H, string((char*)&surc, sizeof(S_UserReConnect)));
		//发送现在 桌子的全部信息
		H.Type = HEAD_GETCHESSTABLE;
		string dataSend = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), string(( char*)&CTEs[TableId].cht,sizeof(S_ChessTable)));
		Serv.Send(s, dataSend);
		Mutex.unlock();
	}
	return true;
}
//特指 游戏玩家离开
void LeaveTable(SOCKET s, int UserId) {
	if (UserId == -1) {
		SendError(s, string("用户请先登入"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("用户没有选择座位桌子"));
		return;
	}

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht;
	_sct.sss[_spi.NowSeatId].UserId = -1;

	_spi.GameStatus = GAMESTATUS_LOGIN;
	_spi.NowTableId = -1;
	Head H;
	S_LeaveTable sl;
	if (_sct.MoveResult == MOVE_RESULT_NORESULT) sl.LeaveType = true;
	else {
		sl.LeaveType = false;
		Mutex.unlock();
		GameOver(s, UserId, 0x03);
		Mutex.lock();
	}
	UpdateLineList(UserId, _spi);
	snprintf(sl.Name, sizeof(sl.Name), "%s", _spi.Name);
	H.Type = HEAD_LEAVETABLE;
	CTEs[TableId].BroadCastPlay(H, string((char*)&sl, sizeof(S_LeaveTable)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&sl, sizeof(S_LeaveTable)));
	//再广播tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = _sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = _sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);
	//向所有的用户广播 用户准备消息
	H.Type = HEAD_GETTABLEINFO;
	BroadCastAllLoginUser(H, string((char*)&sti, sizeof(S_TableInfo)));

	Mutex.unlock();
}

//用户在游戏中 发送断线指令
void UserOutLine(int UserId) {
	if (UserId == -1) {
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		return;
	}

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht;

	S_UserOutLine suol;
	suol.UserId = UserId;
	snprintf(suol.Name, sizeof(suol.Name), "%s", _spi.Name);
	Head H;
	H.Type = EVENT_USEROUTLINE;
	CTEs[TableId].BroadCastPlay(H, string((char*)&suol, sizeof(S_UserOutLine)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&suol, sizeof(S_UserOutLine)));
	Mutex.unlock();
}
void SendError(SOCKET s, string &err) {
	Head H; H.Type = HEAD_ERROR;
	string data = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), err);
	Serv.Send(s,data);
}

//循环遍历CTs 200个桌子

void ServClose() {
	Serv.Destroy();
}

int MaxLineNumber = 200;

atomic_int LoginNumber = 0;

void ServFunction(SOCKET s) {
	if (LoginNumber > MaxLineNumber) {
		//人数过多 ，服务器超载
		closesocket(s);
		return;
	}
	else {
		LoginNumber++;
	}
	thread t(HandleSocket, s);
	t.detach();
}
void AddLineList(int &Id, S_PlayInfo &spi) {
	Mutex_UserLineList.lock();
	LoginNumber++;
	UserLineList[Id] = spi;
	Mutex_UserLineList.unlock();
}
void DeleteLineList(int &Id) {
	Mutex_UserLineList.lock();
	LoginNumber--;
	closesocket(UserLineList[Id].sock);
	UserLineList.erase(Id);
	Mutex_UserLineList.unlock();
}

void UpdateLineList(int &Id, S_PlayInfo &spi) {
	if (Id == -1) return;
	Mutex_UserLineList.lock();
	UserLineList[Id] = spi;
	Mutex_UserLineList.unlock();
}

S_PlayInfo FindLineList(int &Id) {
	S_PlayInfo spi;
	memset(&spi, -1, sizeof(S_PlayInfo));
	Mutex_UserLineList.lock();
	if (UserLineList.count(Id) == 1)
		spi = UserLineList[Id];
	Mutex_UserLineList.unlock();
	return spi;
}

map<int, S_PlayInfo> GetLineLists() {
	return UserLineList;
}


//用户下棋的 流水号
int GetSeriesNum() {
	static int SerialNumber = 0;
	SerialNumber++;
	return SerialNumber;
}