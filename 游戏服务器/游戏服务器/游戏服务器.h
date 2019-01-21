#pragma once
#include "E:\\c++\\libsocket\\libsocket\\libsocket.h"
#include "E:\\中国象棋\\中国象棋第一版\\中国象棋第一版\\联网下棋.h"
#include "数据存储.h"

#include <set>
#include <map>
using namespace std;
#pragma comment(lib,"libsocket.lib")


void ServOpen(int port);

void ServClose();

//初始化桌子
void InitTable();

//断线处理线程
void BrokenLineProcess();
void AddBrokenLineList(int UserId, S_PlayInfo _spi);

//服务函数
void ServFunction(SOCKET s);

//线程遍历socket进行读取数据
void  HandleSocket(SOCKET s);

void AddLineList(int &Id, S_PlayInfo &spi);
void DeleteLineList(int &Id);
void UpdateLineList(int &Id, S_PlayInfo &spi);
S_PlayInfo FindLineList(int &Id);
map<int, S_PlayInfo> GetLineLists();


//游客登入 把 S_PlayInfo填满 UserId
int VisitorLogin(SOCKET s);

//当用户请求房间信息
void SendRoomInfo(SOCKET s);

// 获取图片列表
void SendPicture(SOCKET s);


//用户选择座位 先广播选择座位事件，再广播座位的全部信息
void UserSelectSeat(SOCKET s, int UserId, int SeatId,int TableId);


//广播所有的用户
void BroadCastAllLoginUser(Head &H, string &Data);

//用户准备
void UserReady(SOCKET s, int UserId);
//用户走子
void MoveChess(SOCKET s, int UserId, S_ChessTable &sct);
//游戏结束 
void GameOver(SOCKET s, int UserId, int Type);
//发送消息
void Message(SOCKET s, int UserId,S_Message &sm);
//发送错误
void SendError(SOCKET s, string &err);
//离开房间
void LeaveTable(SOCKET s, int UserId);
//断线重连
bool BreakReconnect(SOCKET s, int UserId);


//发送断线指令
void UserOutLine(int UserId);


//请求桌子信息
void GetTableInfo(SOCKET s,int UserId);

//求和
void SueForPeace(SOCKET s, int UserId, S_SueForPeace sfp);


//用户下棋的 流水号

int GetSeriesNum();