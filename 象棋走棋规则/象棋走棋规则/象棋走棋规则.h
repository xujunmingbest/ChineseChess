#pragma once

#include "棋盘位置索引.h"
#include <vector>
//以红棋在我方为准


#define RETCODEOK 1 //规则成立可以走棋
#define RETCODEABNORMAL -1 //棋局异常 棋子状态错误
#define RETCODERULEFAILED  -2 //走棋不符合规则

//验证棋子是不是正常状态

#define MOVE_RESULT_GAME_HONGSHENG RED
#define MOVE_RESULT_GAME_HEISHENG BLACK
#define MOVE_RESULT_NORESULT 0x03
#define MOVE_RESULT_CHI 0x04
#define MOVE_RESULT_JIANG 0x05
#define MOVE_RESULT_MOVEONLY 0x06 //普通落子
//#define MOVE_RESULT_HONGJIANG 0x07
//#define MOVE_RESULT_HEIJIANG 0x08

//判断绝杀

extern int MoveResult;

#define MODE_SINGER_USER 0x07 //单机模式
#define MODE_NETWORKING 0x08 //联网对弈模式
#define MODE_IRREGULAR 0x09 //无规则模式


#define TURN_RED RED //
#define TURN_BLACK BLACK //


//cps 为选中棋子 原来的位置含有 颜色坐标种类 ，End为选中棋子 后来的位置
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
// 判断吃子
bool JudgeChiZi(string name, map<string, ChessPieceStatus> &HongChessStatusTemp);

bool JiangFaceToFace(map<string, ChessPieceStatus> &HongChessStatusTemp);
//判断红棋 能否吃到黑方老蒋
bool HongCanEatHeiJiang(map<string, ChessPieceStatus> &HongChessStatusTemp);
bool HeiCanEatHongJiang(map<string, ChessPieceStatus> &HongChessStatusTemp);


//各类棋子判断将军
bool CheJiang(ChessCoordinatePosition &CheCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool MaJiang(ChessCoordinatePosition &MaCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool PaoJiang(ChessCoordinatePosition &HongPaoCoordinate, ChessCoordinatePosition &HeiJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp);
bool HongBingJiang(ChessCoordinatePosition &HongBingCoordinate, ChessCoordinatePosition &HeiJiangCoordinate);
bool HeiBingJiang(ChessCoordinatePosition &HeiBingCoordinate, ChessCoordinatePosition &HongJiangCoordinate);

//判断绝杀 思路 红方 绝杀黑方 ,红方将军后 ，黑方遍历 所有的走法 ，结果 还是红方能吃到 黑方老蒋 ，那么 判断为绝杀

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

