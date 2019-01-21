#pragma once

#include "����λ������.h"
#include <vector>
//�Ժ������ҷ�Ϊ׼


#define RETCODEOK 1 //���������������
#define RETCODEABNORMAL -1 //����쳣 ����״̬����
#define RETCODERULEFAILED  -2 //���岻���Ϲ���

//��֤�����ǲ�������״̬

#define MOVE_RESULT_GAME_HONGSHENG RED
#define MOVE_RESULT_GAME_HEISHENG BLACK
#define MOVE_RESULT_NORESULT 0x03
#define MOVE_RESULT_CHI 0x04
#define MOVE_RESULT_JIANG 0x05
#define MOVE_RESULT_MOVEONLY 0x06 //��ͨ����
//#define MOVE_RESULT_HONGJIANG 0x07
//#define MOVE_RESULT_HEIJIANG 0x08

//�жϾ�ɱ

extern int MoveResult;

#define MODE_SINGER_USER 0x07 //����ģʽ
#define MODE_NETWORKING 0x08 //��������ģʽ
#define MODE_IRREGULAR 0x09 //�޹���ģʽ


#define TURN_RED RED //
#define TURN_BLACK BLACK //


//cps Ϊѡ������ ԭ����λ�ú��� ��ɫ�������� ��EndΪѡ������ ������λ��
bool CheRule(ChessPieceStatus &cps, ChessCoordinatePosition &End,map<string, ChessPieceStatus> &HongChessStatusTemp);
bool MaRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool PaoRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool BingRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool ShiRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool XiangRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool JiangRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp);


void InitAllToTransparent(map<string, ChessPieceStatus> &HongChessStatusTemp);

bool InRuleTemp(string name, ChessCoordinatePosition End, map<string, ChessPieceStatus> &ChessHongStatus);

//
bool InRule(string name, ChessCoordinatePosition End,map<string, ChessPieceStatus> &ChessHongStatus);
// �жϳ���
bool JudgeChiZi(string name, map<string, ChessPieceStatus> &HongChessStatusTemp);

bool JiangFaceToFace(map<string, ChessPieceStatus> &HongChessStatusTemp);
//�жϺ��� �ܷ�Ե��ڷ��Ͻ�
bool HongCanEatHeiJiang(map<string, ChessPieceStatus> &HongChessStatusTemp);
bool HeiCanEatHongJiang(map<string, ChessPieceStatus> &HongChessStatusTemp);


//���������жϽ���
bool CheJiang(ChessCoordinatePosition &CheCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool MaJiang(ChessCoordinatePosition &MaCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool PaoJiang(ChessCoordinatePosition &HongPaoCoordinate, ChessCoordinatePosition &HeiJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool HongBingJiang(ChessCoordinatePosition &HongBingCoordinate, ChessCoordinatePosition &HeiJiangCoordinate);
bool HeiBingJiang(ChessCoordinatePosition &HeiBingCoordinate, ChessCoordinatePosition &HongJiangCoordinate);

//�жϾ�ɱ ˼· �췽 ��ɱ�ڷ� ,�췽������ ���ڷ����� ���е��߷� ����� ���Ǻ췽�ܳԵ� �ڷ��Ͻ� ����ô �ж�Ϊ��ɱ

bool JudgeHongJueShaHei(map<string, ChessPieceStatus> &HongChessStatusTemp);
bool JudgeHeiJueShaHong(map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> GetAllMoveByColor(bool _Color, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> GetAllMoveByColor(bool _Color, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> CheAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> MaAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> PaoAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> ShiAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> XiangAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> JiangAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);
vector<map<string, ChessPieceStatus>> BingAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp);

