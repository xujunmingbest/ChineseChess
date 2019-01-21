#pragma once
#include "E:\\c++\\libsocket\\libsocket\\libsocket.h"
#include "E:\\�й�����\\�й������һ��\\�й������һ��\\��������.h"
#include "���ݴ洢.h"

#include <set>
#include <map>
using namespace std;
#pragma comment(lib,"libsocket.lib")


void ServOpen(int port);

void ServClose();

//��ʼ������
void InitTable();

//���ߴ����߳�
void BrokenLineProcess();
void AddBrokenLineList(int UserId, S_PlayInfo _spi);

//������
void ServFunction(SOCKET s);

//�̱߳���socket���ж�ȡ����
void  HandleSocket(SOCKET s);

void AddLineList(int &Id, S_PlayInfo &spi);
void DeleteLineList(int &Id);
void UpdateLineList(int &Id, S_PlayInfo &spi);
S_PlayInfo FindLineList(int &Id);
map<int, S_PlayInfo> GetLineLists();


//�ο͵��� �� S_PlayInfo���� UserId
int VisitorLogin(SOCKET s);

//���û����󷿼���Ϣ
void SendRoomInfo(SOCKET s);

// ��ȡͼƬ�б�
void SendPicture(SOCKET s);


//�û�ѡ����λ �ȹ㲥ѡ����λ�¼����ٹ㲥��λ��ȫ����Ϣ
void UserSelectSeat(SOCKET s, int UserId, int SeatId,int TableId);


//�㲥���е��û�
void BroadCastAllLoginUser(Head &H, string &Data);

//�û�׼��
void UserReady(SOCKET s, int UserId);
//�û�����
void MoveChess(SOCKET s, int UserId, S_ChessTable &sct);
//��Ϸ���� 
void GameOver(SOCKET s, int UserId, int Type);
//������Ϣ
void Message(SOCKET s, int UserId,S_Message &sm);
//���ʹ���
void SendError(SOCKET s, string &err);
//�뿪����
void LeaveTable(SOCKET s, int UserId);
//��������
bool BreakReconnect(SOCKET s, int UserId);


//���Ͷ���ָ��
void UserOutLine(int UserId);


//����������Ϣ
void GetTableInfo(SOCKET s,int UserId);

//���
void SueForPeace(SOCKET s, int UserId, S_SueForPeace sfp);


//�û������ ��ˮ��

int GetSeriesNum();