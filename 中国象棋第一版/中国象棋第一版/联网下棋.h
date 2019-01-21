#pragma once
#include "E:\\c++\\libsocket\\libsocket\\libsocket.h"
#include "E:\\c++\\libfilesql\\libfilesql\\libfilesql.h"
#pragma comment(lib,"libfilesql.lib")
#pragma comment(lib,"libsocket.lib")
#include <set>
#include "E:\\中国象棋\\象棋走棋规则\\象棋走棋规则\\象棋走棋规则.h"
#include <windows.h>
#include <time.h>

#define SERVERIP "47.94.219.135"

#define HEAD_NETWORKPACKAGE 0x01 //网络测试包
#define HEAD_SENDREADY 0x02 //用户准备
#define HEAD_KAIJU 0x03 //用户开局
#define HEAD_MOVECHESS 0x04 
#define HEAD_GAMEOVER 0x05 //走子

#define HEAD_VISITORLOGIN 0x07 //游客登入
//#define HEAD_REGISTERLOGIN 0x08  //用户登入
//#define HEAD_USERREGISTER 0x09 //用户注册
#define HEAD_ROOMINFO 0x10 //请求信息 先下载房间信息 ，在下载头像列表
#define HEAD_PICTURELIST 0x11 //请求信息
#define HEAD_USERSELECTSEAT 0x12 //用户选择座位
#define HEAD_USERWATCHTABLE 0x13  //用户观看比赛
#define HEAD_ERROR 0x14  //发送错误码
#define HEAD_MESSAGE 0x15  //发送消息
#define HEAD_LEAVETABLE 0x16  //用户离开桌子
#define HEAD_GETTABLEINFO 0x17 //请求桌子详细信息
#define HEAD_GETPLAYERINFOBYID 0x18 //请求某个人的详细信息
#define HEAD_ENTERTABLE 0x19//在用户选择桌子之后群发 谁进入桌子了
#define EVENT_USERENTERTABLE 0x1a //用户进入房间
#define HEAD_BROKENLINERECONNECTION 0x1b //断线重连
#define EVENT_USEROUTLINE 0x1c //用户断线
#define EVENT_USERREONLINE 0x1d //用户重新连接上
#define HEAD_GETCHESSTABLE 0x1e //获取桌子的信息
#define HEAD_GIVEUP 0x1f //放弃棋局 认输
#define HEAD_SUEFORPEACE 0x20 //求和
#define HEAD_TAKEBACK 0x21 //求和


#define GAMESTATUS_NOTLOGIN 0x27 //没有登入
#define GAMESTATUS_LOGIN 0x28  //已经登入
#define GAMESTATUS_INTABLE 0x29 //已经选择一个桌子
#define GAMESTATUS_OUTLINE 0x30 //用户断线
#define GAMESTATUS_NOTREADY 0x31 //未准备
#define GAMESTATUS_READY 0x32 //已准备
#define GAMESTATUS_GAMEING 0x33 //游戏中
#define GAMESTATUS_WATCHING 0x34 //观战中
#define GAMESTATUS_LOSE 0x35 //游戏失败
#define GAMESTATUS_WIN 0x36 //游戏胜利
#define GAMESTATUS_END 0x37 //游戏结束


#pragma pack(1)
struct Head {
	int Id;
	int Type;
};


//传输数据结构体
struct S_ChessPieceStatus{
	int id; //玩家ID
	char Name[50]; //玩家姓名
	char ChessPieceStatus[33]; //33个棋子
	char Manual[50];
	bool NowMovePlayer; //走棋方
};

//玩家断线的时候 在线表里面找不到 Id的 ，table 设置断线保护时间检测 ，一旦发现超过 30 秒断线保护伞时间立刻判断 游戏结束
//玩家登入 先看看 对应的桌子里面 是不是 自己的  断线 Id 符合断线要求 群发 而结束指令 游戏结束
struct S_PlayInfo {
	SOCKET sock;
	int id; //玩家ID
	int GameStatus; //游戏状态
	char Name[50]; //玩家姓名
	char HeadPictureName[50]; //头像
	int Total; //总盘数
	int WinCount; //赢得盘数
	int LostCount; //输的盘数
	int FleeTimes; //逃跑次数
	int NowTableId; //当前桌子
	int NowSeatId; //当前桌子座位号 1 是左边 2是右边
	int NowSerialNumber; //当前 游戏流水号
	int LineBrokenTime; //断线时间戳
};

//#ifndef SOCKET
//#define SOCKET unsigned int
//#endif
//桌子配置
//
extern int SerialNumber ;

struct S_SeatStatus {
	int UserId;
	int Color;
	int Status;
};


struct S_ChessTable {
	int SerialNumber = 0;  //游戏的 棋盘ID  在用户 开局的时候进行 赋值
	int TableId;
	S_SeatStatus sss[2];  //sss[0] 是左边的座位 sss[1] 是右边的座位
	int MoveResult; //移动棋子产生的效果
	int NextSeat ; //下一个走棋方
	ChessPieceStatus HongChessStatus[33];
};

//游戏房间里的头像名称 和桌子号码
struct S_TableInfo {
	int TableId;
	S_PlayInfo spi[2];//spi[0] 是左边的座位 spi[1] 是右边的座位
};

extern S_PlayInfo g_pi;



//事件统一结构体 在玩家方接收
struct S_Event {
	int UserId; //事件发生用户
	char Name[50]; //事件发生名字
};


//用户选择座位 发送
struct S_SelectSeat {
	int SeatId;
	int TableId;
};



typedef S_Event S_EnterTable;
typedef S_Event S_GameReady;
struct S_LeaveTable {
	bool LeaveType; //true是正常离开房间 false强制离开房间
	int UserId; //事件发生用户
	char Name[50]; //事件发生名字
};


#define WINTYPE_JUESHA 0x00
#define WINTYPE_TIMEOUT 0x01
#define WINTYPE_OUTLINE 0x02
#define WINTYPE_RUNAWAY 0x03 //逃跑
#define WINTYPE_GIVEUP 0x04  //认输
#define WINTYPE_PEACE 0x05  //逃跑
struct S_GameOver {
	char LoseName[50];
	char WinName[50];
	int WinType;  // 0 被对方杀死 ，1 超时  2 断网 
	bool WinFang; //获胜ID
};
typedef S_Event S_UserOutLine;
typedef S_Event S_UserReConnect;
struct S_Message {
	char Name[50];
	char msg[100];
	int ExpressionId; //表情地址
};

//求和
#define PEACESUE 0x01 //请求和棋请求
#define PEACEREJECT 0x02 //拒绝
#define PEACERAGREE 0x03 //同意
struct S_SueForPeace {
	char Name[50];
	int Type;
};

//悔棋
#define TAKEBACKSUE 0x01    //请求悔棋
#define TAKEBACKJECT 0x02   //拒绝
#define TAKEBACKAGREE 0x03  //同意
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

//游客登入 获取S_PlayInfo
void Cli_SendRequest(int Type,string Param);
void Cli_SendRequest(int Type);

void MasterControl();
void OpenMasterControl();

