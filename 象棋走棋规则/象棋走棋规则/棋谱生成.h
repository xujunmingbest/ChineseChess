#pragma once
//��������Ĺ�����������
//�Ժ췽 ���ҷ�Ϊ׼


#include "�����������.h"
#include <vector>
#include <fstream>
//���ױ���


#pragma pack(1)
struct ManualHead{
	char NameRed[50];
	char NameBlack[50];
	int RecordNum; //��������
	int SaveTime;
};
#pragma pop()

//��������string filename, ManualHead &H, vector<ChessPieceStatus> &cps
bool _SaveManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &Manual);

//��ȡ����
bool _ReadManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &cps);

//map �Ϳ��Դ洢�� struct�� ת��
void ChessStatusToStruct(map<string, ChessPieceStatus> &cpss, ChessPieceStatus cpsout[33]);
void StructToChessStatus(ChessPieceStatus cpsIn[33], map<string, ChessPieceStatus> &cpssOut);

//�������ת��Ϊ ����
map<string, ChessPieceStatus> WordToManual(const map<string, ChessPieceStatus> Begin,string &word);

void replace_all(string&   str, const string&  old_value, const  string&  new_value);



//�ɿ�ʼ������������
string ManualToWord(ChessPieceStatus &begin, ChessPieceStatus &end);

//Ѱ��������һ��������
bool FindDiffByManual(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual, ChessPieceStatus &Begin, ChessPieceStatus &End);

string GenerateManualWord(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual);
int CharacterToInt(string &in);
string IntToCharacter(int &in);