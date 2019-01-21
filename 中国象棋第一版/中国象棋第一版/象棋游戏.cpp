#include "象棋游戏.h"
using namespace 中国象棋第一版;

#include "E:\\中国象棋\\象棋走棋规则\\象棋走棋规则\\象棋走棋规则.h"
#pragma comment(lib,"E:\\中国象棋\\象棋走棋规则\\Release\\象棋走棋规则.lib") 

map<string, ChessPieceStatus> ChessStatus;

bool OurColor = RED;
int NextSeat ;

void HideAllChessPieces() {
	map<string, ChessPieceStatus>::iterator it;
	for (it = ChessStatus.begin(); it != ChessStatus.end(); it++) {
		it->second.CCP = { -1,-1 };
	}
}



void LoadHeadPic(PictureBox^ p,String^ path) {
	if (path->Length == 0) {
		p->ImageLocation = "UserData\\HeadPic\\空用户.png";
		return;
	}
	if (File::Exists(path)) {
		p->ImageLocation = path;
	}else{
		p->ImageLocation = "UserData\\HeadPic\\空用户.png";
	}
}



void 象棋游戏::ShowChessByStatus() {
	map<string, ChessPieceStatus>::iterator it;

	for (it = ChessStatus.begin(); it != ChessStatus.end(); it++) {
		string name = it->first;
		ChessPieceStatus cps = it->second;
		Control ^control = P_chessboard->Controls->Find(gcnew String(name.c_str()), true)[0];
		PictureBox^ pb = (PictureBox^)control;
		ChessPixelLocation cpl = GetChessPixelLocationByCoordinate(ChessCoordinatePosition{ cps.CCP.x,cps.CCP.y });
		pb->Location = Point(cpl.x,cpl.y);
		switch (cps.BC) {
		case BC_TRANSPARENT:
			pb->BackColor = Color::Transparent;
			break;
		case BC_GRAY:
			pb->BackColor = Color::Gray;
			break;
		}
	}
}

void 象棋游戏::InitP_chessboard() {
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
	InitBlackOpening(ChessStatus);
}

PictureBox^ 象棋游戏::GetOurChoosePiece() {
	if (OurColor == RED) {
		if (P_HongChe1->BackColor == Color::Gray)return P_HongChe1;
		if (P_HongChe2->BackColor == Color::Gray)return P_HongChe2;
		if (P_HongMa1->BackColor == Color::Gray)return P_HongMa1;
		if (P_HongMa2->BackColor == Color::Gray)return P_HongMa2;
		if (P_HongPao1->BackColor == Color::Gray)return P_HongPao1;
		if (P_HongPao2->BackColor == Color::Gray)return P_HongPao2;
		if (P_HongShi1->BackColor == Color::Gray)return P_HongShi1;
		if (P_HongShi2->BackColor == Color::Gray)return P_HongShi2;
		if (P_HongXiang1->BackColor == Color::Gray)return P_HongXiang1;
		if (P_HongXiang2->BackColor == Color::Gray)return P_HongXiang2;
		if (P_HongJiang->BackColor == Color::Gray)return P_HongJiang;
		if (P_HongBing1->BackColor == Color::Gray)return P_HongBing1;
		if (P_HongBing2->BackColor == Color::Gray)return P_HongBing2;
		if (P_HongBing3->BackColor == Color::Gray)return P_HongBing3;
		if (P_HongBing4->BackColor == Color::Gray)return P_HongBing4;
		if (P_HongBing5->BackColor == Color::Gray)return P_HongBing5;
	}
	else {
		if (P_HeiChe1->BackColor == Color::Gray)return P_HeiChe1;
		if (P_HeiChe2->BackColor == Color::Gray)return P_HeiChe2;
		if (P_HeiMa1->BackColor == Color::Gray)return P_HeiMa1;
		if (P_HeiMa2->BackColor == Color::Gray)return P_HeiMa2;
		if (P_HeiPao1->BackColor == Color::Gray)return P_HeiPao1;
		if (P_HeiPao2->BackColor == Color::Gray)return P_HeiPao2;
		if (P_HeiShi1->BackColor == Color::Gray)return P_HeiShi1;
		if (P_HeiShi2->BackColor == Color::Gray)return P_HeiShi2;
		if (P_HeiXiang1->BackColor == Color::Gray)return P_HeiXiang1;
		if (P_HeiXiang2->BackColor == Color::Gray)return P_HeiXiang2;
		if (P_HeiJiang->BackColor == Color::Gray)return P_HeiJiang;
		if (P_HeiBing1->BackColor == Color::Gray)return P_HeiBing1;
		if (P_HeiBing2->BackColor == Color::Gray)return P_HeiBing2;
		if (P_HeiBing3->BackColor == Color::Gray)return P_HeiBing3;
		if (P_HeiBing4->BackColor == Color::Gray)return P_HeiBing4;
		if (P_HeiBing5->BackColor == Color::Gray)return P_HeiBing5;
	}
	return nullptr;
}

void 象棋游戏::ClickChangeColor(PictureBox ^ pb) {
	if (pb->BackColor == Color::Gray) {
		AllOurChesePieceTransparent();
	}
	else {
		AllOurChesePieceTransparent();
		pb->BackColor = Color::Gray;
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\捡棋.mp3";
	}
}

void 象棋游戏::AllOurChesePieceTransparent() {
	if (OurColor == BLACK) {
		P_HeiChe1->BackColor = Color::Transparent;
		P_HeiChe2->BackColor = Color::Transparent;
		P_HeiMa1->BackColor = Color::Transparent;
		P_HeiMa2->BackColor = Color::Transparent;
		P_HeiPao1->BackColor = Color::Transparent;
		P_HeiPao2->BackColor = Color::Transparent;
		P_HeiShi1->BackColor = Color::Transparent;
		P_HeiShi2->BackColor = Color::Transparent;
		P_HeiXiang1->BackColor = Color::Transparent;
		P_HeiXiang2->BackColor = Color::Transparent;
		P_HeiJiang->BackColor = Color::Transparent;
		P_HeiBing1->BackColor = Color::Transparent;
		P_HeiBing2->BackColor = Color::Transparent;
		P_HeiBing3->BackColor = Color::Transparent;
		P_HeiBing4->BackColor = Color::Transparent;
		P_HeiBing5->BackColor = Color::Transparent;
	}
	else {
		P_HongChe1->BackColor = Color::Transparent;
		P_HongChe2->BackColor = Color::Transparent;
		P_HongMa1->BackColor = Color::Transparent;
		P_HongMa2->BackColor = Color::Transparent;
		P_HongPao1->BackColor = Color::Transparent;
		P_HongPao2->BackColor = Color::Transparent;
		P_HongShi1->BackColor = Color::Transparent;
		P_HongShi2->BackColor = Color::Transparent;
		P_HongXiang1->BackColor = Color::Transparent;
		P_HongXiang2->BackColor = Color::Transparent;
		P_HongJiang->BackColor = Color::Transparent;
		P_HongBing1->BackColor = Color::Transparent;
		P_HongBing2->BackColor = Color::Transparent;
		P_HongBing3->BackColor = Color::Transparent;
		P_HongBing4->BackColor = Color::Transparent;
		P_HongBing5->BackColor = Color::Transparent;
	}
}

bool 象棋游戏::GetChessPieceColor(PictureBox ^pb) {
	String ^Name = pb->Name;
	if (Name->Contains("P_Hei")) return BLACK;
	else if (Name->Contains("P_Hong")) return RED;
}

void 象棋游戏::PlaySoundEffect() {

	if (MoveResult == MOVE_RESULT_NORESULT) {
	
	}
	else if (MoveResult == MOVE_RESULT_MOVEONLY) {
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\落子.wav";
	}
	else if (MoveResult == OurColor) {
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\鼓掌.mp3";
	}
	else if (MoveResult == MOVE_RESULT_JIANG) {
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\将.m4a";
	}
	else if (MoveResult == MOVE_RESULT_CHI) {
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\吃.m4a";
	}
	else {
		axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\失败.mp3";
	}
	
	MoveResult = MOVE_RESULT_NORESULT;
	Thread::Sleep(100);
}

void 象棋游戏::PieceClickEvent(PictureBox ^pb) {
	if (NextSeat != g_pi.NowSeatId) return;
	PictureBox ^OurChoosePiece =  GetOurChoosePiece();
	bool ClickColor = GetChessPieceColor(pb);
	if (ClickColor == OurColor) {
		ClickChangeColor(pb);
		return;
	}
	//发现不是我们的颜色
	if (OurChoosePiece == nullptr) return;

	map<string, ChessPieceStatus> HongChessStatus = ChessStatus;
	if (OurColor == BLACK) ReversalChess(HongChessStatus);
	string ChooseName = T_to_string(OurChoosePiece->Name);
	string ClickName = T_to_string(pb->Name);
	if (InRule(ChooseName, HongChessStatus[ClickName].CCP, HongChessStatus)) {
		S_ChessTable sct;
		sct.MoveResult = MoveResult;
		ChessStatusToStruct(HongChessStatus, sct.HongChessStatus);
		Cli_SendRequest(HEAD_MOVECHESS, string((char*)& sct, sizeof(S_ChessTable)));
	}
}

string T_to_string(String^in)
{
	int len = in->Length * 2;
	char *buff = new char[len + 1];
	memset(buff, 0x00, len + 1);
	snprintf(buff, len + 1, "%s", in);
	string temp = buff;
	delete[] buff;
	return temp;
}


void 象棋游戏::KaiJu(S_ChessTable &sctTemp) {
	int MySeat = g_pi.NowSeatId;
	if (sctTemp.sss[MySeat].UserId != g_pi.id) {
		MessageBox::Show("棋局异常");
	}
	P_chessboard->Enabled = true;
	buttonGiveUp->Enabled = true;
	button4->Enabled = false;
	MyName = OurName->Text;
	EenmyName = EnemyName->Text;
	listBoxMenu->Items->Clear();
	if (sctTemp.sss[MySeat].Color == RED) {
		OurColor = RED;
		InitRedOpening(ChessStatus);
		ShowChessByStatus();
	}
	else  {
		OurColor = BLACK;
		InitBlackOpening(ChessStatus);
		ShowChessByStatus();
	}
	Log("游戏开始");
	axWindowsMediaPlayer1->URL = "E:\\中国象棋\\res\\音效\\游戏开始.wav";
	NextSeat = sctTemp.NextSeat;
	chessmanual.clear();
	map<string, ChessPieceStatus> cpssTemp;
	InitRedOpening(cpssTemp);
	chessmanual.push_back(cpssTemp);
	_TotalStart();
	if (NextSeat == MySeat) {
		_OurStepStart();
	}
	else {
		_EnemyStepStart();
	}
}

void 象棋游戏::GameOver(S_GameOver &sgo) {
	if (sgo.WinType == 0x00) {
		Log(gcnew String(sgo.WinName) + "绝杀了" + gcnew String(sgo.LoseName));
	}
	else if (sgo.WinType == 0x01) {
		Log(gcnew String(sgo.LoseName) + "超时");
	}
	else if (sgo.WinType == 0x02) {
		Log(gcnew String(sgo.LoseName) + "断网");
	}
	else if (sgo.WinType == 0x03) {
		Log(gcnew String(sgo.LoseName) + "逃跑");
	}
	else if (sgo.WinType == 0x04) {
		Log(gcnew String(sgo.LoseName) + "认输");
	}
	else if (sgo.WinType == 0x05) {
		Log("双方协商和棋，本次游戏结束");
	}
	P_chessboard->Enabled = false;
	button4->Enabled = true;
	if (sgo.WinType == 0x05) {
	
	}
	else if (sgo.WinFang == MOVE_RESULT_GAME_HEISHENG) {
		Log("本局游戏结束,黑方胜");
	}
	else if(sgo.WinFang == MOVE_RESULT_GAME_HONGSHENG){
		Log("本局游戏结束,红方胜");
	}
	else {
	
	}
	
	_EnemyStepAbort();
	_OurStepAbort();
	_TotalAbort();
	OurReady->Text = "准备";
	EnemyReady->Text = "准备";
}

void 象棋游戏::SaveClose() {
	_EnemyStepAbort();
	_OurStepAbort();
	_TotalAbort();
}
void 象棋游戏::StepAllClose() {
	_EnemyStepAbort();
	_OurStepAbort();
}

void 象棋游戏::LeaveTable(S_LeaveTable &slt) {
	String ^name = gcnew String(slt.Name);
	if (slt.LeaveType == true) {
		userLog->LogOutput(name + "离开了房间");
	}
	else {
		userLog->LogOutput(name + "强退,扣分");
	}
	OurReady->Text = "准备";
	EnemyReady->Text = "准备";
	SaveClose();
}

void 象棋游戏::UserOutLine(S_UserOutLine &suol) {
	String ^ Name = gcnew String(suol.Name);

	userLog->LogOutput("玩家:" + gcnew String(suol.Name) + "断线");
	if (EnemyName->Text == Name) {
	   //显示断线保护时间

	}
}

void 象棋游戏::SueForPeace(S_SueForPeace &sfp) {
	if (sfp.Type == PEACESUE) {
		::DialogResult d = MessageBox::Show("同意对方和棋请求吗", "提示", MessageBoxButtons::YesNo);
		if (d == ::DialogResult::Yes) {
			sfp.Type = PEACERAGREE;
			Cli_SendRequest(HEAD_SUEFORPEACE, string((char*)&sfp, sizeof(S_SueForPeace)));
		}
		else {
			sfp.Type = PEACEREJECT;
			Cli_SendRequest(HEAD_SUEFORPEACE, string((char*)&sfp, sizeof(S_SueForPeace)));
		}
	}
	else if(sfp.Type == PEACERAGREE){
		MessageBox::Show("对方同意和棋");
		Log("对方同意和棋");
	}
	else if (sfp.Type == PEACEREJECT) {
		MessageBox::Show("对方不同意和棋");
		Log("对方不同意和棋");
	}
}

void 象棋游戏::Message(S_Message &sfp) {
	Log(gcnew String(sfp.Name) + " 说:" + gcnew String(sfp.msg));
}

void 象棋游戏::MoveChess(S_ChessTable &sctTemp) {
	map<string, ChessPieceStatus> Temp;
	StructToChessStatus(sctTemp.HongChessStatus, Temp);
	//生成棋谱语句 //用于传输的 统一是 以红方在我方为准
	if (OurColor == RED) {
		listBoxMenu->Items->Add(gcnew String(GenerateManualWord(ChessStatus, Temp).c_str()));
	}
	else if(OurColor == BLACK) { //为黑色
		map<string, ChessPieceStatus> _tempOld = ChessStatus;
		ReversalChess(_tempOld);
		listBoxMenu->Items->Add(gcnew String(GenerateManualWord(_tempOld, Temp).c_str()));
	}
	//跟新棋谱
	chessmanual.push_back(Temp);

	if (OurColor == BLACK) ReversalChess(Temp);
	ChessStatus = Temp;

	ShowChessByStatus();
	PlaySoundEffect();
	StepAllClose();
	if (g_pi.NowSeatId == sctTemp.NextSeat) {
		_EnemyStepStart();
		_OurStepAbort();
		//userLog->LogOutput("我方走棋");
	}
	else {
		_EnemyStepAbort();
		_OurStepStart();
		//userLog->LogOutput("对方走棋");
	}
	NextSeat = (NextSeat + 1) % 2;
}

void 象棋游戏::ReconnectMove(S_ChessTable &sctTemp) {
	map<string, ChessPieceStatus> Temp;
	StructToChessStatus(sctTemp.HongChessStatus, Temp);
	//生成棋谱语句 //用于传输的 统一是 以红方在我方为准
	if (OurColor == RED) {
		listBoxMenu->Items->Add(gcnew String(GenerateManualWord(ChessStatus, Temp).c_str()));
	}
	else if (OurColor == BLACK) { //为黑色
		map<string, ChessPieceStatus> _tempOld = ChessStatus;
		ReversalChess(_tempOld);
		listBoxMenu->Items->Add(gcnew String(GenerateManualWord(_tempOld, Temp).c_str()));
	}
	//跟新棋谱
	chessmanual.push_back(Temp);

	if (OurColor == BLACK) ReversalChess(Temp);
	ChessStatus = Temp;

	ShowChessByStatus();
	PlaySoundEffect();
	listBoxMenu->Items->Add("走棋");
	StepAllClose();
	if (g_pi.NowSeatId == sctTemp.NextSeat) {

		_EnemyStepAbort();
		_OurStepStart();
		userLog->LogOutput("对方走棋");
	}
	else {
		_EnemyStepStart();
		_OurStepAbort();
		userLog->LogOutput("我方走棋");
	}
	NextSeat = sctTemp.NextSeat;
}


//一是准备 而是登入桌子
void 象棋游戏::UpdateTableInfo(S_TableInfo &sti) {
	if (sti.spi[0].id == g_pi.id) {
		if (sti.spi[0].GameStatus == GAMESTATUS_READY) OurReady->Text = "已准备";
		if (sti.spi[1].GameStatus == GAMESTATUS_READY) EnemyReady->Text = "已准备";
		LoadHeadPic(OurHeadPic, gcnew String(sti.spi[0].HeadPictureName));
		LoadHeadPic(EnemyHeadPic, gcnew String(sti.spi[1].HeadPictureName));
		OurName->Text = gcnew String(sti.spi[0].Name);
		EnemyName->Text = gcnew String(sti.spi[1].Name);
	}
	else if (sti.spi[1].id == g_pi.id) {
		if (sti.spi[0].GameStatus == GAMESTATUS_READY) EnemyReady->Text = "已准备";
		if (sti.spi[1].GameStatus == GAMESTATUS_READY) OurReady->Text = "已准备";
		LoadHeadPic(OurHeadPic, gcnew String(sti.spi[1].HeadPictureName));
		LoadHeadPic(EnemyHeadPic, gcnew String(sti.spi[0].HeadPictureName));
		OurName->Text = gcnew String(sti.spi[1].Name);
		EnemyName->Text = gcnew String(sti.spi[0].Name);
	}
	else { //观战模式
	
	}
}


void 象棋游戏::Log(String^in) {
	userLog->LogOutput(in);
}
void 象棋游戏::_OurStepStart() {
	OurStep = gcnew Thread(gcnew ThreadStart(this, &象棋游戏::OurStepStart));
	OurStep->IsBackground = true;
	OurStep->Start();
}
void 象棋游戏::_EnemyStepStart() {
	EnemyStep = gcnew Thread(gcnew ThreadStart(this, &象棋游戏::EnemyStepStart));
	EnemyStep->IsBackground = true;
	EnemyStep->Start();
}
void 象棋游戏::_TotalStart() {
	Total = gcnew Thread(gcnew ThreadStart(this, &象棋游戏::TotalStart));
	Total->IsBackground = true;
	Total->Start();
}
void 象棋游戏::_OurStepAbort() {
	try {
		OurStep->Abort();
		labelOurStepTime->Text = "01:00";
	}
	catch(System::Exception ^e){}
}
void 象棋游戏::_EnemyStepAbort() {
	try {
		EnemyStep->Abort();
		labelEnemyStepTime->Text = "01:00";
	}
	catch (System::Exception ^e) {}
}
void 象棋游戏::_TotalAbort() {
	try {
		Total->Abort();
		labelTotalTime->Text = "00:00";
	}
	catch (System::Exception ^e) {}
}
void 象棋游戏::OurStepStart() {
	labelOurStepTime->Text = "01:00";
	DateTime StepEnd = DateTime::Now.AddMinutes(1);
	while (1) {
		Sleep(1000);
		TimeSpan d = StepEnd - DateTime::Now;
		String^ t = String::Format("{0:00}:{1:00}", d.Minutes, d.Seconds);
		labelOurStepTime->Text = t;
		String ^Temp = t->Replace(":", ",");
		if (Convert::ToSingle(Temp) <= 0) {
		 //发送超时 判断输了消息
			Head H;
			H.Type = HEAD_GAMEOVER;
			int Type = 0x01; //超时
			Cli_SendRequest(HEAD_GAMEOVER,string( (char*)&Type,sizeof(int)));
			_OurStepAbort();
		}
	}
}

void 象棋游戏::EnemyStepStart() {
	labelEnemyStepTime->Text = "01:00";
	DateTime StepEnd = DateTime::Now.AddMinutes(1);
	while (1) {
		Sleep(1000);
		TimeSpan d = StepEnd - DateTime::Now;
		String^ t = String::Format("{0:00}:{1:00}", d.Minutes, d.Seconds);
		labelEnemyStepTime->Text = t;
		String ^Temp = t->Replace(":", ",");
		if (Convert::ToSingle(Temp) <= 0) {
			_EnemyStepAbort();
		}
	}
}
void 象棋游戏::TotalStart() {
	labelTotalTime->Text = "00:00";
	DateTime GameStart = DateTime::Now; //游戏开始时间
	while (1) {
		Sleep(1000);
		TimeSpan d = DateTime::Now - GameStart;
		String^ t = String::Format("{0:00}:{1:00}:{2:00}", d.Hours, d.Minutes, d.Seconds);
		labelTotalTime->Text = t;
	}
}