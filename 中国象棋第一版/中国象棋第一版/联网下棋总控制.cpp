#include "联网下棋.h"
#include "游戏房间.h"
#include "象棋游戏.h"
#include "主界面.h"

using namespace 中国象棋第一版;
using namespace System::Threading;

//下棋总控制 利用这个控制窗体

void OpenMasterControl() {
	Thread ^t = gcnew Thread(gcnew ThreadStart(MasterControl));
	t->Start();
	t->IsBackground = true;
}


//每盘棋的棋谱
vector<map<string, ChessPieceStatus>>chessmanual;

void MasterControl() {
	Thread::Sleep(3000);
	AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
	主界面 ^ 主界面Wnd;
	for each(Form ^fm in Application::OpenForms)
	{
		if (fm->Name == "主界面")
		{
			主界面Wnd = (主界面 ^)fm;
			axWindowsMediaPlayer1 = 主界面Wnd->axWindowsMediaPlayer1;
		}
	}
	游戏房间^ 游戏房间Wnd = 主界面Wnd->游戏房间Wnd;
	登入 ^ 登入Wnd = 主界面Wnd->登入Wnd;
	主界面Wnd->Log("MasterControl 已开启");
	while (1) {
		uint f_l = 0;
		if (!sc.RecvFIRSTBYTES(sc.sc, f_l)) {
			sc.Destroy();
			break;
		}
		uint s_l = 0;
		if (!sc.RecvSECONDBYTES(sc.sc, s_l)) {
			sc.Destroy();
			break;
		}
		string f_s;
		if (!sc.RecvFIRST(sc.sc, f_l, f_s)) {
			sc.Destroy();
			break;
		}
		string s_s;
		if (!sc.RecvSECOND(sc.sc, s_l, s_s)) {
			sc.Destroy();
			break;
		}
		Head H;
		memcpy(&H, f_s.c_str(), sizeof(Head));
		switch (H.Type) {
		case	HEAD_VISITORLOGIN: //游客登入
			memcpy(&g_pi, s_s.c_str(), sizeof(S_PlayInfo));
			主界面Wnd->Log("动作:" + "游客登入");
			主界面Wnd->Log("ID:" + g_pi.id.ToString());
			主界面Wnd->Log("姓名:" + gcnew String(g_pi.Name));
			主界面Wnd->Log("头像:" + gcnew String(g_pi.HeadPictureName));
			break;
		case HEAD_ENTERTABLE: //进入桌子
		{
			S_EnterTable EnterTable;
			memcpy(&EnterTable, s_s.c_str(), sizeof(S_EnterTable));
			if(EnterTable.UserId == g_pi.id)  
				主界面Wnd->Show象棋游戏();
			Thread::Sleep(500);
			Global::象棋游戏Wnd->Log("玩家" + gcnew String(EnterTable.Name) + "进入桌子");
			break;
		}
		case HEAD_GETTABLEINFO: { //群发消息 选中座位 玩家准备
			主界面Wnd->Log("桌子有变动");
			S_TableInfo TableInfo;
			memcpy(&TableInfo, s_s.c_str(), sizeof(S_TableInfo));
			try {
			游戏房间Wnd->UpdateTable(TableInfo);
			if (TableInfo.spi[0].id == g_pi.id) {
				g_pi = TableInfo.spi[0];
			}
			else if (TableInfo.spi[1].id == g_pi.id) {
				g_pi = TableInfo.spi[1];
			}
			主界面Wnd->Log(gcnew String(TableInfo.spi[0].HeadPictureName));
			主界面Wnd->Log(gcnew String(TableInfo.spi[1].HeadPictureName));
				if (Global::象棋游戏Wnd != nullptr) {
					Global::象棋游戏Wnd->UpdateTableInfo(TableInfo);
				}
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_SENDREADY: { //游戏准备
			S_GameReady sgr;
			memcpy(&sgr, s_s.c_str(), s_s.length());
			try {
				if (Global::象棋游戏Wnd != nullptr) {
					Global::象棋游戏Wnd->Log("玩家" + gcnew String(sgr.Name) + "已准备");
				}
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_KAIJU: //开局
		{
			S_ChessTable  sctTemp;
			memcpy(&sctTemp, s_s.c_str(), sizeof(S_ChessTable));
			try {
				Global::象棋游戏Wnd->KaiJu(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_MOVECHESS: {
			S_ChessTable  sctTemp;
			memcpy(&sctTemp, s_s.c_str(), s_s.length());
			try {
				Global::象棋游戏Wnd->MoveChess(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_GAMEOVER: {
			S_GameOver sgo;
			memcpy(&sgo, s_s.c_str(), s_s.length());
			try {
				Global::象棋游戏Wnd->GameOver(sgo);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_LEAVETABLE: { // 用户离开桌子
			S_LeaveTable sl;
			memcpy(&sl, s_s.c_str(), sizeof(S_LeaveTable));
			try {
				Global::象棋游戏Wnd->LeaveTable(sl);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case EVENT_USEROUTLINE: {
			S_UserOutLine suol;
			memcpy(&suol, s_s.c_str(), sizeof(S_UserOutLine)); 
			try {
				Global::象棋游戏Wnd->UserOutLine(suol);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case EVENT_USERREONLINE: {
			S_UserReConnect surc;
			memcpy(&surc, s_s.c_str(), sizeof(S_UserReConnect));
			try {
				Global::象棋游戏Wnd->Log("玩家:" + gcnew String(surc.Name) + "已经连线");
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_GETCHESSTABLE: {
			S_ChessTable  sctTemp;
			memcpy(&sctTemp, s_s.c_str(), s_s.length());
			try {
				cout << sctTemp.HongChessStatus[10].Name << endl;
				cout << sctTemp.HongChessStatus[10].alive << endl;
				cout << sctTemp.HongChessStatus[10].CCP.x << endl;
				cout << sctTemp.HongChessStatus[10].CCP.y << endl;
				Global::象棋游戏Wnd->ReconnectMove(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_SUEFORPEACE: {
			S_SueForPeace  SueForPeace;
			memcpy(&SueForPeace, s_s.c_str(), s_s.length());
			try {
				Global::象棋游戏Wnd->SueForPeace(SueForPeace);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		//case	HEAD_REGISTERLOGIN:
		//	break;
		//case	HEAD_USERREGISTER:
		//	break;
		case	HEAD_ROOMINFO: { //房间信息
			S_TableInfo CTs[10];
			memcpy(CTs, s_s.c_str(), s_s.length());
			游戏房间Wnd->UdateRoomInfo(CTs);
			break;
		}
		case	HEAD_PICTURELIST: //头像列表
			char fileName[50];
			memcpy(fileName, s_s.c_str(), 50);
			fileSql fs;
			fs.Writefile(string(fileName), s_s.substr(50));
			break;
		case	HEAD_USERWATCHTABLE:
			break;
		case HEAD_ERROR: //错误消息
			主界面Wnd->Log("错误:" + gcnew String(s_s.c_str()));
			MessageBox::Show(gcnew String(s_s.c_str()));
			break;
		case HEAD_MESSAGE: //用户发言
		{
			S_Message sm;
			memcpy(&sm, s_s.c_str(), sizeof(S_Message));
			try {
				Global::象棋游戏Wnd->Message(sm);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_NETWORKPACKAGE: {
			S_PackTest PackTest;
			memcpy(&PackTest, s_s.c_str(), sizeof(S_PackTest));
			PackTest.RecvTimeStemp = clock();
			主界面Wnd->Log("网络测试包,网络延迟: " + (PackTest.RecvTimeStemp- PackTest.SendTimeStamp).ToString() + " 毫秒");
			break;
		}
		}
	}
		if (CliOpen(SERVERIP, "20000")) {
			Cli_SendRequest(HEAD_BROKENLINERECONNECTION, string((char*)&g_pi.id, sizeof(int)));
		}
		else {
			Sleep(1000);
		}
		OpenMasterControl();
}