#pragma once
#include "联网下棋.h"
#include "E:\\中国象棋\\象棋走棋规则\\象棋走棋规则\\棋谱生成.h"
extern map<string, ChessPieceStatus> ChessStatus;
#define HEADSAVEPATH "UserData/HeadPic/"
#define MANUALSAVEPATH "UserData/Manual/"
#define MANUALSUFFIX "manual"
#define WORDSUFFIX "word"

using namespace System::Windows::Forms;
using namespace System;
using namespace System::IO;
void LoadHeadPic(PictureBox^ p, String^ path);
void HideAllChessPieces();
string T_to_string(String^in);


extern bool OurColor ;
extern int NextSeat;

namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// 象棋游戏 摘要
	/// </summary>
	public ref class 象棋游戏 : public System::Windows::Forms::Form
	{
	public:
		象棋游戏(AxWMPLib::AxWindowsMediaPlayer ^p)
		{
			axWindowsMediaPlayer1 = p;
			InitializeComponent();
			InitP_chessboard();
			HideAllChessPieces();
			ShowChessByStatus();

			
			int x = P_chessboard->Location.X + P_chessboard->Size.Width + 10;
			int y = P_chessboard->Location.Y;
			panelOtherInfo->Location = Point(x,y);
			MessageBox::Show(panelOtherInfo->Location.X.ToString());
			MessageBox::Show(P_chessboard->Width.ToString()+ ":" + P_chessboard->Height.ToString());

			//InitRedOpening(ChessStatus);

			//
			//TODO:  在此处添加构造函数代码
			//
		}
		void ShowChessByStatus();
		void InitP_chessboard(); //初始化
		PictureBox^ GetOurChoosePiece();
		void ClickChangeColor(PictureBox ^ pb);
		void AllOurChesePieceTransparent();
		bool GetChessPieceColor(PictureBox ^pb);
		void PlaySoundEffect();

		//修改敌人信息
		//void UpdatePlay(S_TableInfo &sct);
		void KaiJu(S_ChessTable &sctTemp);
		void MoveChess(S_ChessTable &sctTemp);
		void ReconnectMove(S_ChessTable &sctTemp);
		void UpdateTableInfo(S_TableInfo &sti);
		void GameOver(S_GameOver &sgo);
		void LeaveTable(S_LeaveTable &slt);
		void UserOutLine(S_UserOutLine &suol);
		void SueForPeace(S_SueForPeace &sfp);
		void Message(S_Message &sfp);
		void Log(String^in);
	private: System::Windows::Forms::Button^  buttonTakeBack;
	public:

	private: System::Windows::Forms::Button^  buttonPeace;

	public:

	private: System::Windows::Forms::Button^  buttonGiveUp;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBoxMessage;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panelOtherInfo;


			 AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
		protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~象棋游戏()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  P_None;
	protected:
	private: System::Windows::Forms::PictureBox^  P_HongPao2;
	private: System::Windows::Forms::PictureBox^  P_HongPao1;
	private: System::Windows::Forms::PictureBox^  P_HeiPao2;
	private: System::Windows::Forms::PictureBox^  P_HeiPao1;
	private: System::Windows::Forms::PictureBox^  P_HongBing5;
	private: System::Windows::Forms::PictureBox^  P_HongBing4;
	private: System::Windows::Forms::PictureBox^  P_HongBing3;
	private: System::Windows::Forms::PictureBox^  P_HongBing2;
	private: System::Windows::Forms::PictureBox^  P_HongBing1;
	private: System::Windows::Forms::PictureBox^  P_HongJiang;
	private: System::Windows::Forms::PictureBox^  P_HongShi1;
	private: System::Windows::Forms::PictureBox^  P_HongShi2;
	private: System::Windows::Forms::PictureBox^  P_HongXiang1;
	private: System::Windows::Forms::PictureBox^  P_HongXiang2;
	private: System::Windows::Forms::PictureBox^  P_HongMa1;
	private: System::Windows::Forms::PictureBox^  P_HongChe2;
	private: System::Windows::Forms::PictureBox^  P_HongChe1;
	private: System::Windows::Forms::PictureBox^  P_HongMa2;
	private: System::Windows::Forms::PictureBox^  P_HeiBing5;
	private: System::Windows::Forms::PictureBox^  P_HeiBing4;
	private: System::Windows::Forms::PictureBox^  P_HeiBing3;
	private: System::Windows::Forms::PictureBox^  P_HeiBing2;
	private: System::Windows::Forms::PictureBox^  P_HeiJiang;
	private: System::Windows::Forms::PictureBox^  P_HeiShi1;
	private: System::Windows::Forms::PictureBox^  P_HeiShi2;
	private: System::Windows::Forms::PictureBox^  P_HeiXiang1;
	private: System::Windows::Forms::PictureBox^  P_HeiXiang2;
	private: System::Windows::Forms::PictureBox^  P_HeiMa2;
	private: System::Windows::Forms::PictureBox^  P_HeiChe2;
	private: System::Windows::Forms::PictureBox^  P_HeiChe1;
	private: System::Windows::Forms::PictureBox^  P_HeiMa1;
	private: System::Windows::Forms::PictureBox^  P_HeiBing1;
	private: System::Windows::Forms::PictureBox^  P_chessboard;
	private: 日志控件::UserControl1^  userLog;
	private: System::Windows::Forms::PictureBox^  EnemyHeadPic;
	private: System::Windows::Forms::PictureBox^  OurHeadPic;
	private: System::Windows::Forms::Label^  EnemyName;
	private: System::Windows::Forms::Button^  EnemyReady;


	private: System::Windows::Forms::Button^  OurReady;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelEnemyStepTime;
	private: System::Windows::Forms::Label^  labelOurStepTime;




	private: System::Windows::Forms::Label^  labelTotalTime;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  OurName;
private: System::Windows::Forms::ListBox^  listBoxMenu;




	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(象棋游戏::typeid));
			this->P_None = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongPao2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongPao1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiPao2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiPao1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongBing5 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongBing4 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongBing3 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongBing2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongBing1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongJiang = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongShi1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongShi2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongXiang1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongXiang2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongMa1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongChe2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongChe1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HongMa2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiBing5 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiBing4 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiBing3 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiBing2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiJiang = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiShi1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiShi2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiXiang1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiXiang2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiMa2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiChe2 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiChe1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiMa1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_HeiBing1 = (gcnew System::Windows::Forms::PictureBox());
			this->P_chessboard = (gcnew System::Windows::Forms::PictureBox());
			this->userLog = (gcnew 日志控件::UserControl1());
			this->EnemyHeadPic = (gcnew System::Windows::Forms::PictureBox());
			this->OurHeadPic = (gcnew System::Windows::Forms::PictureBox());
			this->EnemyName = (gcnew System::Windows::Forms::Label());
			this->EnemyReady = (gcnew System::Windows::Forms::Button());
			this->OurReady = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelEnemyStepTime = (gcnew System::Windows::Forms::Label());
			this->labelOurStepTime = (gcnew System::Windows::Forms::Label());
			this->labelTotalTime = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->OurName = (gcnew System::Windows::Forms::Label());
			this->listBoxMenu = (gcnew System::Windows::Forms::ListBox());
			this->buttonTakeBack = (gcnew System::Windows::Forms::Button());
			this->buttonPeace = (gcnew System::Windows::Forms::Button());
			this->buttonGiveUp = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panelOtherInfo = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_None))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongPao2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongPao1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiPao2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiPao1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongJiang))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongShi1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongShi2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongXiang1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongXiang2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongMa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongChe2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongChe1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongMa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiJiang))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiShi1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiShi2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiXiang1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiXiang2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiMa2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiChe2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiChe1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiMa1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_chessboard))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EnemyHeadPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OurHeadPic))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panelOtherInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// P_None
			// 
			this->P_None->BackColor = System::Drawing::Color::Transparent;
			this->P_None->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_None.Image")));
			this->P_None->Location = System::Drawing::Point(406, 112);
			this->P_None->Name = L"P_None";
			this->P_None->Size = System::Drawing::Size(80, 80);
			this->P_None->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_None->TabIndex = 68;
			this->P_None->TabStop = false;
			this->P_None->Click += gcnew System::EventHandler(this, &象棋游戏::P_None_Click);
			// 
			// P_HongPao2
			// 
			this->P_HongPao2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongPao2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongPao2.Image")));
			this->P_HongPao2->Location = System::Drawing::Point(664, 605);
			this->P_HongPao2->Name = L"P_HongPao2";
			this->P_HongPao2->Size = System::Drawing::Size(80, 80);
			this->P_HongPao2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongPao2->TabIndex = 67;
			this->P_HongPao2->TabStop = false;
			this->P_HongPao2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongPao2_Click);
			// 
			// P_HongPao1
			// 
			this->P_HongPao1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongPao1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongPao1.Image")));
			this->P_HongPao1->Location = System::Drawing::Point(148, 605);
			this->P_HongPao1->Name = L"P_HongPao1";
			this->P_HongPao1->Size = System::Drawing::Size(80, 80);
			this->P_HongPao1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongPao1->TabIndex = 66;
			this->P_HongPao1->TabStop = false;
			this->P_HongPao1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongPao1_Click);
			// 
			// P_HeiPao2
			// 
			this->P_HeiPao2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiPao2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiPao2.Image")));
			this->P_HeiPao2->Location = System::Drawing::Point(664, 182);
			this->P_HeiPao2->Name = L"P_HeiPao2";
			this->P_HeiPao2->Size = System::Drawing::Size(80, 80);
			this->P_HeiPao2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiPao2->TabIndex = 65;
			this->P_HeiPao2->TabStop = false;
			this->P_HeiPao2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiPao2_Click);
			// 
			// P_HeiPao1
			// 
			this->P_HeiPao1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiPao1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiPao1.Image")));
			this->P_HeiPao1->Location = System::Drawing::Point(148, 182);
			this->P_HeiPao1->Name = L"P_HeiPao1";
			this->P_HeiPao1->Size = System::Drawing::Size(80, 80);
			this->P_HeiPao1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiPao1->TabIndex = 64;
			this->P_HeiPao1->TabStop = false;
			this->P_HeiPao1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiPao1_Click);
			// 
			// P_HongBing5
			// 
			this->P_HongBing5->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing5.Image")));
			this->P_HongBing5->Location = System::Drawing::Point(745, 515);
			this->P_HongBing5->Name = L"P_HongBing5";
			this->P_HongBing5->Size = System::Drawing::Size(80, 80);
			this->P_HongBing5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongBing5->TabIndex = 63;
			this->P_HongBing5->TabStop = false;
			this->P_HongBing5->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongBing5_Click);
			// 
			// P_HongBing4
			// 
			this->P_HongBing4->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing4.Image")));
			this->P_HongBing4->Location = System::Drawing::Point(578, 515);
			this->P_HongBing4->Name = L"P_HongBing4";
			this->P_HongBing4->Size = System::Drawing::Size(80, 80);
			this->P_HongBing4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongBing4->TabIndex = 62;
			this->P_HongBing4->TabStop = false;
			this->P_HongBing4->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongBing4_Click);
			// 
			// P_HongBing3
			// 
			this->P_HongBing3->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing3.Image")));
			this->P_HongBing3->Location = System::Drawing::Point(406, 515);
			this->P_HongBing3->Name = L"P_HongBing3";
			this->P_HongBing3->Size = System::Drawing::Size(80, 80);
			this->P_HongBing3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongBing3->TabIndex = 61;
			this->P_HongBing3->TabStop = false;
			this->P_HongBing3->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongBing3_Click);
			// 
			// P_HongBing2
			// 
			this->P_HongBing2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing2.Image")));
			this->P_HongBing2->Location = System::Drawing::Point(234, 515);
			this->P_HongBing2->Name = L"P_HongBing2";
			this->P_HongBing2->Size = System::Drawing::Size(80, 80);
			this->P_HongBing2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongBing2->TabIndex = 60;
			this->P_HongBing2->TabStop = false;
			this->P_HongBing2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongBing2_Click);
			// 
			// P_HongBing1
			// 
			this->P_HongBing1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing1.Image")));
			this->P_HongBing1->Location = System::Drawing::Point(63, 515);
			this->P_HongBing1->Name = L"P_HongBing1";
			this->P_HongBing1->Size = System::Drawing::Size(80, 80);
			this->P_HongBing1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongBing1->TabIndex = 59;
			this->P_HongBing1->TabStop = false;
			this->P_HongBing1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongBing1_Click);
			// 
			// P_HongJiang
			// 
			this->P_HongJiang->BackColor = System::Drawing::Color::Transparent;
			this->P_HongJiang->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongJiang.Image")));
			this->P_HongJiang->Location = System::Drawing::Point(406, 767);
			this->P_HongJiang->Name = L"P_HongJiang";
			this->P_HongJiang->Size = System::Drawing::Size(80, 80);
			this->P_HongJiang->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongJiang->TabIndex = 58;
			this->P_HongJiang->TabStop = false;
			this->P_HongJiang->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongJiang_Click);
			// 
			// P_HongShi1
			// 
			this->P_HongShi1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongShi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongShi1.Image")));
			this->P_HongShi1->Location = System::Drawing::Point(321, 767);
			this->P_HongShi1->Name = L"P_HongShi1";
			this->P_HongShi1->Size = System::Drawing::Size(80, 80);
			this->P_HongShi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongShi1->TabIndex = 57;
			this->P_HongShi1->TabStop = false;
			this->P_HongShi1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongShi1_Click);
			// 
			// P_HongShi2
			// 
			this->P_HongShi2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongShi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongShi2.Image")));
			this->P_HongShi2->Location = System::Drawing::Point(492, 767);
			this->P_HongShi2->Name = L"P_HongShi2";
			this->P_HongShi2->Size = System::Drawing::Size(80, 80);
			this->P_HongShi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongShi2->TabIndex = 56;
			this->P_HongShi2->TabStop = false;
			this->P_HongShi2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongShi2_Click);
			// 
			// P_HongXiang1
			// 
			this->P_HongXiang1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongXiang1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongXiang1.Image")));
			this->P_HongXiang1->Location = System::Drawing::Point(234, 767);
			this->P_HongXiang1->Name = L"P_HongXiang1";
			this->P_HongXiang1->Size = System::Drawing::Size(80, 80);
			this->P_HongXiang1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongXiang1->TabIndex = 55;
			this->P_HongXiang1->TabStop = false;
			this->P_HongXiang1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongXiang1_Click);
			// 
			// P_HongXiang2
			// 
			this->P_HongXiang2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongXiang2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongXiang2.Image")));
			this->P_HongXiang2->Location = System::Drawing::Point(578, 767);
			this->P_HongXiang2->Name = L"P_HongXiang2";
			this->P_HongXiang2->Size = System::Drawing::Size(80, 80);
			this->P_HongXiang2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongXiang2->TabIndex = 54;
			this->P_HongXiang2->TabStop = false;
			this->P_HongXiang2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongXiang2_Click);
			// 
			// P_HongMa1
			// 
			this->P_HongMa1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongMa1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongMa1.Image")));
			this->P_HongMa1->Location = System::Drawing::Point(664, 767);
			this->P_HongMa1->Name = L"P_HongMa1";
			this->P_HongMa1->Size = System::Drawing::Size(80, 80);
			this->P_HongMa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongMa1->TabIndex = 53;
			this->P_HongMa1->TabStop = false;
			this->P_HongMa1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongMa1_Click);
			// 
			// P_HongChe2
			// 
			this->P_HongChe2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongChe2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongChe2.Image")));
			this->P_HongChe2->Location = System::Drawing::Point(745, 767);
			this->P_HongChe2->Name = L"P_HongChe2";
			this->P_HongChe2->Size = System::Drawing::Size(80, 80);
			this->P_HongChe2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongChe2->TabIndex = 52;
			this->P_HongChe2->TabStop = false;
			this->P_HongChe2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongChe2_Click);
			// 
			// P_HongChe1
			// 
			this->P_HongChe1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongChe1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongChe1.Image")));
			this->P_HongChe1->Location = System::Drawing::Point(61, 768);
			this->P_HongChe1->Name = L"P_HongChe1";
			this->P_HongChe1->Size = System::Drawing::Size(80, 80);
			this->P_HongChe1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongChe1->TabIndex = 51;
			this->P_HongChe1->TabStop = false;
			this->P_HongChe1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongChe1_Click);
			// 
			// P_HongMa2
			// 
			this->P_HongMa2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongMa2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongMa2.Image")));
			this->P_HongMa2->Location = System::Drawing::Point(148, 767);
			this->P_HongMa2->Name = L"P_HongMa2";
			this->P_HongMa2->Size = System::Drawing::Size(80, 80);
			this->P_HongMa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HongMa2->TabIndex = 50;
			this->P_HongMa2->TabStop = false;
			this->P_HongMa2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HongMa2_Click);
			// 
			// P_HeiBing5
			// 
			this->P_HeiBing5->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing5.Image")));
			this->P_HeiBing5->Location = System::Drawing::Point(745, 265);
			this->P_HeiBing5->Name = L"P_HeiBing5";
			this->P_HeiBing5->Size = System::Drawing::Size(80, 80);
			this->P_HeiBing5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiBing5->TabIndex = 49;
			this->P_HeiBing5->TabStop = false;
			this->P_HeiBing5->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiBing5_Click);
			// 
			// P_HeiBing4
			// 
			this->P_HeiBing4->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing4.Image")));
			this->P_HeiBing4->Location = System::Drawing::Point(578, 265);
			this->P_HeiBing4->Name = L"P_HeiBing4";
			this->P_HeiBing4->Size = System::Drawing::Size(80, 80);
			this->P_HeiBing4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiBing4->TabIndex = 48;
			this->P_HeiBing4->TabStop = false;
			this->P_HeiBing4->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiBing4_Click);
			// 
			// P_HeiBing3
			// 
			this->P_HeiBing3->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing3.Image")));
			this->P_HeiBing3->Location = System::Drawing::Point(406, 265);
			this->P_HeiBing3->Name = L"P_HeiBing3";
			this->P_HeiBing3->Size = System::Drawing::Size(80, 80);
			this->P_HeiBing3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiBing3->TabIndex = 47;
			this->P_HeiBing3->TabStop = false;
			this->P_HeiBing3->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiBing3_Click);
			// 
			// P_HeiBing2
			// 
			this->P_HeiBing2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing2.Image")));
			this->P_HeiBing2->Location = System::Drawing::Point(234, 265);
			this->P_HeiBing2->Name = L"P_HeiBing2";
			this->P_HeiBing2->Size = System::Drawing::Size(80, 80);
			this->P_HeiBing2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiBing2->TabIndex = 46;
			this->P_HeiBing2->TabStop = false;
			this->P_HeiBing2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiBing2_Click);
			// 
			// P_HeiJiang
			// 
			this->P_HeiJiang->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiJiang->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiJiang.Image")));
			this->P_HeiJiang->Location = System::Drawing::Point(406, 15);
			this->P_HeiJiang->Name = L"P_HeiJiang";
			this->P_HeiJiang->Size = System::Drawing::Size(80, 80);
			this->P_HeiJiang->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiJiang->TabIndex = 45;
			this->P_HeiJiang->TabStop = false;
			this->P_HeiJiang->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiJiang_Click);
			// 
			// P_HeiShi1
			// 
			this->P_HeiShi1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiShi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiShi1.Image")));
			this->P_HeiShi1->Location = System::Drawing::Point(321, 15);
			this->P_HeiShi1->Name = L"P_HeiShi1";
			this->P_HeiShi1->Size = System::Drawing::Size(80, 80);
			this->P_HeiShi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiShi1->TabIndex = 44;
			this->P_HeiShi1->TabStop = false;
			this->P_HeiShi1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiShi1_Click);
			// 
			// P_HeiShi2
			// 
			this->P_HeiShi2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiShi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiShi2.Image")));
			this->P_HeiShi2->Location = System::Drawing::Point(492, 15);
			this->P_HeiShi2->Name = L"P_HeiShi2";
			this->P_HeiShi2->Size = System::Drawing::Size(80, 80);
			this->P_HeiShi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiShi2->TabIndex = 43;
			this->P_HeiShi2->TabStop = false;
			this->P_HeiShi2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiShi2_Click);
			// 
			// P_HeiXiang1
			// 
			this->P_HeiXiang1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiXiang1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiXiang1.Image")));
			this->P_HeiXiang1->Location = System::Drawing::Point(234, 15);
			this->P_HeiXiang1->Name = L"P_HeiXiang1";
			this->P_HeiXiang1->Size = System::Drawing::Size(80, 80);
			this->P_HeiXiang1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiXiang1->TabIndex = 42;
			this->P_HeiXiang1->TabStop = false;
			this->P_HeiXiang1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiXiang1_Click);
			// 
			// P_HeiXiang2
			// 
			this->P_HeiXiang2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiXiang2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiXiang2.Image")));
			this->P_HeiXiang2->Location = System::Drawing::Point(578, 15);
			this->P_HeiXiang2->Name = L"P_HeiXiang2";
			this->P_HeiXiang2->Size = System::Drawing::Size(80, 80);
			this->P_HeiXiang2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiXiang2->TabIndex = 41;
			this->P_HeiXiang2->TabStop = false;
			this->P_HeiXiang2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiXiang2_Click);
			// 
			// P_HeiMa2
			// 
			this->P_HeiMa2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiMa2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiMa2.Image")));
			this->P_HeiMa2->Location = System::Drawing::Point(664, 15);
			this->P_HeiMa2->Name = L"P_HeiMa2";
			this->P_HeiMa2->Size = System::Drawing::Size(80, 80);
			this->P_HeiMa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiMa2->TabIndex = 40;
			this->P_HeiMa2->TabStop = false;
			this->P_HeiMa2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiMa2_Click);
			// 
			// P_HeiChe2
			// 
			this->P_HeiChe2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiChe2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiChe2.Image")));
			this->P_HeiChe2->Location = System::Drawing::Point(748, 15);
			this->P_HeiChe2->Name = L"P_HeiChe2";
			this->P_HeiChe2->Size = System::Drawing::Size(80, 80);
			this->P_HeiChe2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiChe2->TabIndex = 39;
			this->P_HeiChe2->TabStop = false;
			this->P_HeiChe2->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiChe2_Click);
			// 
			// P_HeiChe1
			// 
			this->P_HeiChe1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiChe1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiChe1.Image")));
			this->P_HeiChe1->Location = System::Drawing::Point(62, 12);
			this->P_HeiChe1->Name = L"P_HeiChe1";
			this->P_HeiChe1->Size = System::Drawing::Size(80, 80);
			this->P_HeiChe1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiChe1->TabIndex = 38;
			this->P_HeiChe1->TabStop = false;
			this->P_HeiChe1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiChe1_Click);
			// 
			// P_HeiMa1
			// 
			this->P_HeiMa1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiMa1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiMa1.Image")));
			this->P_HeiMa1->Location = System::Drawing::Point(148, 15);
			this->P_HeiMa1->Name = L"P_HeiMa1";
			this->P_HeiMa1->Size = System::Drawing::Size(80, 80);
			this->P_HeiMa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiMa1->TabIndex = 37;
			this->P_HeiMa1->TabStop = false;
			this->P_HeiMa1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiMa1_Click);
			// 
			// P_HeiBing1
			// 
			this->P_HeiBing1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing1.Image")));
			this->P_HeiBing1->Location = System::Drawing::Point(63, 265);
			this->P_HeiBing1->Name = L"P_HeiBing1";
			this->P_HeiBing1->Size = System::Drawing::Size(80, 80);
			this->P_HeiBing1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_HeiBing1->TabIndex = 36;
			this->P_HeiBing1->TabStop = false;
			this->P_HeiBing1->Click += gcnew System::EventHandler(this, &象棋游戏::P_HeiBing1_Click);
			// 
			// P_chessboard
			// 
			this->P_chessboard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_chessboard.Image")));
			this->P_chessboard->Location = System::Drawing::Point(10, 3);
			this->P_chessboard->Name = L"P_chessboard";
			this->P_chessboard->Size = System::Drawing::Size(860, 860);
			this->P_chessboard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->P_chessboard->TabIndex = 35;
			this->P_chessboard->TabStop = false;
			this->P_chessboard->Click += gcnew System::EventHandler(this, &象棋游戏::P_chessboard_Click);
			// 
			// userLog
			// 
			this->userLog->Location = System::Drawing::Point(3, 299);
			this->userLog->Name = L"userLog";
			this->userLog->Size = System::Drawing::Size(331, 334);
			this->userLog->TabIndex = 69;
			this->userLog->Load += gcnew System::EventHandler(this, &象棋游戏::userLog_Load);
			// 
			// EnemyHeadPic
			// 
			this->EnemyHeadPic->Location = System::Drawing::Point(2, 18);
			this->EnemyHeadPic->Name = L"EnemyHeadPic";
			this->EnemyHeadPic->Size = System::Drawing::Size(100, 100);
			this->EnemyHeadPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->EnemyHeadPic->TabIndex = 70;
			this->EnemyHeadPic->TabStop = false;
			// 
			// OurHeadPic
			// 
			this->OurHeadPic->Location = System::Drawing::Point(2, 713);
			this->OurHeadPic->Name = L"OurHeadPic";
			this->OurHeadPic->Size = System::Drawing::Size(100, 100);
			this->OurHeadPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->OurHeadPic->TabIndex = 71;
			this->OurHeadPic->TabStop = false;
			// 
			// EnemyName
			// 
			this->EnemyName->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->EnemyName->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->EnemyName->Location = System::Drawing::Point(108, 24);
			this->EnemyName->Name = L"EnemyName";
			this->EnemyName->Size = System::Drawing::Size(226, 23);
			this->EnemyName->TabIndex = 72;
			this->EnemyName->Text = L"label1";
			// 
			// EnemyReady
			// 
			this->EnemyReady->Location = System::Drawing::Point(3, 127);
			this->EnemyReady->Name = L"EnemyReady";
			this->EnemyReady->Size = System::Drawing::Size(86, 54);
			this->EnemyReady->TabIndex = 74;
			this->EnemyReady->Text = L"准备";
			this->EnemyReady->UseVisualStyleBackColor = true;
			this->EnemyReady->Click += gcnew System::EventHandler(this, &象棋游戏::EnemyReady_Click);
			// 
			// OurReady
			// 
			this->OurReady->Location = System::Drawing::Point(3, 819);
			this->OurReady->Name = L"OurReady";
			this->OurReady->Size = System::Drawing::Size(86, 54);
			this->OurReady->TabIndex = 75;
			this->OurReady->Text = L"准备";
			this->OurReady->UseVisualStyleBackColor = true;
			this->OurReady->Click += gcnew System::EventHandler(this, &象棋游戏::OurReady_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(108, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 22);
			this->label4->TabIndex = 77;
			this->label4->Text = L"步时";
			// 
			// labelEnemyStepTime
			// 
			this->labelEnemyStepTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelEnemyStepTime->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->labelEnemyStepTime->Location = System::Drawing::Point(165, 94);
			this->labelEnemyStepTime->Name = L"labelEnemyStepTime";
			this->labelEnemyStepTime->Size = System::Drawing::Size(169, 22);
			this->labelEnemyStepTime->TabIndex = 79;
			this->labelEnemyStepTime->Text = L"1:00";
			// 
			// labelOurStepTime
			// 
			this->labelOurStepTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelOurStepTime->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->labelOurStepTime->Location = System::Drawing::Point(165, 783);
			this->labelOurStepTime->Name = L"labelOurStepTime";
			this->labelOurStepTime->Size = System::Drawing::Size(169, 22);
			this->labelOurStepTime->TabIndex = 84;
			this->labelOurStepTime->Text = L"1:00";
			// 
			// labelTotalTime
			// 
			this->labelTotalTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelTotalTime->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->labelTotalTime->Location = System::Drawing::Point(60, 249);
			this->labelTotalTime->Name = L"labelTotalTime";
			this->labelTotalTime->Size = System::Drawing::Size(213, 22);
			this->labelTotalTime->TabIndex = 83;
			this->labelTotalTime->Text = L"00:00:00";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label8->Location = System::Drawing::Point(108, 783);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 22);
			this->label8->TabIndex = 82;
			this->label8->Text = L"步时";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label9->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label9->Location = System::Drawing::Point(3, 250);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 22);
			this->label9->TabIndex = 81;
			this->label9->Text = L"局时";
			// 
			// OurName
			// 
			this->OurName->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->OurName->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->OurName->Location = System::Drawing::Point(108, 713);
			this->OurName->Name = L"OurName";
			this->OurName->Size = System::Drawing::Size(226, 23);
			this->OurName->TabIndex = 80;
			this->OurName->Text = L"label10";
			// 
			// listBoxMenu
			// 
			this->listBoxMenu->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listBoxMenu->FormattingEnabled = true;
			this->listBoxMenu->ItemHeight = 20;
			this->listBoxMenu->Location = System::Drawing::Point(16, 27);
			this->listBoxMenu->Name = L"listBoxMenu";
			this->listBoxMenu->Size = System::Drawing::Size(225, 604);
			this->listBoxMenu->TabIndex = 85;
			this->listBoxMenu->SelectedIndexChanged += gcnew System::EventHandler(this, &象棋游戏::listBoxMenu_SelectedIndexChanged);
			// 
			// buttonTakeBack
			// 
			this->buttonTakeBack->Location = System::Drawing::Point(95, 819);
			this->buttonTakeBack->Name = L"buttonTakeBack";
			this->buttonTakeBack->Size = System::Drawing::Size(86, 54);
			this->buttonTakeBack->TabIndex = 87;
			this->buttonTakeBack->Text = L"悔棋";
			this->buttonTakeBack->UseVisualStyleBackColor = true;
			// 
			// buttonPeace
			// 
			this->buttonPeace->Location = System::Drawing::Point(187, 819);
			this->buttonPeace->Name = L"buttonPeace";
			this->buttonPeace->Size = System::Drawing::Size(86, 54);
			this->buttonPeace->TabIndex = 88;
			this->buttonPeace->Text = L"求和";
			this->buttonPeace->UseVisualStyleBackColor = true;
			this->buttonPeace->Click += gcnew System::EventHandler(this, &象棋游戏::buttonPeace_Click);
			// 
			// buttonGiveUp
			// 
			this->buttonGiveUp->Location = System::Drawing::Point(279, 819);
			this->buttonGiveUp->Name = L"buttonGiveUp";
			this->buttonGiveUp->Size = System::Drawing::Size(86, 54);
			this->buttonGiveUp->TabIndex = 89;
			this->buttonGiveUp->Text = L"认输";
			this->buttonGiveUp->UseVisualStyleBackColor = true;
			this->buttonGiveUp->Click += gcnew System::EventHandler(this, &象棋游戏::button3_Click);
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(47, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 38);
			this->label1->TabIndex = 90;
			this->label1->Text = L"30";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(108, 146);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 91;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"断线保护时间";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->listBoxMenu);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(351, 39);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(261, 703);
			this->groupBox2->TabIndex = 92;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"棋谱";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(16, 646);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(102, 34);
			this->button4->TabIndex = 86;
			this->button4->Text = L"棋谱保存";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &象棋游戏::button4_Click);
			// 
			// textBoxMessage
			// 
			this->textBoxMessage->Location = System::Drawing::Point(3, 639);
			this->textBoxMessage->Name = L"textBoxMessage";
			this->textBoxMessage->Size = System::Drawing::Size(169, 25);
			this->textBoxMessage->TabIndex = 93;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(178, 636);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 28);
			this->button1->TabIndex = 94;
			this->button1->Text = L"发送";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &象棋游戏::button1_Click);
			// 
			// panelOtherInfo
			// 
			this->panelOtherInfo->Controls->Add(this->userLog);
			this->panelOtherInfo->Controls->Add(this->button1);
			this->panelOtherInfo->Controls->Add(this->EnemyHeadPic);
			this->panelOtherInfo->Controls->Add(this->textBoxMessage);
			this->panelOtherInfo->Controls->Add(this->OurHeadPic);
			this->panelOtherInfo->Controls->Add(this->groupBox2);
			this->panelOtherInfo->Controls->Add(this->EnemyName);
			this->panelOtherInfo->Controls->Add(this->groupBox1);
			this->panelOtherInfo->Controls->Add(this->EnemyReady);
			this->panelOtherInfo->Controls->Add(this->buttonGiveUp);
			this->panelOtherInfo->Controls->Add(this->OurReady);
			this->panelOtherInfo->Controls->Add(this->buttonPeace);
			this->panelOtherInfo->Controls->Add(this->label4);
			this->panelOtherInfo->Controls->Add(this->buttonTakeBack);
			this->panelOtherInfo->Controls->Add(this->labelEnemyStepTime);
			this->panelOtherInfo->Controls->Add(this->labelOurStepTime);
			this->panelOtherInfo->Controls->Add(this->OurName);
			this->panelOtherInfo->Controls->Add(this->labelTotalTime);
			this->panelOtherInfo->Controls->Add(this->label9);
			this->panelOtherInfo->Controls->Add(this->label8);
			this->panelOtherInfo->Location = System::Drawing::Point(876, 3);
			this->panelOtherInfo->Name = L"panelOtherInfo";
			this->panelOtherInfo->Size = System::Drawing::Size(648, 875);
			this->panelOtherInfo->TabIndex = 95;
			// 
			// 象棋游戏
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1591, 774);
			this->Controls->Add(this->panelOtherInfo);
			this->Controls->Add(this->P_None);
			this->Controls->Add(this->P_HongPao2);
			this->Controls->Add(this->P_HongPao1);
			this->Controls->Add(this->P_HeiPao2);
			this->Controls->Add(this->P_HeiPao1);
			this->Controls->Add(this->P_HongBing5);
			this->Controls->Add(this->P_HongBing4);
			this->Controls->Add(this->P_HongBing3);
			this->Controls->Add(this->P_HongBing2);
			this->Controls->Add(this->P_HongBing1);
			this->Controls->Add(this->P_HongJiang);
			this->Controls->Add(this->P_HongShi1);
			this->Controls->Add(this->P_HongShi2);
			this->Controls->Add(this->P_HongXiang1);
			this->Controls->Add(this->P_HongXiang2);
			this->Controls->Add(this->P_HongMa1);
			this->Controls->Add(this->P_HongChe2);
			this->Controls->Add(this->P_HongChe1);
			this->Controls->Add(this->P_HongMa2);
			this->Controls->Add(this->P_HeiBing5);
			this->Controls->Add(this->P_HeiBing4);
			this->Controls->Add(this->P_HeiBing3);
			this->Controls->Add(this->P_HeiBing2);
			this->Controls->Add(this->P_HeiJiang);
			this->Controls->Add(this->P_HeiShi1);
			this->Controls->Add(this->P_HeiShi2);
			this->Controls->Add(this->P_HeiXiang1);
			this->Controls->Add(this->P_HeiXiang2);
			this->Controls->Add(this->P_HeiMa2);
			this->Controls->Add(this->P_HeiChe2);
			this->Controls->Add(this->P_HeiChe1);
			this->Controls->Add(this->P_HeiMa1);
			this->Controls->Add(this->P_HeiBing1);
			this->Controls->Add(this->P_chessboard);
			this->Name = L"象棋游戏";
			this->Text = L"象棋游戏";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &象棋游戏::象棋游戏_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &象棋游戏::象棋游戏_FormClosed);
			this->Load += gcnew System::EventHandler(this, &象棋游戏::象棋游戏_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_None))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongPao2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongPao1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiPao2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiPao1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongBing1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongJiang))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongShi1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongShi2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongXiang1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongXiang2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongMa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongChe2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongChe1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HongMa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiJiang))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiShi1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiShi2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiXiang1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiXiang2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiMa2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiChe2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiChe1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiMa1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_HeiBing1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->P_chessboard))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EnemyHeadPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OurHeadPic))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->panelOtherInfo->ResumeLayout(false);
			this->panelOtherInfo->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void 象棋游戏_Load(System::Object^  sender, System::EventArgs^  e) {
		CheckForIllegalCrossThreadCalls = false; 
    } 

	 Thread ^ Total;
	 Thread ^ OurStep;
	 Thread ^ EnemyStep;
	 void OurStepStart();
	 void EnemyStepStart();
	 void TotalStart();
	 void _OurStepStart();
	 void _EnemyStepStart();
	 void _TotalStart();
	 void _OurStepAbort();
	 void _EnemyStepAbort();
	 void _TotalAbort();

private: System::Void userLog_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void OurReady_Click(System::Object^  sender, System::EventArgs^  e) {
	if (OurReady->Text == "准备") {
		Cli_SendRequest(HEAD_SENDREADY);
	}
}
		 //判断点中的 棋子是红还是黑
		 bool GetClickColor(PictureBox ^pb) {
			 String ^Name = pb->Name;
			 if (Name->Contains("P_Hei")) return BLACK;
			 else if (Name->Contains("P_Hong")) return RED;
		 }
		 void PieceClickEvent(PictureBox ^pb);
private: System::Void P_HeiChe1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiMa1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiXiang1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiShi1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiJiang_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiShi2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiXiang2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiMa2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiChe2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_None_Click(System::Object^  sender, System::EventArgs^  e) {
	if (NextSeat != g_pi.NowSeatId) return;
	PictureBox ^OurChoosePiece = GetOurChoosePiece();
	if (OurChoosePiece == nullptr) return;

	map<string, ChessPieceStatus> HongChessStatus;
	HongChessStatus = ChessStatus;
	if (OurColor == BLACK) ReversalChess(HongChessStatus);

	string name = T_to_string(OurChoosePiece->Name);
	if (InRule(name, HongChessStatus["P_None"].CCP, HongChessStatus)) {
		S_ChessTable sct;
		sct.MoveResult = MoveResult;
		ChessStatusToStruct(HongChessStatus, sct.HongChessStatus);
		Cli_SendRequest(HEAD_MOVECHESS, string((char*)& sct, sizeof(S_ChessTable)));
	}

}
private: System::Void P_HeiPao1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiPao2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiBing1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiBing2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiBing3_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiBing4_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HeiBing5_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongBing1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongBing2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongBing3_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongBing4_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongBing5_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongPao1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongPao2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongChe1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongMa2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongXiang1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongShi1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongJiang_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongShi2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongXiang2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongMa1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_HongChe2_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureBox ^ pb = (PictureBox ^)sender;
	PieceClickEvent(pb);
}
private: System::Void P_chessboard_Click(System::Object^  sender, System::EventArgs^  e) {
	if (NextSeat != g_pi.NowSeatId) return;
	PictureBox ^OurChoosePiece = GetOurChoosePiece();
	if (OurChoosePiece == nullptr) return;


	int x = ((MouseEventArgs^)e)->X - CHESSPIECEWIDTH / 2;
	int y = ((MouseEventArgs^)e)->Y - CHESSPIECEWIDTH / 2;
	ChessCoordinatePosition ccp = GetChessPixelLocation(x, y);
	if (ccp.x == -1) return;
	if (OurColor == BLACK) {
		ccp.x = 10 - ccp.x;
		ccp.y = 11 - ccp.y;
	}
	map<string, ChessPieceStatus> HongChessStatus;
	HongChessStatus = ChessStatus;
	if (OurColor == BLACK) ReversalChess(HongChessStatus);
	
	string name = T_to_string(OurChoosePiece->Name);
	
	if (InRule(name, ccp, HongChessStatus)) {
		S_ChessTable sct;
		sct.MoveResult = MoveResult;
		ChessStatusToStruct(HongChessStatus, sct.HongChessStatus);
		Cli_SendRequest( HEAD_MOVECHESS,string( (char*)& sct,sizeof(S_ChessTable)));
	}
}
private: System::Void 象棋游戏_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	Cli_SendRequest(HEAD_LEAVETABLE);
}


private: System::Void listBoxMenu_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
		 void SaveClose();
		 void StepAllClose();
private: System::Void 象棋游戏_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	System::Windows::Forms::DialogResult dr =  MessageBox::Show("是否要关闭", "退出", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
	if (dr == System::Windows::Forms::DialogResult::OK) {
		SaveClose();
	}
	else {
		e->Cancel = true;
	}
}
		 String^ MyName="";
		 String^ EenmyName = "";
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ File = MyName + "-" + EenmyName+"-";
	DateTime n = DateTime::Now;
	File += n.Year.ToString()+ n.Month.ToString()+ n.Day.ToString() + n.Hour.ToString() + n.Minute.ToString() + n.Second.ToString();
	string fileName = string(MANUALSAVEPATH) +T_to_string( File) + ".manual";
	ManualHead H;
	H.RecordNum = chessmanual.size();
	if (OurColor == RED) {
		snprintf(H.NameRed, sizeof(H.NameRed), "%s", MyName);
		snprintf(H.NameBlack, sizeof(H.NameBlack), "%s", EenmyName);
	}
	else {
		snprintf(H.NameBlack, sizeof(H.NameBlack), "%s", MyName);
		snprintf(H.NameRed, sizeof(H.NameRed), "%s", EenmyName);
	}
	if (_SaveManual(fileName, H, chessmanual)) {
		Log("棋谱保存成功");
	}
	else {
		Log("棋谱保存失败");
	}

}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	::DialogResult d =  MessageBox::Show("确定要认输吗?","提示", MessageBoxButtons::YesNo);
	if (d == ::DialogResult::Yes) {
		int Type = WINTYPE_GIVEUP; //认输
		Cli_SendRequest(HEAD_GAMEOVER, string((char*)&Type, sizeof(int)));
	}
}

private: System::Void buttonPeace_Click(System::Object^  sender, System::EventArgs^  e) {
	::DialogResult d = MessageBox::Show("确定要求和吗?", "提示", MessageBoxButtons::YesNo);
	if (d == ::DialogResult::Yes) {
		S_SueForPeace SueForPeace;
		SueForPeace.Type = PEACESUE;
		Cli_SendRequest(HEAD_SUEFORPEACE, string((char*)&SueForPeace, sizeof(S_SueForPeace)));
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	S_Message sm;
	snprintf(sm.msg, sizeof(sm.msg), "%s", textBoxMessage->Text);

	Cli_SendRequest(HEAD_MESSAGE, string((char*)&sm, sizeof(S_Message)));

}
private: System::Void EnemyReady_Click(System::Object^  sender, System::EventArgs^  e) {
}
};

public ref class Global {
public: static 象棋游戏^ 象棋游戏Wnd;


};
}
