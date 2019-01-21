#include "�����������.h"

bool CheRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (cps.CCP.x != End.x && cps.CCP.y != End.y) return false;
	if (End.x < 1 || End.x > 9 || End.y < 1 || End.y  >10) return false;
	//�ж�End������ ��û�� �Լ�������
	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;

		if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
			return false; //���Լ������ӣ������Ϲ���
		}
		if (cps.CCP.x == End.x){
			if (CpsTemp.alive && CpsTemp.CCP.x == cps.CCP.x) { //�ڷ�Χ��
				if (CpsTemp.CCP.y > cps.CCP.y && CpsTemp.CCP.y < End.y) {
					return false;
				}
				else if (CpsTemp.CCP.y < cps.CCP.y && CpsTemp.CCP.y > End.y) {
					return false;
				}
			}
		}
		else if (cps.CCP.y == End.y) {
			if (CpsTemp.alive && CpsTemp.CCP.y == cps.CCP.y) { //�ڷ�Χ��
				if (CpsTemp.CCP.x > cps.CCP.x && CpsTemp.CCP.x < End.x) {
					return false;
				}
				else if (CpsTemp.CCP.x < cps.CCP.x && CpsTemp.CCP.x > End.x) {
					return false;
				}
			}
		}
	}
	//�ж�
	return true;
}

bool MaRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	int dx = cps.CCP.x - End.x;
	int dy = cps.CCP.y - End.y;
	if (End.x < 1 || End.x > 9 || End.y < 1 || End.y  >10) return false;

	if (dx*dx + dy*dy == 5) {
		map<string, ChessPieceStatus>::iterator it;
		for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
			string Name = it->first;
			ChessPieceStatus CpsTemp = it->second;
			if (CpsTemp.alive == false) continue;
			if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
				return false; //���Լ������ӣ������Ϲ���
			}
			if (abs(dx) == 1) { //x���1 �Ƿ������
				int JiaoX = cps.CCP.x;
				int JiaoY = (cps.CCP.y + End.y) / 2;
				if (JiaoX == CpsTemp.CCP.x && JiaoY == CpsTemp.CCP.y) {
					return false;
				}
			}
			else if (abs(dy) == 1) {
				int JiaoX = (cps.CCP.x + End.x) / 2;
				int JiaoY = cps.CCP.y;
				if (JiaoX == CpsTemp.CCP.x && JiaoY == CpsTemp.CCP.y) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool PaoRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (End.x < 1 || End.x > 9 || End.y < 1 || End.y  >10) return false;
	if (cps.CCP.x != End.x && cps.CCP.y != End.y) return false;
	int MinX = cps.CCP.x < End.x ? cps.CCP.x : End.x;
	int MaxX = cps.CCP.x > End.x ? cps.CCP.x : End.x;
	int MinY = cps.CCP.y < End.y ? cps.CCP.y : End.y;
	int MaxY = cps.CCP.y > End.y ? cps.CCP.y : End.y;
	bool EndCoordinateIsEnemy = false; //�Է�����

	map<string, ChessPieceStatus>::iterator it;
	int Count = 0;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.alive == false) continue;
		if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
			return false; //���Լ������ӣ������Ϲ���
		}
		else if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color != cps.Color) {
		  //�жԷ�������
			EndCoordinateIsEnemy = true;
		}
		if (cps.CCP.x == End.x && cps.CCP.x == CpsTemp.CCP.x) { //�ж��м�ֻ��һ����
			if (CpsTemp.CCP.y > MinY && CpsTemp.CCP.y < MaxY) Count++;
		}
		else if (cps.CCP.y == End.y && cps.CCP.y == CpsTemp.CCP.y) {
			if (CpsTemp.CCP.x > MinX && CpsTemp.CCP.x < MaxX) Count++;
		}
	}
	if (Count == 1 && EndCoordinateIsEnemy == true) return true;
	else if (Count == 0 && EndCoordinateIsEnemy == false) return true;
	else return false;
}

bool BingRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (End.x < 1 || End.x > 9 || End.y < 1 || End.y  >10) return false;
	if (cps.Color == RED) {
		if (cps.CCP.y <= 5) {
			if (cps.CCP.x == End.x && cps.CCP.y + 1 == End.y) return true;
		}
		else if (cps.CCP.y >= 6) {
			if (cps.CCP.x == End.x && cps.CCP.y + 1 == End.y) return true;
			else if (abs(cps.CCP.x - End.x) == 1 && cps.CCP.y == End.y) return true;
		}
	}
	else if (cps.Color == BLACK) {
		if (cps.CCP.y >= 6) {
			if (cps.CCP.x == End.x && cps.CCP.y - 1 == End.y) return true;
		}
		else if (cps.CCP.y <= 5) {
			if (cps.CCP.x == End.x && cps.CCP.y - 1 == End.y) return true;
			else if (abs(cps.CCP.x - End.x) == 1 && cps.CCP.y == End.y) return true;
		}
	}
	return false;
}

bool ShiRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (cps.Color == RED) {
		if (End.x >= 4 && End.x <= 6 && End.y >= 1 && End.y <= 3);
		else return false;
	}
	else if (cps.Color == BLACK) {
		if (End.x >= 4 && End.x <= 6 && End.y >= 8 && End.y <= 10);
		else return false;
	}

	int dx = cps.CCP.x - End.x;
	int dy = cps.CCP.y - End.y;

	if (dx*dx + dy*dy == 2) {
		map<string, ChessPieceStatus>::iterator it;
		for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
			string Name = it->first;
			ChessPieceStatus CpsTemp = it->second;
			if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
				return false; //���Լ������ӣ������Ϲ���
			}
		}
	}
	return true;
}

bool XiangRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	int dx = cps.CCP.x - End.x;
	int dy = cps.CCP.y - End.y;
	if (dx*dx + dy*dy != 8) return false;
	//�ж���û�г�����Χ
	if (cps.Color == RED) {
		if (End.x >= 1 && End.x <= 9 && End.y >= 1 && End.y <= 5) ;
		else return false;
	}
	else if (cps.Color == BLACK) {
		if (End.x >= 1 && End.x <= 9 && End.y >= 6 && End.y <= 10);
		else return false;
	}


	int KaX = (cps.CCP.x + End.x) / 2;
	int KaY = (cps.CCP.y + End.y) / 2;

	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
			return false; //���Լ������ӣ������Ϲ���
		}
		if (CpsTemp.alive == true && CpsTemp.CCP.x == KaX && CpsTemp.CCP.y == KaY) { //����м��п�λ�Ļ�
			return false;
		}
	}
	return true;
}

bool JiangRule(ChessPieceStatus &cps, ChessCoordinatePosition &End, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	int dx = cps.CCP.x - End.x;
	int dy = cps.CCP.y - End.y;
	if (dx*dx + dy*dy != 1) return false;
	if (cps.Color == RED) {
		if (End.x >= 4 && End.x <= 6 && End.y >= 1 && End.y <= 3);
		else return false;
	}
	else if (cps.Color == BLACK) {
		if (End.x >= 4 && End.x <= 6 && End.y >= 8 && End.y <= 10);
		else return false;
	}
	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.alive == true && CpsTemp.CCP.x == End.x && CpsTemp.CCP.y == End.y && CpsTemp.Color == cps.Color) {
			return false; //���Լ������ӣ������Ϲ���
		}
	}
	//�ж��ǲ��� 
	return true;
}
#include <mutex>
mutex Mutex;
bool InRule(string name,ChessCoordinatePosition End, map<string, ChessPieceStatus> &ChessHongStatus) {
	MoveResult = MOVE_RESULT_MOVEONLY;
	if (ChessHongStatus.count(name) == 0) return false;
	ChessPieceStatus cps = ChessHongStatus[name];
	if (cps.CCP.x == End.x && cps.CCP.y == End.y) return false;
	if (cps.alive == false) return false;
	if (cps.CCP.x == -1) return false;

	Mutex.lock();
	map<string, ChessPieceStatus> HongChessStatusCache = ChessHongStatus;
	bool Effect = false;
	switch (cps.Name) {
	case CHE:
		Effect= CheRule(cps, End, ChessHongStatus);
		break;
	case MA:
		Effect = MaRule(cps, End, ChessHongStatus);
		break;
	case PAO:
		Effect = PaoRule(cps, End, ChessHongStatus);
		break;
	case BING:
		Effect = BingRule(cps, End, ChessHongStatus);
		break;
	case XIANG:
		Effect = XiangRule(cps, End, ChessHongStatus);
		break;
	case SHI:
		Effect = ShiRule(cps, End, ChessHongStatus);
		break;
	case JIANG:
		Effect = JiangRule(cps, End, ChessHongStatus);
		break;
	default:;
	}
	if (Effect == false) {
		Mutex.unlock();
		return false;
	}
	// �����������
	ChessHongStatus["P_None"].CCP = ChessHongStatus[name].CCP;
	//ֱ�Ӱ� ���ӱ��
	ChessHongStatus[name].CCP = End;
	//ָ�븳ֵ����
	InitAllToTransparent(ChessHongStatus);
	ChessHongStatus[name].BC = BC_GRAY;
	if (JudgeChiZi(name, ChessHongStatus)) {
		MoveResult = MOVE_RESULT_CHI;
	}
	//�����Ըı����

	//����֮�����ж� �������Ƿ�����֮��ͻᱻɱ��
	if (JiangFaceToFace(ChessHongStatus)) {
		ChessHongStatus = HongChessStatusCache;
		Mutex.unlock();
		return false;
	}

	//�ж�
	if (cps.Color == RED) {
		if (HeiCanEatHongJiang(ChessHongStatus)) {
			ChessHongStatus = HongChessStatusCache;
			Mutex.unlock();
			return false;
		}
		if (HongCanEatHeiJiang(ChessHongStatus)) {
			MoveResult = MOVE_RESULT_JIANG;
			if (JudgeHongJueShaHei(ChessHongStatus)) {
				MoveResult = MOVE_RESULT_GAME_HONGSHENG;
			}
		}
	}
	else if (cps.Color == BLACK) {
		if (HongCanEatHeiJiang(ChessHongStatus)) {
			ChessHongStatus = HongChessStatusCache;
			Mutex.unlock();
			return false;
		}
		if (HeiCanEatHongJiang(ChessHongStatus)) {
			MoveResult = MOVE_RESULT_JIANG;
			if (JudgeHeiJueShaHong(ChessHongStatus)) {
				MoveResult = MOVE_RESULT_GAME_HEISHENG;
			}
		}
	}
	Mutex.unlock();
	return true;
}

bool InRuleTemp(string name, ChessCoordinatePosition End, map<string, ChessPieceStatus> &ChessHongStatus) {
	if (ChessHongStatus.count(name) == 0) return false;
	ChessPieceStatus cps = ChessHongStatus[name];
	if (cps.CCP.x == End.x && cps.CCP.y == End.y) return false;
	if (cps.alive == false) return false;
	if (cps.CCP.x == -1) return false;

	map<string, ChessPieceStatus> HongChessStatusCache = ChessHongStatus;
	bool Effect = false;
	switch (cps.Name) {
	case CHE:
		Effect = CheRule(cps, End, ChessHongStatus);
		break;
	case MA:
		Effect = MaRule(cps, End, ChessHongStatus);
		break;
	case PAO:
		Effect = PaoRule(cps, End, ChessHongStatus);
		break;
	case BING:
		Effect = BingRule(cps, End, ChessHongStatus);
		break;
	case XIANG:
		Effect = XiangRule(cps, End, ChessHongStatus);
		break;
	case SHI:
		Effect = ShiRule(cps, End, ChessHongStatus);
		break;
	case JIANG:
		Effect = JiangRule(cps, End, ChessHongStatus);
		break;
	default:;
	}
	if (Effect == false) {
		return false;
	}
	// �����������
	//ChessHongStatus["P_None"].CCP = ChessHongStatus[name].CCP;
	//ֱ�Ӱ� ���ӱ��
	ChessHongStatus[name].CCP = End;
	//ָ�븳ֵ����
	//InitAllToTransparent();
	ChessHongStatus[name].BC = BC_GRAY;
	JudgeChiZi(name, ChessHongStatus);
	//�����Ըı����

	//����֮�����ж� �������Ƿ�����֮��ͻᱻɱ��
	if (JiangFaceToFace(ChessHongStatus)) {
		ChessHongStatus = HongChessStatusCache;
		return false;
	}
	//�ж� �Ƿ�����֮��ͻᱻ �Է��Խ�
	if (cps.Color == RED) {
		if (HeiCanEatHongJiang(ChessHongStatus)) {
			return false;
		}
	}
	else if (cps.Color == BLACK) {
		if (HongCanEatHeiJiang(ChessHongStatus)) {
			return false;
		}
	}
	return true;
}


void ReversalChess(map<string, ChessPieceStatus> &cs) {
	map<string, ChessPieceStatus>::iterator it = cs.begin();
	for (; it != cs.end(); it++) {
		string name = it->first;
		ChessPieceStatus cps = it->second;
		if (cps.CCP.x != -1) { //�������ϵ��ӷ�ת
			it->second.CCP.x = 10 - cps.CCP.x;
			it->second.CCP.y = 11 - cps.CCP.y;
		}
	}
}

int MoveResult = MOVE_RESULT_NORESULT;


//HongChessStatusTemp
//������Ч
bool JudgeChiZi(string name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	ChessPieceStatus cps = HongChessStatusTemp[name];

	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus &CpsTemp = it->second;
		if (!CpsTemp.alive) continue;
		if (Name != name) {
			if (cps.CCP.x == CpsTemp.CCP.x && cps.CCP.y == CpsTemp.CCP.y) {
				CpsTemp.alive = false;
				CpsTemp.CCP = { -1,-1 };
				return true;
			}
		}
	}
	return false;
}

void InitAllToTransparent(map<string, ChessPieceStatus> &HongChessStatusTemp){
	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus &CpsTemp = it->second;
			CpsTemp.BC = BC_TRANSPARENT;
	}
}

void JiangJun(string name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (HongChessStatusTemp.count(name) == 0) return;
	ChessPieceStatus cps = HongChessStatusTemp[name];
	bool _Jiang = false;
	if (cps.Color == RED) {
		//�ҳ��ڽ���λ��
		ChessPieceStatus cpsHeiJiang = HongChessStatusTemp["P_HeiJiang"];

		switch (cps.Name) {
		case CHE: {
			_Jiang = CheJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case MA: {
			_Jiang = MaJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case PAO: {
			_Jiang = PaoJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case BING: {
			_Jiang = HongBingJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP);
			break;
		}
		}
	}
	else if (cps.Color == BLACK) {
		ChessPieceStatus cpsHeiJiang = HongChessStatusTemp["P_HongJiang"];

		switch (cps.Name) {
		case CHE: {
			_Jiang = CheJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case MA: {
			_Jiang = MaJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case PAO: {
			_Jiang = PaoJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
			break;
		}
		case BING: {
			_Jiang = HeiBingJiang(HongChessStatusTemp[name].CCP, cpsHeiJiang.CCP);
			break;
		}
		}
	}
	if (_Jiang) MoveResult = MOVE_RESULT_JIANG;
}

bool CheJiang(ChessCoordinatePosition &CheCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (CheCoordinate.x == -1) return false;
	if (CheCoordinate.x == EnemyJiangCoordinate.x) {
		map<string, ChessPieceStatus>::iterator it;
		for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
			string Name = it->first;
			ChessPieceStatus CpsTemp = it->second;
			if (CpsTemp.alive && CpsTemp.CCP.x == CheCoordinate.x) { //�ڷ�Χ��
				if (CpsTemp.CCP.y > CheCoordinate.y && CpsTemp.CCP.y < EnemyJiangCoordinate.y) {
					return false;
				}
				else if (CpsTemp.CCP.y < CheCoordinate.y && CpsTemp.CCP.y > EnemyJiangCoordinate.y) {
					return false;
				}
			}
		}
		return true;
	}
	else if (CheCoordinate.y == EnemyJiangCoordinate.y) {
		map<string, ChessPieceStatus>::iterator it;
		for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
			string Name = it->first;
			ChessPieceStatus CpsTemp = it->second;
			if (CpsTemp.alive && CpsTemp.CCP.y == CheCoordinate.y) { //�ڷ�Χ��
				if (CpsTemp.CCP.x > CheCoordinate.x && CpsTemp.CCP.x < EnemyJiangCoordinate.x) {
					return false;
				}
				else if (CpsTemp.CCP.x < CheCoordinate.x && CpsTemp.CCP.x > EnemyJiangCoordinate.x) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}


bool MaJiang(ChessCoordinatePosition &MaCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (MaCoordinate.x == -1) return false; //��ʾ����������
									  // x�� ƽ�� �� y��ƽ������5 ��������
	int dx = MaCoordinate.x - EnemyJiangCoordinate.x;
	int dy = MaCoordinate.y - EnemyJiangCoordinate.y;
	if (dx*dx + dy*dy == 5) {
		map<string, ChessPieceStatus>::iterator it;
		for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
			string Name = it->first;
			ChessPieceStatus CpsTemp = it->second;
			if (abs(dx) == 1) { //x���1 �Ƿ������
				int JiaoX = MaCoordinate.x;
				int JiaoY = (MaCoordinate.y + EnemyJiangCoordinate.y) / 2;
				if (JiaoX == CpsTemp.CCP.x && JiaoY == CpsTemp.CCP.y) {
					return false;
				}
			}
			else if (abs(dy) == 1) {
				int JiaoX = (MaCoordinate.x + EnemyJiangCoordinate.x) / 2;
				int JiaoY = MaCoordinate.y;
				if (JiaoX == CpsTemp.CCP.x && JiaoY == CpsTemp.CCP.y) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

bool PaoJiang(ChessCoordinatePosition &PaoCoordinate, ChessCoordinatePosition &EnemyJiangCoordinate, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (PaoCoordinate.x != EnemyJiangCoordinate.x && PaoCoordinate.y != EnemyJiangCoordinate.y) return false;
	int MinX = PaoCoordinate.x < EnemyJiangCoordinate.x ? PaoCoordinate.x : EnemyJiangCoordinate.x;
	int MaxX = PaoCoordinate.x > EnemyJiangCoordinate.x ? PaoCoordinate.x : EnemyJiangCoordinate.x;
	int MinY = PaoCoordinate.y < EnemyJiangCoordinate.y ? PaoCoordinate.y : EnemyJiangCoordinate.y;
	int MaxY = PaoCoordinate.y > EnemyJiangCoordinate.y ? PaoCoordinate.y : EnemyJiangCoordinate.y;

	map<string, ChessPieceStatus>::iterator it;
	int Count = 0;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.alive == false) continue;
		if (PaoCoordinate.x == EnemyJiangCoordinate.x && PaoCoordinate.x == CpsTemp.CCP.x) { //�ж��м�ֻ��һ����
			if (CpsTemp.CCP.y > MinY && CpsTemp.CCP.y < MaxY) Count++;
		}
		else if (PaoCoordinate.y == EnemyJiangCoordinate.y && PaoCoordinate.y == CpsTemp.CCP.y) {
			if (CpsTemp.CCP.x > MinX && CpsTemp.CCP.x < MaxX) Count++;
		}
	}
	if (Count == 1) return true;
	return false;
}



bool HongBingJiang(ChessCoordinatePosition &HongBingCoordinate, ChessCoordinatePosition &HeiJiangCoordinate) {
	if (HongBingCoordinate.x == HeiJiangCoordinate.x && HongBingCoordinate.y + 1 == HeiJiangCoordinate.y) return true;
	else if (HongBingCoordinate.y == HeiJiangCoordinate.y && abs(HongBingCoordinate.x - HeiJiangCoordinate.x) == 1) return true;
	return false;
}
bool HeiBingJiang(ChessCoordinatePosition &HeiBingCoordinate, ChessCoordinatePosition &HongJiangCoordinate) {
	if (HeiBingCoordinate.x == HongJiangCoordinate.x && HeiBingCoordinate.y - 1 == HongJiangCoordinate.y) return true;
	else if (HeiBingCoordinate.y == HongJiangCoordinate.y && abs(HeiBingCoordinate.x - HongJiangCoordinate.x) == 1) return true;
	return false;
}

bool JiangFaceToFace(map<string, ChessPieceStatus> &HongChessStatusTemp) {
	ChessCoordinatePosition HongJiangcps = HongChessStatusTemp["P_HongJiang"].CCP;
	ChessCoordinatePosition HeiJiangcps  = HongChessStatusTemp["P_HeiJiang"].CCP;
	if (HongJiangcps.x != HeiJiangcps.x)  return false;
	int JiangX = HongJiangcps.x;

	map<string, ChessPieceStatus>::iterator it;
	int Count = 0;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.alive) {
			if (CpsTemp.CCP.x == JiangX) {
				if (CpsTemp.CCP.y > HongJiangcps.y &&CpsTemp.CCP.y < HeiJiangcps.y) //������֮��
					return false;
			}
		}
	}
	return true;
}

//�췽�ܲ��ܳԵ��ڷ��Ͻ�
bool HongCanEatHeiJiang(map<string, ChessPieceStatus> &HongChessStatusTemp) {
	map<string, ChessPieceStatus>::iterator it;
	bool _Jiang = false;
	ChessPieceStatus cpsHeiJiang = HongChessStatusTemp["P_HeiJiang"];
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.Color == RED) {
			switch (CpsTemp.Name) {
			case CHE: {
				_Jiang = CheJiang(CpsTemp.CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
				break;
			}
			case MA: {
				_Jiang = MaJiang(CpsTemp.CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
				break;
			}
			case PAO: {
				_Jiang = PaoJiang(CpsTemp.CCP, cpsHeiJiang.CCP, HongChessStatusTemp);
				break;
			}
			case BING: {
				_Jiang = HongBingJiang(CpsTemp.CCP, cpsHeiJiang.CCP);
				break;
			}
			}
			if (_Jiang) return true;
		}
	}
	return false;
}


bool HeiCanEatHongJiang(map<string, ChessPieceStatus> &HongChessStatusTemp) {
	map<string, ChessPieceStatus>::iterator it;
	bool _Jiang = false;
	ChessPieceStatus cpsHongJiang = HongChessStatusTemp["P_HongJiang"];
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.Color == BLACK) {
			switch (CpsTemp.Name) {
			case CHE: {
				_Jiang = CheJiang(CpsTemp.CCP, cpsHongJiang.CCP, HongChessStatusTemp);
				break;
			}
			case MA: {
				_Jiang = MaJiang(CpsTemp.CCP, cpsHongJiang.CCP, HongChessStatusTemp);
				break;
			}
			case PAO: {
				_Jiang = PaoJiang(CpsTemp.CCP, cpsHongJiang.CCP, HongChessStatusTemp);
				break;
			}
			case BING: {
				_Jiang = HeiBingJiang(CpsTemp.CCP, cpsHongJiang.CCP);
				break;
			}
			}
			if (_Jiang) return true;
		}
	}
	return false;
}

//�ж��Ƿ��ɱ ����֮���ж�
// �жϾ�ɱ ˼· �췽 ��ɱ�ڷ�, �췽������ ���ڷ����� ���е��߷� ����� ���Ǻ췽�ܳԵ� �ڷ��Ͻ� ����ô �ж�Ϊ��ɱ
bool JudgeHongJueShaHei(map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (MoveResult == MOVE_RESULT_JIANG) {
		//��ȡ�ڷ����е� �����߷�
		vector<map<string, ChessPieceStatus>> AllHeiLegalMove = GetAllMoveByColor(BLACK, HongChessStatusTemp);
		for (int i = 0; i < AllHeiLegalMove.size(); i++) {
			if (!HongCanEatHeiJiang(AllHeiLegalMove[i])) {
				return false;
			}
		}
		if (AllHeiLegalMove.size() == 0) return true;
	}
	return false;
}

bool JudgeHeiJueShaHong(map<string, ChessPieceStatus> &HongChessStatusTemp) {
	if (MoveResult == MOVE_RESULT_JIANG) {
		//��ȡ�ڷ����е� �����߷�
		vector<map<string, ChessPieceStatus>> AllHongLegalMove = GetAllMoveByColor(RED, HongChessStatusTemp);
		for (int i = 0; i < AllHongLegalMove.size(); i++) {
			if (!HeiCanEatHongJiang(AllHongLegalMove[i])) {
				return false;
			}
		}
	}
	return true;
}

vector<map<string, ChessPieceStatus>> GetAllMoveByColor(bool _Color,map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> AllLegalMove;
	vector<map<string, ChessPieceStatus>> temp;
	map<string, ChessPieceStatus>::iterator it;
	for (it = HongChessStatusTemp.begin(); it != HongChessStatusTemp.end(); it++) {
		string Name = it->first;
		ChessPieceStatus CpsTemp = it->second;
		if (CpsTemp.Color == _Color && CpsTemp.alive == true) {
			switch (CpsTemp.Name) {
			case CHE: {
				temp = CheAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			case MA: {
				temp = MaAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			case PAO: {
				temp = PaoAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			case BING: {
				temp = BingAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			case SHI: {
				temp = ShiAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			case XIANG: {
				temp = XiangAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}	
			case JIANG: {
				temp = JiangAllLegalMove(Name, HongChessStatusTemp);
				AllLegalMove.insert(AllLegalMove.end(), temp.begin(), temp.end());
				break;
			}
			}
		
		}
	}
	return AllLegalMove;
}


vector<map<string, ChessPieceStatus>> CheAllLegalMove(string Name ,map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		for (int i = y; i <= 10; i++) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x,i }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
			else break;
		}
		//Y��С
		for (int i = y; i>0; i--) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x,i }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
			else break;
		}
		//x����
		for (int i = x; i <=9; i++) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ i,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
			else break;
		}
		//x��С
		for (int i = x; i > 0; i--) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ i,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
			else break;
		}
	}
	return ret;
}


vector<map<string, ChessPieceStatus>> MaAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {

	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x+2,y+1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y + 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y + 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 2,y + 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 2,y - 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		} 
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y - 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y - 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 2,y - 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}


vector<map<string, ChessPieceStatus>> PaoAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		for (int i = y; i <= 10; i++) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x,i }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		//Y��С
		for (int i = y; i >= 0; i--) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x,i }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		//x����
		for (int i = x; i <= 9; i++) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ i,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		//x��С
		for (int i = x; i >= 0; i--) {
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ i,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}

vector<map<string, ChessPieceStatus>> ShiAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y +1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y + 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y - 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		} 
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y - 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}

vector<map<string, ChessPieceStatus>> XiangAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 2,y + 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 2,y - 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 2,y + 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 2,y - 2 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}

vector<map<string, ChessPieceStatus>> JiangAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x,y + 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x ,y - 1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}

vector<map<string, ChessPieceStatus>> BingAllLegalMove(string Name, map<string, ChessPieceStatus> &HongChessStatusTemp) {
	vector<map<string, ChessPieceStatus>> ret;
	ChessPieceStatus cps = HongChessStatusTemp[Name];
	if (cps.alive) {
		int x = cps.CCP.x;
		int y = cps.CCP.y;
		//���߷�ɢ
		//Y����
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x ,y+1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x ,y-1 }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x - 1,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
		{
			map<string, ChessPieceStatus> _HongChessStatusTemp = HongChessStatusTemp;
			if (InRuleTemp(Name, ChessCoordinatePosition{ x + 1,y }, _HongChessStatusTemp)) {
				ret.push_back(_HongChessStatusTemp);
			}
		}
	}
	return ret;
}
