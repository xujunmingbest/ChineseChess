#pragma once
#include "E:\\c++\\libsocket\\libsocket\\libsocket.h"
#include "E:\\c++\\libfilesql\\libfilesql\\libfilesql.h"
#pragma comment(lib,"libfilesql.lib")
#pragma comment(lib,"libsocket.lib")
#include <set>
#include "E:\\�й�����\\�����������\\�����������\\�����������.h"
#include <windows.h>
#include <time.h>

#define SERVERIP "47.94.219.135"

#define HEAD_NETWORKPACKAGE 0x01 //������԰�
#define HEAD_SENDREADY 0x02 //�û�׼��
#define HEAD_KAIJU 0x03 //�û�����
#define HEAD_MOVECHESS 0x04 
#define HEAD_GAMEOVER 0x05 //����

#define HEAD_VISITORLOGIN 0x07 //�ο͵���
//#define HEAD_REGISTERLOGIN 0x08  //�û�����
//#define HEAD_USERREGISTER 0x09 //�û�ע��
#define HEAD_ROOMINFO 0x10 //������Ϣ �����ط�����Ϣ ��������ͷ���б�
#define HEAD_PICTURELIST 0x11 //������Ϣ
#define HEAD_USERSELECTSEAT 0x12 //�û�ѡ����λ
#define HEAD_USERWATCHTABLE 0x13  //�û��ۿ�����
#define HEAD_ERROR 0x14  //���ʹ�����
#define HEAD_MESSAGE 0x15  //������Ϣ
#define HEAD_LEAVETABLE 0x16  //�û��뿪����
#define HEAD_GETTABLEINFO 0x17 //����������ϸ��Ϣ
#define HEAD_GETPLAYERINFOBYID 0x18 //����ĳ���˵���ϸ��Ϣ
#define HEAD_ENTERTABLE 0x19//���û�ѡ������֮��Ⱥ�� ˭����������
#define EVENT_USERENTERTABLE 0x1a //�û����뷿��
#define HEAD_BROKENLINERECONNECTION 0x1b //��������
#define EVENT_USEROUTLINE 0x1c //�û�����
#define EVENT_USERREONLINE 0x1d //�û�����������
#define HEAD_GETCHESSTABLE 0x1e //��ȡ���ӵ���Ϣ
#define HEAD_GIVEUP 0x1f //������� ����
#define HEAD_SUEFORPEACE 0x20 //���
#define HEAD_TAKEBACK 0x21 //���


#define GAMESTATUS_NOTLOGIN 0x27 //û�е���
#define GAMESTATUS_LOGIN 0x28  //�Ѿ�����
#define GAMESTATUS_INTABLE 0x29 //�Ѿ�ѡ��һ������
#define GAMESTATUS_OUTLINE 0x30 //�û�����
#define GAMESTATUS_NOTREADY 0x31 //δ׼��
#define GAMESTATUS_READY 0x32 //��׼��
#define GAMESTATUS_GAMEING 0x33 //��Ϸ��
#define GAMESTATUS_WATCHING 0x34 //��ս��
#define GAMESTATUS_LOSE 0x35 //��Ϸʧ��
#define GAMESTATUS_WIN 0x36 //��Ϸʤ��
#define GAMESTATUS_END 0x37 //��Ϸ����


#pragma pack(1)
struct Head {
	int Id;
	int Type;
};


//�������ݽṹ��
struct S_ChessPieceStatus{
	int id; //���ID
	char Name[50]; //�������
	char ChessPieceStatus[33]; //33������
	char Manual[50];
	bool NowMovePlayer; //���巽
};

//��Ҷ��ߵ�ʱ�� ���߱������Ҳ��� Id�� ��table ���ö��߱���ʱ���� ��һ�����ֳ��� 30 ����߱���ɡʱ�������ж� ��Ϸ����
//��ҵ��� �ȿ��� ��Ӧ���������� �ǲ��� �Լ���  ���� Id ���϶���Ҫ�� Ⱥ�� ������ָ�� ��Ϸ����
struct S_PlayInfo {
	SOCKET sock;
	int id; //���ID
	int GameStatus; //��Ϸ״̬
	char Name[50]; //�������
	char HeadPictureName[50]; //ͷ��
	int Total; //������
	int WinCount; //Ӯ������
	int LostCount; //�������
	int FleeTimes; //���ܴ���
	int NowTableId; //��ǰ����
	int NowSeatId; //��ǰ������λ�� 1 ����� 2���ұ�
	int NowSerialNumber; //��ǰ ��Ϸ��ˮ��
	int LineBrokenTime; //����ʱ���
};

//#ifndef SOCKET
//#define SOCKET unsigned int
//#endif
//��������
//
extern int SerialNumber ;

struct S_SeatStatus {
	int UserId;
	int Color;
	int Status;
};


struct S_ChessTable {
	int SerialNumber = 0;  //��Ϸ�� ����ID  ���û� ���ֵ�ʱ����� ��ֵ
	int TableId;
	S_SeatStatus sss[2];  //sss[0] ����ߵ���λ sss[1] ���ұߵ���λ
	int MoveResult; //�ƶ����Ӳ�����Ч��
	int NextSeat ; //��һ�����巽
	ChessPieceStatus HongChessStatus[33];
};

//��Ϸ�������ͷ������ �����Ӻ���
struct S_TableInfo {
	int TableId;
	S_PlayInfo spi[2];//spi[0] ����ߵ���λ spi[1] ���ұߵ���λ
};

extern S_PlayInfo g_pi;



//�¼�ͳһ�ṹ�� ����ҷ�����
struct S_Event {
	int UserId; //�¼������û�
	char Name[50]; //�¼���������
};


//�û�ѡ����λ ����
struct S_SelectSeat {
	int SeatId;
	int TableId;
};



typedef S_Event S_EnterTable;
typedef S_Event S_GameReady;
struct S_LeaveTable {
	bool LeaveType; //true�������뿪���� falseǿ���뿪����
	int UserId; //�¼������û�
	char Name[50]; //�¼���������
};


#define WINTYPE_JUESHA 0x00
#define WINTYPE_TIMEOUT 0x01
#define WINTYPE_OUTLINE 0x02
#define WINTYPE_RUNAWAY 0x03 //����
#define WINTYPE_GIVEUP 0x04  //����
#define WINTYPE_PEACE 0x05  //����
struct S_GameOver {
	char LoseName[50];
	char WinName[50];
	int WinType;  // 0 ���Է�ɱ�� ��1 ��ʱ  2 ���� 
	bool WinFang; //��ʤID
};
typedef S_Event S_UserOutLine;
typedef S_Event S_UserReConnect;
struct S_Message {
	char Name[50];
	char msg[100];
	int ExpressionId; //�����ַ
};

//���
#define PEACESUE 0x01 //�����������
#define PEACEREJECT 0x02 //�ܾ�
#define PEACERAGREE 0x03 //ͬ��
struct S_SueForPeace {
	char Name[50];
	int Type;
};

//����
#define TAKEBACKSUE 0x01    //�������
#define TAKEBACKJECT 0x02   //�ܾ�
#define TAKEBACKAGREE 0x03  //ͬ��
struct S_SueForTakeBack {
	ChessPieceStatus HongChessStatus[33];
	char Name[50];
	int Type;
};


#pragma pop()



bool CliOpen(string Ip,string port);
void CliClose();

class SocketCli : public SynchroShortConnection, public protocolDemo {
public: string GenerateRequest(Head &H, string Param) {
	string s_H((char*)(&H), sizeof(Head));
	string f_l = GenerateFIRSTBYTES(s_H.length());
	string s_l = GenerateSECONDBYTES(Param.length());
	return f_l + s_l + s_H + Param;
}
};

extern SocketCli sc;


extern vector<map<string, ChessPieceStatus>>chessmanual;

//�ο͵��� ��ȡS_PlayInfo
void Cli_SendRequest(int Type,string Param);
void Cli_SendRequest(int Type);

void MasterControl();
void OpenMasterControl();

