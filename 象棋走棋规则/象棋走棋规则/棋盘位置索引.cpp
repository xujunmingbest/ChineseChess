#include "ÆåÅÌÎ»ÖÃË÷Òý.h"


ChessCoordinatePosition GetChessPixelLocation(int x, int y) {
	int EFFECTIVERADIUS = ((INTERVALY - 20) / 2)* ((INTERVALY - 20) / 2);

	map<ChessCoordinatePosition, ChessPixelLocation>::iterator it; ChessPosTable;
	for (it = ChessPosTable.begin(); it != ChessPosTable.end(); it++) {
		int dx = it->second.x - x;
		int dy = it->second.y - y;
		int dd = dx*dx + dy*dy;
		if (dd < EFFECTIVERADIUS) return it->first;
	}
	return { -1,-1 };
}


void ChangeChessStatusTransparent(map<string, ChessPieceStatus> &HongChessStatus) {
	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatus.begin(); it != HongChessStatus.end(); it++) {
		it->second.BC = BC_TRANSPARENT;
	}
}



ChessPixelLocation GetChessPixelLocationByCoordinate(ChessCoordinatePosition &ccp) {

	if (ChessPosTable.count(ccp) != 0) {
		return ChessPosTable[ccp];
	}
	else {
		return ChessPixelLocation{ -1,-1 };
	}
}


void InitRedOpening(map<string, ChessPieceStatus> &ChessStatus) {

	ChessPieceStatus cps;
	cps.alive = true;
	cps.BC = BC_TRANSPARENT;

	cps.CCP.x = 1; cps.CCP.y = 10;
	cps.Name = CHE;	cps.Color = BLACK;
	ChessStatus["P_HeiChe1"] = cps;


	cps.CCP.x = 9; cps.CCP.y = 10;
	cps.Name = CHE;	cps.Color = BLACK;
	ChessStatus["P_HeiChe2"] = cps;

	cps.CCP.x = 2; cps.CCP.y = 10;
	cps.Name = MA;	cps.Color = BLACK;
	ChessStatus["P_HeiMa1"] = cps;


	cps.CCP.x = 8; cps.CCP.y = 10;
	cps.Name = MA;	cps.Color = BLACK;
	ChessStatus["P_HeiMa2"] = cps;

	cps.CCP.x = 2; cps.CCP.y = 8;
	cps.Name = PAO;	cps.Color = BLACK;
	ChessStatus["P_HeiPao1"] = cps;

	cps.Name = PAO;	cps.Color = BLACK;
	cps.CCP.x = 8; cps.CCP.y = 8;
	ChessStatus["P_HeiPao2"] = cps;

	cps.Name = SHI;	cps.Color = BLACK;
	cps.CCP.x = 4; cps.CCP.y = 10;
	ChessStatus["P_HeiShi1"] = cps;

	cps.Name = SHI;	cps.Color = BLACK;
	cps.CCP.x = 6; cps.CCP.y = 10;
	ChessStatus["P_HeiShi2"] = cps;

	cps.Name = XIANG;	cps.Color = BLACK;
	cps.CCP.x = 3; cps.CCP.y = 10;
	ChessStatus["P_HeiXiang1"] = cps;

	cps.Name = XIANG;	cps.Color = BLACK;
	cps.CCP.x = 7; cps.CCP.y = 10;
	ChessStatus["P_HeiXiang2"] = cps;

	cps.Name = JIANG;	cps.Color = BLACK;
	cps.CCP.x = 5; cps.CCP.y = 10;
	ChessStatus["P_HeiJiang"] = cps;

	cps.Name = BING;	cps.Color = BLACK;
	cps.CCP.x = 1; cps.CCP.y = 7;
	ChessStatus["P_HeiBing1"] = cps;

	cps.Name = BING;	cps.Color = BLACK;
	cps.CCP.x = 3; cps.CCP.y = 7;
	ChessStatus["P_HeiBing2"] = cps;

	cps.Name = BING;	cps.Color = BLACK;
	cps.CCP.x = 5; cps.CCP.y = 7;
	ChessStatus["P_HeiBing3"] = cps;

	cps.Name = BING;	cps.Color = BLACK;
	cps.CCP.x = 7; cps.CCP.y = 7;
	ChessStatus["P_HeiBing4"] = cps;

	cps.Name = BING;	cps.Color = BLACK;
	cps.CCP.x = 9; cps.CCP.y = 7;
	ChessStatus["P_HeiBing5"] = cps;

	cps.Name = CHE;	cps.Color = RED;
	cps.CCP.x = 1; cps.CCP.y = 1;
	ChessStatus["P_HongChe1"] = cps;

	cps.Name = CHE;	cps.Color = RED;
	cps.CCP.x = 9; cps.CCP.y = 1;
	ChessStatus["P_HongChe2"] = cps;

	cps.Name = MA;	cps.Color = RED;
	cps.CCP.x = 2; cps.CCP.y = 1;
	ChessStatus["P_HongMa1"] = cps;

	cps.Name = MA;	cps.Color = RED;
	cps.CCP.x = 8; cps.CCP.y = 1;
	ChessStatus["P_HongMa2"] = cps;

	cps.Name = PAO;	cps.Color = RED;
	cps.CCP.x = 2; cps.CCP.y = 3;
	ChessStatus["P_HongPao1"] = cps;

	cps.Name = PAO;	cps.Color = RED;
	cps.CCP.x = 8; cps.CCP.y = 3;
	ChessStatus["P_HongPao2"] = cps;

	cps.Name = SHI;	cps.Color = RED;
	cps.CCP.x = 4; cps.CCP.y = 1;
	ChessStatus["P_HongShi1"] = cps;

	cps.Name = SHI;	cps.Color = RED;
	cps.CCP.x = 6; cps.CCP.y = 1;
	ChessStatus["P_HongShi2"] = cps;

	cps.Name = XIANG;	cps.Color = RED;
	cps.CCP.x = 3; cps.CCP.y = 1;
	ChessStatus["P_HongXiang1"] = cps;

	cps.Name = XIANG;	cps.Color = RED;
	cps.CCP.x = 7; cps.CCP.y = 1;
	ChessStatus["P_HongXiang2"] = cps;

	cps.Name = JIANG;	cps.Color = RED;
	cps.CCP.x = 5; cps.CCP.y = 1;
	ChessStatus["P_HongJiang"] = cps;

	cps.Name = BING;	cps.Color = RED;
	cps.CCP.x = 1; cps.CCP.y = 4;
	ChessStatus["P_HongBing1"] = cps;

	cps.Name = BING;	cps.Color = RED;
	cps.CCP.x = 3; cps.CCP.y = 4;
	ChessStatus["P_HongBing2"] = cps;

	cps.Name = BING;	cps.Color = RED;
	cps.CCP.x = 5; cps.CCP.y = 4;
	ChessStatus["P_HongBing3"] = cps;

	cps.Name = BING;	cps.Color = RED;
	cps.CCP.x = 7; cps.CCP.y = 4;
	ChessStatus["P_HongBing4"] = cps;

	cps.Name = BING;	cps.Color = RED;
	cps.CCP.x = 9; cps.CCP.y = 4;
	ChessStatus["P_HongBing5"] = cps;

	cps.alive = false; cps.Name = KONG;
	cps.CCP.x = -1; cps.CCP.y = -1;
	ChessStatus["P_None"] = cps;
}
void InitBlackOpening(map<string, ChessPieceStatus> &ChessStatus) {
	InitRedOpening(ChessStatus);
	ReversalChess(ChessStatus);
	return;
}

