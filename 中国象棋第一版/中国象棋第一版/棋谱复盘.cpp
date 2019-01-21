#include "棋谱复盘.h"
using namespace 中国象棋第一版;

vector<map<string, ChessPieceStatus>> ReplayData;

void 棋谱复盘::InitP_chessboard() {
	P_HeiChe1->Parent = P_chessboard;
	P_HeiChe2->Parent = P_chessboard;
	P_HeiMa1->Parent = P_chessboard;
	P_HeiMa2->Parent = P_chessboard;
	P_HeiPao1->Parent = P_chessboard;
	P_HeiPao2->Parent = P_chessboard;
	P_HeiShi1->Parent = P_chessboard;
	P_HeiShi2->Parent = P_chessboard;
	P_HeiXiang1->Parent = P_chessboard;
	P_HeiXiang2->Parent = P_chessboard;
	P_HeiJiang->Parent = P_chessboard;
	P_HeiBing1->Parent = P_chessboard;
	P_HeiBing2->Parent = P_chessboard;
	P_HeiBing3->Parent = P_chessboard;
	P_HeiBing4->Parent = P_chessboard;
	P_HeiBing5->Parent = P_chessboard;

	P_HongChe1->Parent = P_chessboard;
	P_HongChe2->Parent = P_chessboard;
	P_HongMa1->Parent = P_chessboard;
	P_HongMa2->Parent = P_chessboard;
	P_HongPao1->Parent = P_chessboard;
	P_HongPao2->Parent = P_chessboard;
	P_HongShi1->Parent = P_chessboard;
	P_HongShi2->Parent = P_chessboard;
	P_HongXiang1->Parent = P_chessboard;
	P_HongXiang2->Parent = P_chessboard;
	P_HongJiang->Parent = P_chessboard;
	P_HongBing1->Parent = P_chessboard;
	P_HongBing2->Parent = P_chessboard;
	P_HongBing3->Parent = P_chessboard;
	P_HongBing4->Parent = P_chessboard;
	P_HongBing5->Parent = P_chessboard;

	P_None->Parent = P_chessboard;
}