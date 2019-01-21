#include "��Ϸ������.h"
#include <atomic> 
#include "E:\\�й�����\\�����������\\�����������\\��������.h"
#pragma comment(lib,"E:\\�й�����\\�����������\\Release\\�����������.lib") 

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

// ���ӵ�socket���Id ��û��Id����Ϊ-1

//�����û��б�
map<int, S_PlayInfo> UserLineList;
mutex Mutex_UserLineList;

struct S_ChessTable_EX {
	S_ChessTable cht;
	mutex Mutex; //�������ӵ���
public:void BroadCastVisitors(Head &H, string &body);
public:void BroadCastPlay(Head &H, string &body);
	set<int> visitors; //����ID���� ����Ϣ����
};

//����Ҫ��������
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
//����Ҫ��������
void S_ChessTable_EX::BroadCastPlay(Head &H, string &body) {
	string Senddata = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), body);
	S_PlayInfo spi0 = FindLineList(cht.sss[0].UserId);
	S_PlayInfo spi1 = FindLineList(cht.sss[1].UserId);
	if (!Serv.Send(spi0.sock, Senddata)) {
		cht.sss[0].Status = GAMESTATUS_OUTLINE; //����
	}
	if (!Serv.Send(spi1.sock, Senddata)) {
		cht.sss[1].Status = GAMESTATUS_OUTLINE; //����
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


S_ChessTable_EX CTEs[10]; //10������

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

//����map  UserId ����ʱ��
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
			if (TimeNow - spi.LineBrokenTime >= 30) { //����30�� ���������Ƴ�����
				BrokenLineList.erase(it++);
				GameOver(spi.sock, UserId, 0x02); //����
				LeaveTable(spi.sock, UserId); //�뿪���� ���������Ƴ�
				DeleteLineList(UserId); //�������б��Ƴ�
			}
			else if (spi.GameStatus != GAMESTATUS_OUTLINE) { //�ж�Ϊ���µ���
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
		case	HEAD_VISITORLOGIN: //�ο͵���
			if (UserId != -1) {
				SendError(s, string("���ѵ��룬�����ظ�����"));
				break;
			}
			UserId = VisitorLogin(s);
			break;
		case	HEAD_USERSELECTSEAT: { //�û�ѡ����λ
			S_SelectSeat sss;
			memcpy(&sss, s_s.c_str(), sizeof(S_SelectSeat));
			UserSelectSeat(s, UserId, sss.SeatId, sss.TableId);
			break;
		}
		case	HEAD_SENDREADY: { //�û�׼��
			UserReady(s,UserId);
			break;
		}
		case	HEAD_KAIJU:
			break;
		case	HEAD_MOVECHESS: {
			//�û�����
			S_ChessTable sct;
			memcpy(&sct, s_s.c_str(), s_s.length());
			MoveChess(s,UserId, sct);
			break;
		}
		case	HEAD_GAMEOVER: { //һ�����ڳ�ʱ��ʱ�� ��ʱ
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
		case HEAD_GIVEUP: //����
		{
			int Type;
			memcpy(&Type, s_s.c_str(), s_s.length());
			GameOver(s, UserId, Type);
			break;
		}
		case HEAD_SUEFORPEACE: //���
		{
			S_SueForPeace sfp;
			memcpy(&sfp, s_s.c_str(), s_s.length());
			SueForPeace(s,UserId, sfp);
			break;
		}
		case HEAD_TAKEBACK: //����
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
	//�����б�ɾ��
	//���ߵĻ���
	S_PlayInfo spi =  FindLineList(UserId);
	if (spi.NowTableId != -1 ){ //����������
		if (spi.GameStatus == GAMESTATUS_GAMEING) { //�������Ϸ���Ͷ���֪ͨ
			spi.GameStatus = GAMESTATUS_OUTLINE; //
			//���Ͷ���ָ��
			UpdateLineList(UserId, spi);
			UserOutLine(UserId);
			AddBrokenLineList(UserId, spi);
		}
		else { // ������Ϸ����������
			LeaveTable(s, UserId);
			DeleteLineList(UserId);
		}
	}
	else { //û���� ������
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
	string Name = "�ο�";
	VisitorMax++;
	char buff[10];
	snprintf(buff, 10, "%d", VisitorMax);
	Name += buff;
	spi.id = VisitorMax;
	MutexVisitor.unlock();

	snprintf(spi.Name, sizeof(spi.Name), "%s", Name.c_str());
	snprintf(spi.HeadPictureName, sizeof(spi.HeadPictureName), "%sͷ��%d.jpeg", HEADPICSAVEPATH, VisitorMax%4+1);
	spi.FleeTimes = 0;
	spi.sock = s;
	spi.LostCount = 0;
	spi.NowTableId = -1;
	spi.Total = 0;
	spi.WinCount = 0;
	spi.GameStatus = GAMESTATUS_LOGIN;
	spi.NowSerialNumber = -1;
	spi.NowSeatId = -1;
	//���ͻ�ȥ 
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

	//���������б�
	AddLineList(spi.id, spi);
	SendError(s, spi.Name+ string(",���ѵ���ɹ�"));
	return spi.id;
}

void SendRoomInfo(SOCKET s) {
	//����table
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
		SendError(s, string("�û����ȵ���"));
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
		HeadPicFile += "ͷ��";
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

//�û�ѡ����λ
void UserSelectSeat(SOCKET s, int UserId, int SeatId, int TableId) {
	//��֤�ǲ��ǺϷ�
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId != -1) {
		SendError(s, string("���Ѿ���������,�����˳�����"));
		return;
	}
	if (SeatId != 0 && SeatId != 1) {
		SendError(s, string("ѡ����λʧ��"));
		return;
	}
	////////////////////////////
	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht;
	if (sct.sss[SeatId].UserId != -1) {
		SendError(s, string("����λ�Ѿ�����"));
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
	//�㲥 �û����뷿��
	Head H;
	H.Type = HEAD_ENTERTABLE;
	S_EnterTable EnterTable;
	EnterTable.UserId = UserId;
	snprintf(EnterTable.Name,sizeof(EnterTable.Name),"%s",_spi.Name) ;
	UpdateLineList(UserId, _spi);
	string data = string((char*)&EnterTable, sizeof(S_EnterTable));
	CTEs[TableId].BroadCastPlay(H, data);
	CTEs[TableId].BroadCastVisitors(H, data);
	//�ٹ㲥tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);

	//�����е��û��㲥 ѡ��������Ϣ
	H.Type = HEAD_GETTABLEINFO;
	BroadCastAllLoginUser(H,string((char*)&sti,sizeof(S_TableInfo)));
    Mutex.unlock();

}


//�û�׼�� �޸�CTEs��ֵ  ���غ��ID ���״̬ ��
void UserReady(SOCKET s, int UserId) {
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
		return;
	}
	//��֤�Ϸ�

	int TableId = _spi.NowTableId;

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht; //�޸���Ϸ״̬
	sct.sss[_spi.NowSeatId].Status = GAMESTATUS_READY;
	_spi.GameStatus = GAMESTATUS_READY;
	UpdateLineList(UserId, _spi);
	Head H;
	H.Type = HEAD_SENDREADY;
	S_GameReady sgr;
	sgr.UserId = UserId;
	snprintf(sgr.Name, sizeof(sgr.Name), "%s", _spi.Name);
	//�ֱ�������������˷���
	CTEs[TableId].BroadCastPlay(H, string((char*)&sgr, sizeof(S_GameReady)));
	CTEs[TableId].BroadCastVisitors(H, string((char*)&sgr, sizeof(S_GameReady)));

	//�ٹ㲥tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);
	//�����е��û��㲥 �û�׼����Ϣ
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
		Head H; //����ȷ���췽�ڷ� ���غ��ID ���״̬ ��һ�����巽
		H.Type = HEAD_KAIJU;
		//��һ�����巽
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
	
		//֪ͨ�û����� 
		sct.MoveResult = MOVE_RESULT_NORESULT;
		CTEs[TableId].BroadCastPlay(H, string((char*)&sct, sizeof(sct)));
		CTEs[TableId].BroadCastVisitors(H, string((char*)&sct, sizeof(sct)));
	}
	Mutex.unlock();
}


//���
void SueForPeace(SOCKET s, int UserId, S_SueForPeace sfp) {
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
		return;
	}
	int TableId = _spi.NowTableId;

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &sct = CTEs[TableId].cht; //�޸���Ϸ״̬
	//���͸��Է�
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
	//��֤�Ϸ�
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
		return;
	}


	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht; //�޸���Ϸ״̬
	//�������巽���Լ�
	if (_spi.NowSeatId == _sct.NextSeat) {
		memcpy(_sct.HongChessStatus, sct.HongChessStatus, sizeof(sct.HongChessStatus));
		_sct.MoveResult = sct.MoveResult;
		Head H;
		H.Type = HEAD_MOVECHESS;
		//�ֱ��������ϵ��˷���
		CTEs[TableId].BroadCastPlay(H, string((char*)&_sct, sizeof(sct)));
		CTEs[TableId].BroadCastVisitors(H, string((char*)&_sct, sizeof(sct)));
		//�ж��ǲ�����Ϸ����
		if (_sct.MoveResult == MOVE_RESULT_GAME_HEISHENG || _sct.MoveResult == MOVE_RESULT_GAME_HONGSHENG) {
			Mutex.unlock();
			GameOver(s, UserId, 0x00);
			return;
		}
	}
	else {
		SendError(s, string("����������"));
		Mutex.unlock();
		return;
	}
	_sct.NextSeat = (_sct.NextSeat + 1) % 2;
	Mutex.unlock();
}

//��Ϸ����
void GameOver(SOCKET s,int UserId,int Type) {
	//�ж�˭��Ӯ�� ��˭����� ����table״̬ Ϊ Intable
	//��֤�Ϸ�
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
		return;
	}

	mutex &Mutex = CTEs[TableId].Mutex;
	Mutex.lock();
	S_ChessTable &_sct = CTEs[TableId].cht;
	S_PlayInfo spi1 = FindLineList(_sct.sss[0].UserId);
	S_PlayInfo spi2 = FindLineList(_sct.sss[1].UserId);
	Head H;
	H.Type = HEAD_GAMEOVER;
	//�ֱ��������ϵ��˷���
	S_GameOver sgo;
	switch (Type) {
	case WINTYPE_JUESHA: { //����
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
	case WINTYPE_GIVEUP: { //����
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
	case WINTYPE_TIMEOUT: { //��ʱ
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
	case WINTYPE_OUTLINE: { //����
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
	case WINTYPE_RUNAWAY: { //ǿ���˳�
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
	_sct.MoveResult = MOVE_RESULT_NORESULT; //��ʼ��Ϊ noresult
	_spi.GameStatus = GAMESTATUS_INTABLE;
	UpdateLineList(UserId, _spi);
    Mutex.unlock();
}

void Message(SOCKET s, int UserId, S_Message &sm) {
	S_PlayInfo _spi = FindLineList(UserId);
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
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
		SendError(s, string("�û����ȵ���"));
		return false;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	mutex &Mutex = CTEs[TableId].Mutex;
	if (_spi.id == -1) { // �Ѿ���ʱ
		SendError(s, string("�����µ���"));
		return false;
	}
	else {
		Mutex.lock();
		DeleteBrokenLineList(UserId);
		//Ⱥ���û����µ�����Ϣ
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
		//�������� ���ӵ�ȫ����Ϣ
		H.Type = HEAD_GETCHESSTABLE;
		string dataSend = Serv.GenerateRetMsg(string((char*)&H, sizeof(Head)), string(( char*)&CTEs[TableId].cht,sizeof(S_ChessTable)));
		Serv.Send(s, dataSend);
		Mutex.unlock();
	}
	return true;
}
//��ָ ��Ϸ����뿪
void LeaveTable(SOCKET s, int UserId) {
	if (UserId == -1) {
		SendError(s, string("�û����ȵ���"));
		return;
	}
	S_PlayInfo _spi = FindLineList(UserId);
	int TableId = _spi.NowTableId;
	if (_spi.NowTableId == -1) {
		SendError(s, string("�û�û��ѡ����λ����"));
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
	//�ٹ㲥tableInfo
	S_TableInfo sti;
	sti.TableId = TableId;
	int Id1 = _sct.sss[0].UserId;
	sti.spi[0] = FindLineList(Id1);
	int Id2 = _sct.sss[1].UserId;
	sti.spi[1] = FindLineList(Id2);
	//�����е��û��㲥 �û�׼����Ϣ
	H.Type = HEAD_GETTABLEINFO;
	BroadCastAllLoginUser(H, string((char*)&sti, sizeof(S_TableInfo)));

	Mutex.unlock();
}

//�û�����Ϸ�� ���Ͷ���ָ��
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

//ѭ������CTs 200������

void ServClose() {
	Serv.Destroy();
}

int MaxLineNumber = 200;

atomic_int LoginNumber = 0;

void ServFunction(SOCKET s) {
	if (LoginNumber > MaxLineNumber) {
		//�������� ������������
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


//�û������ ��ˮ��
int GetSeriesNum() {
	static int SerialNumber = 0;
	SerialNumber++;
	return SerialNumber;
}