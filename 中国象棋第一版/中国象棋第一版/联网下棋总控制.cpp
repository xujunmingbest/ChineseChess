#include "��������.h"
#include "��Ϸ����.h"
#include "������Ϸ.h"
#include "������.h"

using namespace �й������һ��;
using namespace System::Threading;

//�����ܿ��� ����������ƴ���

void OpenMasterControl() {
	Thread ^t = gcnew Thread(gcnew ThreadStart(MasterControl));
	t->Start();
	t->IsBackground = true;
}


//ÿ���������
vector<map<string, ChessPieceStatus>>chessmanual;

void MasterControl() {
	Thread::Sleep(3000);
	AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
	������ ^ ������Wnd;
	for each(Form ^fm in Application::OpenForms)
	{
		if (fm->Name == "������")
		{
			������Wnd = (������ ^)fm;
			axWindowsMediaPlayer1 = ������Wnd->axWindowsMediaPlayer1;
		}
	}
	��Ϸ����^ ��Ϸ����Wnd = ������Wnd->��Ϸ����Wnd;
	���� ^ ����Wnd = ������Wnd->����Wnd;
	������Wnd->Log("MasterControl �ѿ���");
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
		case	HEAD_VISITORLOGIN: //�ο͵���
			memcpy(&g_pi, s_s.c_str(), sizeof(S_PlayInfo));
			������Wnd->Log("����:" + "�ο͵���");
			������Wnd->Log("ID:" + g_pi.id.ToString());
			������Wnd->Log("����:" + gcnew String(g_pi.Name));
			������Wnd->Log("ͷ��:" + gcnew String(g_pi.HeadPictureName));
			break;
		case HEAD_ENTERTABLE: //��������
		{
			S_EnterTable EnterTable;
			memcpy(&EnterTable, s_s.c_str(), sizeof(S_EnterTable));
			if(EnterTable.UserId == g_pi.id)  
				������Wnd->Show������Ϸ();
			Thread::Sleep(500);
			Global::������ϷWnd->Log("���" + gcnew String(EnterTable.Name) + "��������");
			break;
		}
		case HEAD_GETTABLEINFO: { //Ⱥ����Ϣ ѡ����λ ���׼��
			������Wnd->Log("�����б䶯");
			S_TableInfo TableInfo;
			memcpy(&TableInfo, s_s.c_str(), sizeof(S_TableInfo));
			try {
			��Ϸ����Wnd->UpdateTable(TableInfo);
			if (TableInfo.spi[0].id == g_pi.id) {
				g_pi = TableInfo.spi[0];
			}
			else if (TableInfo.spi[1].id == g_pi.id) {
				g_pi = TableInfo.spi[1];
			}
			������Wnd->Log(gcnew String(TableInfo.spi[0].HeadPictureName));
			������Wnd->Log(gcnew String(TableInfo.spi[1].HeadPictureName));
				if (Global::������ϷWnd != nullptr) {
					Global::������ϷWnd->UpdateTableInfo(TableInfo);
				}
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_SENDREADY: { //��Ϸ׼��
			S_GameReady sgr;
			memcpy(&sgr, s_s.c_str(), s_s.length());
			try {
				if (Global::������ϷWnd != nullptr) {
					Global::������ϷWnd->Log("���" + gcnew String(sgr.Name) + "��׼��");
				}
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_KAIJU: //����
		{
			S_ChessTable  sctTemp;
			memcpy(&sctTemp, s_s.c_str(), sizeof(S_ChessTable));
			try {
				Global::������ϷWnd->KaiJu(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_MOVECHESS: {
			S_ChessTable  sctTemp;
			memcpy(&sctTemp, s_s.c_str(), s_s.length());
			try {
				Global::������ϷWnd->MoveChess(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case	HEAD_GAMEOVER: {
			S_GameOver sgo;
			memcpy(&sgo, s_s.c_str(), s_s.length());
			try {
				Global::������ϷWnd->GameOver(sgo);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_LEAVETABLE: { // �û��뿪����
			S_LeaveTable sl;
			memcpy(&sl, s_s.c_str(), sizeof(S_LeaveTable));
			try {
				Global::������ϷWnd->LeaveTable(sl);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case EVENT_USEROUTLINE: {
			S_UserOutLine suol;
			memcpy(&suol, s_s.c_str(), sizeof(S_UserOutLine)); 
			try {
				Global::������ϷWnd->UserOutLine(suol);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case EVENT_USERREONLINE: {
			S_UserReConnect surc;
			memcpy(&surc, s_s.c_str(), sizeof(S_UserReConnect));
			try {
				Global::������ϷWnd->Log("���:" + gcnew String(surc.Name) + "�Ѿ�����");
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
				Global::������ϷWnd->ReconnectMove(sctTemp);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_SUEFORPEACE: {
			S_SueForPeace  SueForPeace;
			memcpy(&SueForPeace, s_s.c_str(), s_s.length());
			try {
				Global::������ϷWnd->SueForPeace(SueForPeace);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		//case	HEAD_REGISTERLOGIN:
		//	break;
		//case	HEAD_USERREGISTER:
		//	break;
		case	HEAD_ROOMINFO: { //������Ϣ
			S_TableInfo CTs[10];
			memcpy(CTs, s_s.c_str(), s_s.length());
			��Ϸ����Wnd->UdateRoomInfo(CTs);
			break;
		}
		case	HEAD_PICTURELIST: //ͷ���б�
			char fileName[50];
			memcpy(fileName, s_s.c_str(), 50);
			fileSql fs;
			fs.Writefile(string(fileName), s_s.substr(50));
			break;
		case	HEAD_USERWATCHTABLE:
			break;
		case HEAD_ERROR: //������Ϣ
			������Wnd->Log("����:" + gcnew String(s_s.c_str()));
			MessageBox::Show(gcnew String(s_s.c_str()));
			break;
		case HEAD_MESSAGE: //�û�����
		{
			S_Message sm;
			memcpy(&sm, s_s.c_str(), sizeof(S_Message));
			try {
				Global::������ϷWnd->Message(sm);
			}
			catch (System::Exception ^ e) {}
			break;
		}
		case HEAD_NETWORKPACKAGE: {
			S_PackTest PackTest;
			memcpy(&PackTest, s_s.c_str(), sizeof(S_PackTest));
			PackTest.RecvTimeStemp = clock();
			������Wnd->Log("������԰�,�����ӳ�: " + (PackTest.RecvTimeStemp- PackTest.SendTimeStamp).ToString() + " ����");
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