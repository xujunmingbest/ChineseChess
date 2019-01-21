#pragma once
//更具走棋的规则生成棋谱
//以红方 在我方为准


#include "象棋走棋规则.h"
#include <vector>
#include <fstream>
//棋谱保存


#pragma pack(1)
struct ManualHead{
	char NameRed[50];
	char NameBlack[50];
	int RecordNum; //数据条数
	int SaveTime;
};
#pragma pop()

//保存棋谱string filename, ManualHead &H, vector<ChessPieceStatus> &cps
bool _SaveManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &Manual);

//获取棋谱
bool _ReadManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &cps);

//map 和可以存储的 struct的 转化
void ChessStatusToStruct(map<string, ChessPieceStatus> &cpss, ChessPieceStatus cpsout[33]);
void StructToChessStatus(ChessPieceStatus cpsIn[33], map<string, ChessPieceStatus> &cpssOut);

//文字语句转化为 棋谱
map<string, ChessPieceStatus> WordToManual(const map<string, ChessPieceStatus> Begin,string &word);

void replace_all(string&   str, const string&  old_value, const  string&  new_value);



//由开始到结束的棋谱
string ManualToWord(ChessPieceStatus &begin, ChessPieceStatus &end);

//寻找两个不一样的棋谱
bool FindDiffByManual(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual, ChessPieceStatus &Begin, ChessPieceStatus &End);

string GenerateManualWord(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual);
int CharacterToInt(string &in);
string IntToCharacter(int &in);