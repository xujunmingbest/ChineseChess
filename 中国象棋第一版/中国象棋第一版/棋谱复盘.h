#pragma once
#include "象棋游戏.h"
using namespace 中国象棋第一版;
extern vector<map<string, ChessPieceStatus>> ReplayData;
namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WeifenLuo::WinFormsUI::Docking;
	/// <summary>
	/// 棋谱复盘 摘要
	/// </summary>
	public ref class 棋谱复盘 : public DockContent
	{
	public:
		棋谱复盘(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~棋谱复盘()
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
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::ListBox^  listBoxMenu;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(棋谱复盘::typeid));
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBoxMenu = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// P_None
			// 
			this->P_None->BackColor = System::Drawing::Color::Transparent;
			this->P_None->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_None.Image")));
			this->P_None->Location = System::Drawing::Point(408, 121);
			this->P_None->Name = L"P_None";
			this->P_None->Size = System::Drawing::Size(70, 70);
			this->P_None->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_None->TabIndex = 102;
			this->P_None->TabStop = false;
			// 
			// P_HongPao2
			// 
			this->P_HongPao2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongPao2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongPao2.Image")));
			this->P_HongPao2->Location = System::Drawing::Point(666, 614);
			this->P_HongPao2->Name = L"P_HongPao2";
			this->P_HongPao2->Size = System::Drawing::Size(70, 70);
			this->P_HongPao2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongPao2->TabIndex = 101;
			this->P_HongPao2->TabStop = false;
			// 
			// P_HongPao1
			// 
			this->P_HongPao1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongPao1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongPao1.Image")));
			this->P_HongPao1->Location = System::Drawing::Point(150, 614);
			this->P_HongPao1->Name = L"P_HongPao1";
			this->P_HongPao1->Size = System::Drawing::Size(70, 70);
			this->P_HongPao1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongPao1->TabIndex = 100;
			this->P_HongPao1->TabStop = false;
			// 
			// P_HeiPao2
			// 
			this->P_HeiPao2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiPao2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiPao2.Image")));
			this->P_HeiPao2->Location = System::Drawing::Point(666, 191);
			this->P_HeiPao2->Name = L"P_HeiPao2";
			this->P_HeiPao2->Size = System::Drawing::Size(70, 70);
			this->P_HeiPao2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiPao2->TabIndex = 99;
			this->P_HeiPao2->TabStop = false;
			// 
			// P_HeiPao1
			// 
			this->P_HeiPao1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiPao1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiPao1.Image")));
			this->P_HeiPao1->Location = System::Drawing::Point(150, 191);
			this->P_HeiPao1->Name = L"P_HeiPao1";
			this->P_HeiPao1->Size = System::Drawing::Size(70, 70);
			this->P_HeiPao1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiPao1->TabIndex = 98;
			this->P_HeiPao1->TabStop = false;
			// 
			// P_HongBing5
			// 
			this->P_HongBing5->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing5.Image")));
			this->P_HongBing5->Location = System::Drawing::Point(747, 524);
			this->P_HongBing5->Name = L"P_HongBing5";
			this->P_HongBing5->Size = System::Drawing::Size(70, 70);
			this->P_HongBing5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongBing5->TabIndex = 97;
			this->P_HongBing5->TabStop = false;
			// 
			// P_HongBing4
			// 
			this->P_HongBing4->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing4.Image")));
			this->P_HongBing4->Location = System::Drawing::Point(580, 524);
			this->P_HongBing4->Name = L"P_HongBing4";
			this->P_HongBing4->Size = System::Drawing::Size(70, 70);
			this->P_HongBing4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongBing4->TabIndex = 96;
			this->P_HongBing4->TabStop = false;
			// 
			// P_HongBing3
			// 
			this->P_HongBing3->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing3.Image")));
			this->P_HongBing3->Location = System::Drawing::Point(408, 524);
			this->P_HongBing3->Name = L"P_HongBing3";
			this->P_HongBing3->Size = System::Drawing::Size(70, 70);
			this->P_HongBing3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongBing3->TabIndex = 95;
			this->P_HongBing3->TabStop = false;
			// 
			// P_HongBing2
			// 
			this->P_HongBing2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing2.Image")));
			this->P_HongBing2->Location = System::Drawing::Point(236, 524);
			this->P_HongBing2->Name = L"P_HongBing2";
			this->P_HongBing2->Size = System::Drawing::Size(70, 70);
			this->P_HongBing2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongBing2->TabIndex = 94;
			this->P_HongBing2->TabStop = false;
			// 
			// P_HongBing1
			// 
			this->P_HongBing1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongBing1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongBing1.Image")));
			this->P_HongBing1->Location = System::Drawing::Point(65, 524);
			this->P_HongBing1->Name = L"P_HongBing1";
			this->P_HongBing1->Size = System::Drawing::Size(70, 70);
			this->P_HongBing1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongBing1->TabIndex = 93;
			this->P_HongBing1->TabStop = false;
			// 
			// P_HongJiang
			// 
			this->P_HongJiang->BackColor = System::Drawing::Color::Transparent;
			this->P_HongJiang->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongJiang.Image")));
			this->P_HongJiang->Location = System::Drawing::Point(408, 776);
			this->P_HongJiang->Name = L"P_HongJiang";
			this->P_HongJiang->Size = System::Drawing::Size(70, 70);
			this->P_HongJiang->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongJiang->TabIndex = 92;
			this->P_HongJiang->TabStop = false;
			// 
			// P_HongShi1
			// 
			this->P_HongShi1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongShi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongShi1.Image")));
			this->P_HongShi1->Location = System::Drawing::Point(323, 776);
			this->P_HongShi1->Name = L"P_HongShi1";
			this->P_HongShi1->Size = System::Drawing::Size(70, 70);
			this->P_HongShi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongShi1->TabIndex = 91;
			this->P_HongShi1->TabStop = false;
			// 
			// P_HongShi2
			// 
			this->P_HongShi2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongShi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongShi2.Image")));
			this->P_HongShi2->Location = System::Drawing::Point(494, 776);
			this->P_HongShi2->Name = L"P_HongShi2";
			this->P_HongShi2->Size = System::Drawing::Size(70, 70);
			this->P_HongShi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongShi2->TabIndex = 90;
			this->P_HongShi2->TabStop = false;
			// 
			// P_HongXiang1
			// 
			this->P_HongXiang1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongXiang1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongXiang1.Image")));
			this->P_HongXiang1->Location = System::Drawing::Point(236, 776);
			this->P_HongXiang1->Name = L"P_HongXiang1";
			this->P_HongXiang1->Size = System::Drawing::Size(70, 70);
			this->P_HongXiang1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongXiang1->TabIndex = 89;
			this->P_HongXiang1->TabStop = false;
			// 
			// P_HongXiang2
			// 
			this->P_HongXiang2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongXiang2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongXiang2.Image")));
			this->P_HongXiang2->Location = System::Drawing::Point(580, 776);
			this->P_HongXiang2->Name = L"P_HongXiang2";
			this->P_HongXiang2->Size = System::Drawing::Size(70, 70);
			this->P_HongXiang2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongXiang2->TabIndex = 88;
			this->P_HongXiang2->TabStop = false;
			// 
			// P_HongMa1
			// 
			this->P_HongMa1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongMa1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongMa1.Image")));
			this->P_HongMa1->Location = System::Drawing::Point(666, 776);
			this->P_HongMa1->Name = L"P_HongMa1";
			this->P_HongMa1->Size = System::Drawing::Size(70, 70);
			this->P_HongMa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongMa1->TabIndex = 87;
			this->P_HongMa1->TabStop = false;
			// 
			// P_HongChe2
			// 
			this->P_HongChe2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongChe2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongChe2.Image")));
			this->P_HongChe2->Location = System::Drawing::Point(747, 776);
			this->P_HongChe2->Name = L"P_HongChe2";
			this->P_HongChe2->Size = System::Drawing::Size(70, 70);
			this->P_HongChe2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongChe2->TabIndex = 86;
			this->P_HongChe2->TabStop = false;
			// 
			// P_HongChe1
			// 
			this->P_HongChe1->BackColor = System::Drawing::Color::Transparent;
			this->P_HongChe1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongChe1.Image")));
			this->P_HongChe1->Location = System::Drawing::Point(63, 777);
			this->P_HongChe1->Name = L"P_HongChe1";
			this->P_HongChe1->Size = System::Drawing::Size(70, 70);
			this->P_HongChe1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongChe1->TabIndex = 85;
			this->P_HongChe1->TabStop = false;
			// 
			// P_HongMa2
			// 
			this->P_HongMa2->BackColor = System::Drawing::Color::Transparent;
			this->P_HongMa2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HongMa2.Image")));
			this->P_HongMa2->Location = System::Drawing::Point(150, 776);
			this->P_HongMa2->Name = L"P_HongMa2";
			this->P_HongMa2->Size = System::Drawing::Size(70, 70);
			this->P_HongMa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HongMa2->TabIndex = 84;
			this->P_HongMa2->TabStop = false;
			// 
			// P_HeiBing5
			// 
			this->P_HeiBing5->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing5.Image")));
			this->P_HeiBing5->Location = System::Drawing::Point(747, 274);
			this->P_HeiBing5->Name = L"P_HeiBing5";
			this->P_HeiBing5->Size = System::Drawing::Size(70, 70);
			this->P_HeiBing5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiBing5->TabIndex = 83;
			this->P_HeiBing5->TabStop = false;
			// 
			// P_HeiBing4
			// 
			this->P_HeiBing4->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing4.Image")));
			this->P_HeiBing4->Location = System::Drawing::Point(580, 274);
			this->P_HeiBing4->Name = L"P_HeiBing4";
			this->P_HeiBing4->Size = System::Drawing::Size(70, 70);
			this->P_HeiBing4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiBing4->TabIndex = 82;
			this->P_HeiBing4->TabStop = false;
			// 
			// P_HeiBing3
			// 
			this->P_HeiBing3->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing3.Image")));
			this->P_HeiBing3->Location = System::Drawing::Point(408, 274);
			this->P_HeiBing3->Name = L"P_HeiBing3";
			this->P_HeiBing3->Size = System::Drawing::Size(70, 70);
			this->P_HeiBing3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiBing3->TabIndex = 81;
			this->P_HeiBing3->TabStop = false;
			// 
			// P_HeiBing2
			// 
			this->P_HeiBing2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing2.Image")));
			this->P_HeiBing2->Location = System::Drawing::Point(236, 274);
			this->P_HeiBing2->Name = L"P_HeiBing2";
			this->P_HeiBing2->Size = System::Drawing::Size(70, 70);
			this->P_HeiBing2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiBing2->TabIndex = 80;
			this->P_HeiBing2->TabStop = false;
			// 
			// P_HeiJiang
			// 
			this->P_HeiJiang->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiJiang->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiJiang.Image")));
			this->P_HeiJiang->Location = System::Drawing::Point(408, 24);
			this->P_HeiJiang->Name = L"P_HeiJiang";
			this->P_HeiJiang->Size = System::Drawing::Size(70, 70);
			this->P_HeiJiang->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiJiang->TabIndex = 79;
			this->P_HeiJiang->TabStop = false;
			// 
			// P_HeiShi1
			// 
			this->P_HeiShi1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiShi1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiShi1.Image")));
			this->P_HeiShi1->Location = System::Drawing::Point(323, 24);
			this->P_HeiShi1->Name = L"P_HeiShi1";
			this->P_HeiShi1->Size = System::Drawing::Size(70, 70);
			this->P_HeiShi1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiShi1->TabIndex = 78;
			this->P_HeiShi1->TabStop = false;
			// 
			// P_HeiShi2
			// 
			this->P_HeiShi2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiShi2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiShi2.Image")));
			this->P_HeiShi2->Location = System::Drawing::Point(494, 24);
			this->P_HeiShi2->Name = L"P_HeiShi2";
			this->P_HeiShi2->Size = System::Drawing::Size(70, 70);
			this->P_HeiShi2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiShi2->TabIndex = 77;
			this->P_HeiShi2->TabStop = false;
			// 
			// P_HeiXiang1
			// 
			this->P_HeiXiang1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiXiang1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiXiang1.Image")));
			this->P_HeiXiang1->Location = System::Drawing::Point(236, 24);
			this->P_HeiXiang1->Name = L"P_HeiXiang1";
			this->P_HeiXiang1->Size = System::Drawing::Size(70, 70);
			this->P_HeiXiang1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiXiang1->TabIndex = 76;
			this->P_HeiXiang1->TabStop = false;
			// 
			// P_HeiXiang2
			// 
			this->P_HeiXiang2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiXiang2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiXiang2.Image")));
			this->P_HeiXiang2->Location = System::Drawing::Point(580, 24);
			this->P_HeiXiang2->Name = L"P_HeiXiang2";
			this->P_HeiXiang2->Size = System::Drawing::Size(70, 70);
			this->P_HeiXiang2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiXiang2->TabIndex = 75;
			this->P_HeiXiang2->TabStop = false;
			// 
			// P_HeiMa2
			// 
			this->P_HeiMa2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiMa2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiMa2.Image")));
			this->P_HeiMa2->Location = System::Drawing::Point(666, 24);
			this->P_HeiMa2->Name = L"P_HeiMa2";
			this->P_HeiMa2->Size = System::Drawing::Size(70, 70);
			this->P_HeiMa2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiMa2->TabIndex = 74;
			this->P_HeiMa2->TabStop = false;
			// 
			// P_HeiChe2
			// 
			this->P_HeiChe2->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiChe2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiChe2.Image")));
			this->P_HeiChe2->Location = System::Drawing::Point(750, 24);
			this->P_HeiChe2->Name = L"P_HeiChe2";
			this->P_HeiChe2->Size = System::Drawing::Size(70, 70);
			this->P_HeiChe2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiChe2->TabIndex = 73;
			this->P_HeiChe2->TabStop = false;
			// 
			// P_HeiChe1
			// 
			this->P_HeiChe1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiChe1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiChe1.Image")));
			this->P_HeiChe1->Location = System::Drawing::Point(64, 21);
			this->P_HeiChe1->Name = L"P_HeiChe1";
			this->P_HeiChe1->Size = System::Drawing::Size(70, 70);
			this->P_HeiChe1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiChe1->TabIndex = 72;
			this->P_HeiChe1->TabStop = false;
			// 
			// P_HeiMa1
			// 
			this->P_HeiMa1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiMa1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiMa1.Image")));
			this->P_HeiMa1->Location = System::Drawing::Point(150, 24);
			this->P_HeiMa1->Name = L"P_HeiMa1";
			this->P_HeiMa1->Size = System::Drawing::Size(70, 70);
			this->P_HeiMa1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiMa1->TabIndex = 71;
			this->P_HeiMa1->TabStop = false;
			// 
			// P_HeiBing1
			// 
			this->P_HeiBing1->BackColor = System::Drawing::Color::Transparent;
			this->P_HeiBing1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_HeiBing1.Image")));
			this->P_HeiBing1->Location = System::Drawing::Point(65, 274);
			this->P_HeiBing1->Name = L"P_HeiBing1";
			this->P_HeiBing1->Size = System::Drawing::Size(70, 70);
			this->P_HeiBing1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_HeiBing1->TabIndex = 70;
			this->P_HeiBing1->TabStop = false;
			// 
			// P_chessboard
			// 
			this->P_chessboard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"P_chessboard.Image")));
			this->P_chessboard->Location = System::Drawing::Point(12, 12);
			this->P_chessboard->Name = L"P_chessboard";
			this->P_chessboard->Size = System::Drawing::Size(860, 860);
			this->P_chessboard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->P_chessboard->TabIndex = 69;
			this->P_chessboard->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->listBoxMenu);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox2->Location = System::Drawing::Point(1133, 24);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(261, 851);
			this->groupBox2->TabIndex = 103;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"棋谱";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(65, 34);
			this->button2->TabIndex = 90;
			this->button2->Text = L"打开";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &棋谱复盘::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(96, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 34);
			this->button1->TabIndex = 89;
			this->button1->Text = L"清空";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(179, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(62, 34);
			this->button4->TabIndex = 88;
			this->button4->Text = L"保存";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// listBoxMenu
			// 
			this->listBoxMenu->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listBoxMenu->FormattingEnabled = true;
			this->listBoxMenu->ItemHeight = 20;
			this->listBoxMenu->Location = System::Drawing::Point(16, 72);
			this->listBoxMenu->Name = L"listBoxMenu";
			this->listBoxMenu->Size = System::Drawing::Size(225, 764);
			this->listBoxMenu->TabIndex = 85;
			this->listBoxMenu->Click += gcnew System::EventHandler(this, &棋谱复盘::listBoxMenu_Click);
			this->listBoxMenu->SelectedIndexChanged += gcnew System::EventHandler(this, &棋谱复盘::listBoxMenu_SelectedIndexChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(878, 824);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 23);
			this->label1->TabIndex = 104;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(878, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 23);
			this->label2->TabIndex = 105;
			this->label2->Text = L"label2";
			// 
			// 棋谱复盘
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1437, 883);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
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
			this->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"棋谱复盘";
			this->Text = L"棋谱复盘";
			this->Load += gcnew System::EventHandler(this, &棋谱复盘::棋谱复盘_Load);
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
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void 棋谱复盘_Load(System::Object^  sender, System::EventArgs^  e) {
		InitP_chessboard();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::DialogResult d=  openFileDialog1->ShowDialog();
	if (d == System::Windows::Forms::DialogResult::OK) {
		String ^filePath = openFileDialog1->FileName;
		ManualHead H;
		if (!_ReadManual(T_to_string(filePath), H, ReplayData)) {
			MessageBox::Show("棋谱获取失败");
		}
		else {

			listBoxMenu->Items->Clear();
			for (int i = 0; i < ReplayData.size()-1; i++) {
				string word = GenerateManualWord(ReplayData[i], ReplayData[i+1]);
				listBoxMenu->Items->Add(gcnew String(word.c_str()));
			}
		}

	}
}
		 void InitP_chessboard();

		 void ShowChessByStatus(map<string, ChessPieceStatus> &_ChessStatus) {
			 map<string, ChessPieceStatus>::iterator it;

			 for (it = _ChessStatus.begin(); it != _ChessStatus.end(); it++) {
				 string name = it->first;
				 ChessPieceStatus cps = it->second;
				 Control ^control = P_chessboard->Controls->Find(gcnew String(name.c_str()), true)[0];
				 PictureBox^ pb = (PictureBox^)control;
				 ChessPixelLocation cpl = GetChessPixelLocationByCoordinate(ChessCoordinatePosition{ cps.CCP.x,cps.CCP.y });
				 pb->Location = Point(cpl.x, cpl.y);
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
private: System::Void listBoxMenu_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		int SelectedIndex = listBoxMenu->SelectedIndex;
		if (listBoxMenu->SelectedIndex == -1 ) {
			if(ReplayData.size() > 0)
			   ShowChessByStatus(ReplayData[0]);
		}
		else {
			if (ReplayData.size() > SelectedIndex + 1)
				ShowChessByStatus(ReplayData[SelectedIndex+1]);
		}
	}
	catch (System::Exception ^ e) {
	
	
	}
}
private: System::Void listBoxMenu_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
