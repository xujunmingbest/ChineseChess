#include "棋谱生成.h"

bool _SaveManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &Manual) {
	ofstream of;
	of.open(filename, ios::binary);
	if (!of) return false;
	of.write((char*)&H, sizeof(ManualHead));
	for (int i = 0; i < Manual.size(); i++) {
		ChessPieceStatus cpsTemp[33];
		ChessStatusToStruct(Manual[i], cpsTemp);
		of.write((char*)cpsTemp,sizeof(cpsTemp));
	}
	of.close();
	return true;
}

bool _ReadManual(string filename, ManualHead &H, vector<map<string, ChessPieceStatus>> &Manual) {
	memset(&H, 0x00, sizeof(ManualHead));
	Manual.clear();
	ifstream ifile;
	ifile.open(filename, ios::binary);
	if (!ifile) return false;
	ifile.read((char*)&H,sizeof(ManualHead));
	for(int i=0;i<H.RecordNum;i++){
		ChessPieceStatus cpsTemp[33] ;
		ifile.read((char*)cpsTemp,sizeof(cpsTemp));
		map<string, ChessPieceStatus> Temp;
		StructToChessStatus(cpsTemp, Temp);
		Manual.push_back(Temp);
	}
	ifile.close();
	return true;
}

//由开始到结束的棋谱
string ManualToWord(ChessPieceStatus &begin, ChessPieceStatus &end) {
	//检测是不是合法
	if (begin.alive == false || end.alive == false) return "";
	if (begin.Name != end.Name)  return "";
	if (begin.Color != end.Color) return "";
	int BeginPosx = begin.CCP.x;
	int BeginPosy = begin.CCP.y;
	int EndPosx = end.CCP.x;
	int EndPosy = end.CCP.y;
	string manual;
	if (begin.Color == RED) manual = "红:";
	else if (begin.Color == BLACK) manual = "黑:";
	string Name;

	switch (begin.Name) {
	case CHE:
		Name = "车";
		break;
	case MA:
		Name = "马";
		break;
	case PAO:
		Name = "炮";
		break;
	case SHI:
		Name = "士";
		break;
	case XIANG:
		Name = "象";
		break;
	case BING:
		Name = "兵";
		break;
	case JIANG:
		Name = "将";
		break;
	}
	char buff[20];
	string S_BeginPosx = IntToCharacter(BeginPosx);
	string S_BeginPosy = IntToCharacter(BeginPosy);
	string S_EndPosx = IntToCharacter(EndPosx);
	string S_EndPosy = IntToCharacter(EndPosy);
	manual = manual + Name + S_BeginPosx + S_BeginPosy+"到";
	manual = manual + S_EndPosx + S_EndPosy;

	return manual;
}



void ChessStatusToStruct(map<string, ChessPieceStatus> &cpss, ChessPieceStatus cpsout[33]) {
	cpsout[0] = cpss["P_None"];
	cpsout[1] = cpss["P_HeiChe1"];
	cpsout[2] = cpss["P_HeiChe2"];
	cpsout[3] = cpss["P_HeiMa1"];
	cpsout[4] = cpss["P_HeiMa2"];
	cpsout[5] = cpss["P_HeiPao1"];
	cpsout[6] = cpss["P_HeiPao2"];
	cpsout[7] = cpss["P_HeiShi1"];
	cpsout[8] = cpss["P_HeiShi2"];
	cpsout[9] = cpss["P_HeiXiang1"];
	cpsout[10] = cpss["P_HeiXiang2"];
	cpsout[11] = cpss["P_HeiBing1"];
	cpsout[12] = cpss["P_HeiBing2"];
	cpsout[13] = cpss["P_HeiBing3"];
	cpsout[14] = cpss["P_HeiBing4"];
	cpsout[15] = cpss["P_HeiBing5"];
	cpsout[16] = cpss["P_HeiJiang"];

	cpsout[17] = cpss["P_HongChe1"];
	cpsout[18] = cpss["P_HongChe2"];
	cpsout[19] = cpss["P_HongMa1"];
	cpsout[20] = cpss["P_HongMa2"];
	cpsout[21] = cpss["P_HongPao1"];
	cpsout[22] = cpss["P_HongPao2"];
	cpsout[23] = cpss["P_HongShi1"];
	cpsout[24] = cpss["P_HongShi2"];
	cpsout[25] = cpss["P_HongXiang1"];
	cpsout[26] = cpss["P_HongXiang2"];
	cpsout[27] = cpss["P_HongBing1"];
	cpsout[28] = cpss["P_HongBing2"];
	cpsout[29] = cpss["P_HongBing3"];
	cpsout[30] = cpss["P_HongBing4"];
	cpsout[31] = cpss["P_HongBing5"];
	cpsout[32] = cpss["P_HongJiang"];
}


void StructToChessStatus(ChessPieceStatus cpsIn[33], map<string, ChessPieceStatus> &cpssOut) {
	cpssOut["P_None"] = cpsIn[0];
	cpssOut["P_HeiChe1"] = cpsIn[1];
	cpssOut["P_HeiChe2"] = cpsIn[2];
	cpssOut["P_HeiMa1"] = cpsIn[3];
	cpssOut["P_HeiMa2"] = cpsIn[4];
	cpssOut["P_HeiPao1"] = cpsIn[5];
	cpssOut["P_HeiPao2"] = cpsIn[6];
	cpssOut["P_HeiShi1"] = cpsIn[7];
	cpssOut["P_HeiShi2"] = cpsIn[8];
	cpssOut["P_HeiXiang1"] = cpsIn[9];
	cpssOut["P_HeiXiang2"] = cpsIn[10];
	cpssOut["P_HeiBing1"] = cpsIn[11];
	cpssOut["P_HeiBing2"] = cpsIn[12];
	cpssOut["P_HeiBing3"] = cpsIn[13];
	cpssOut["P_HeiBing4"] = cpsIn[14];
	cpssOut["P_HeiBing5"] = cpsIn[15];
	cpssOut["P_HeiJiang"] = cpsIn[16];

	cpssOut["P_HongChe1"] = cpsIn[17];
	cpssOut["P_HongChe2"] = cpsIn[18];
	cpssOut["P_HongMa1"] = cpsIn[19];
	cpssOut["P_HongMa2"] = cpsIn[20];
	cpssOut["P_HongPao1"] = cpsIn[21];
	cpssOut["P_HongPao2"] = cpsIn[22];
	cpssOut["P_HongShi1"] = cpsIn[23];
	cpssOut["P_HongShi2"] = cpsIn[24];
	cpssOut["P_HongXiang1"] = cpsIn[25];
	cpssOut["P_HongXiang2"] = cpsIn[26];
	cpssOut["P_HongBing1"] = cpsIn[27];
	cpssOut["P_HongBing2"] = cpsIn[28];
	cpssOut["P_HongBing3"] = cpsIn[29];
	cpssOut["P_HongBing4"] = cpsIn[30];
	cpssOut["P_HongBing5"] = cpsIn[31];
	cpssOut["P_HongJiang"] = cpsIn[32];
}

bool FindDiffByManual(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual, ChessPieceStatus &Begin, ChessPieceStatus &End)
{
	map<string, ChessPieceStatus>::iterator it = BeginManual.begin();
	for (; it != BeginManual.end(); it++) {
		string name = it->first;
		ChessPieceStatus cpsBegin = it->second;
		ChessPieceStatus cpsEnd = EndManual[name];
		if (cpsBegin.alive && cpsEnd.alive) {
			if (cpsBegin.CCP.x != cpsEnd.CCP.x || cpsBegin.CCP.y != cpsEnd.CCP.y) {
				Begin = cpsBegin;
				End = cpsEnd;
				return true;
			}
		}
	}
	return false;
}
string GenerateManualWord(map<string, ChessPieceStatus>&BeginManual, map<string, ChessPieceStatus>&EndManual)
{
	ChessPieceStatus Begin;
	ChessPieceStatus End;
	if (FindDiffByManual(BeginManual, EndManual, Begin, End)) {
		return ManualToWord(Begin,End);
	}
	return "";
}
void replace_all(string&   str, const string&  old_value, const  string&  new_value)
{
	while (true) {
		string::size_type   pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
}

int CharacterToInt(string &in) {
	if (in == "十") {
		return 10;
	}
	else if (in == "九") {
		return 9;
	}
	else if (in == "八") {
		return 8;
	}
	else if (in == "七") {
		return 7;
	}
	else if (in == "六") {
		return 6;
	}
	else if (in == "五") {
		return 5;
	}
	else if (in == "四") {
		return 4;
	}
	else if (in == "三") {
		return 3;
	}
	else if (in == "二") {
		return 2;
	}
	else if (in == "一") {
		return 1;
	}
}

string IntToCharacter(int &in) {
	if (in == 10) {
		return "十";
	}
	else if (in == 9) {
		return "九";
	}
	else if (in == 8) {
		return "八";
	}
	else if (in == 7) {
		return "七";
	}
	else if (in == 6) {
		return "六";
	}
	else if (in == 5) {
		return "五";
	}
	else if (in == 4) {
		return "四";
	}
	else if (in == 3) {
		return "三";
	}
	else if (in == 2) {
		return "二";
	}
	else if (in == 1) {
		return "一";
	}
	return "";
}

map<string, ChessPieceStatus> WordToManual( map<string, ChessPieceStatus> Begin, string &word) {
	int BeginX;
	int BeginY;
	int EndX;
	int EndY;
	bool Color;
	int name;

	if (word.find("红") != word.npos) {
		Color = RED;
	}
	else if (word.find("黑") != word.npos) {
		Color = BLACK;
	}
	else {
		return Begin;
	}
	int pos = 0;
	if ( (pos = word.find("车")) != word.npos) {
		name = CHE;
	}
	else if ((pos = word.find("马")) != word.npos) {
		name = MA;
	}
	else if ((pos = word.find("炮")) != word.npos) {
		name = PAO;
	}
	else if ((pos = word.find("象")) != word.npos){
		name = XIANG;
	}
	else if ( (pos = word.find("相")) != word.npos) {
		name = XIANG;
	}
	else if ((pos = word.find("士")) != word.npos ) {
		name = SHI;
	}
	else if ((pos = word.find("仕")) != word.npos) {
		name = SHI;
	}
	else if ((pos = word.find("帅")) != word.npos) {
		name = JIANG;
	}
	else if ((pos = word.find("将")) != word.npos) {
		name = JIANG;
	}
	else if ((pos = word.find("兵")) != word.npos) {
		name = BING;
	}
	else {
		return Begin;
	}
	if (pos + 2 + 10 > word.length()) return Begin;
	string s_temp;
	s_temp = word.substr(pos + 2,2);
	BeginX = CharacterToInt(s_temp);
	s_temp = word.substr(pos + 2+2, 2);
	BeginY = CharacterToInt(s_temp);
	s_temp = word.substr(pos + 2 + 6, 2);
	EndX = CharacterToInt(s_temp);
	s_temp = word.substr(pos + 2 + 8, 2);
	EndY = CharacterToInt(s_temp);
	map<string, ChessPieceStatus> ::iterator it = Begin.begin();
	for (; it != Begin.end(); it++) {
		string NameTemp = it->first;
		ChessPieceStatus cps = it->second;
		if (Color != cps.Color) continue;
		if(cps.alive == false) continue;
		if (cps.CCP.x == BeginX && cps.CCP.y == BeginY) {
			InRule(NameTemp, ChessCoordinatePosition{ EndX ,EndY }, Begin);
			return Begin;
		}
	}
	return Begin;
}