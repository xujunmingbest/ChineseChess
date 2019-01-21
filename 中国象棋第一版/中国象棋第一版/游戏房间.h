#pragma once
#include "登入.h"
#include "象棋游戏.h"
namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// <summary>
	/// 游戏房间 摘要
	/// </summary>
	public ref class 游戏房间 : public DockContent
	{
	public:
		游戏房间()
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
		~游戏房间()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	protected:
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox16;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  Table6_1;
	private: System::Windows::Forms::PictureBox^  Table6_2;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  Table1_1;
	private: System::Windows::Forms::PictureBox^  Table1_2;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  Table2_1;
	private: System::Windows::Forms::PictureBox^  Table2_2;


	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  Table3_1;
	private: System::Windows::Forms::PictureBox^  Table3_2;


	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  Table4_1;
	private: System::Windows::Forms::PictureBox^  Table4_2;


	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  Table5_1;
	private: System::Windows::Forms::PictureBox^  Table5_2;


	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::PictureBox^  pictureBox19;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::PictureBox^  Table7_1;
	private: System::Windows::Forms::PictureBox^  Table7_2;


	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::PictureBox^  pictureBox22;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PictureBox^  Table8_1;
	private: System::Windows::Forms::PictureBox^  Table8_2;


	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::PictureBox^  pictureBox25;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::PictureBox^  Table9_1;
	private: System::Windows::Forms::PictureBox^  Table9_2;


	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::PictureBox^  pictureBox28;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::PictureBox^  Table10_1;
	private: System::Windows::Forms::PictureBox^  Table10_2;







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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(游戏房间::typeid));
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Table1_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table1_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Table2_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table2_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Table3_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table3_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Table4_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table4_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Table5_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table5_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Table6_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table6_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Table7_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table7_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Table8_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table8_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Table9_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table9_2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Table10_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Table10_2 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1_2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2_2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3_2))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table4_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table4_2))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table5_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table5_2))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table6_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table6_2))->BeginInit();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table7_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table7_2))->BeginInit();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table8_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table8_2))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table9_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table9_2))->BeginInit();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table10_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table10_2))->BeginInit();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Controls->Add(this->panel3);
			this->flowLayoutPanel1->Controls->Add(this->panel4);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel6);
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel8);
			this->flowLayoutPanel1->Controls->Add(this->panel9);
			this->flowLayoutPanel1->Controls->Add(this->panel10);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(586, 436);
			this->flowLayoutPanel1->TabIndex = 6;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &游戏房间::flowLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->Table1_1);
			this->panel1->Controls->Add(this->Table1_2);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(187, 100);
			this->panel1->TabIndex = 4;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(66, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(50, 50);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(63, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 23);
			this->label1->TabIndex = 3;
			this->label1->Text = L"第1桌";
			// 
			// Table1_1
			// 
			this->Table1_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table1_1.Image")));
			this->Table1_1->Location = System::Drawing::Point(10, 12);
			this->Table1_1->Name = L"Table1_1";
			this->Table1_1->Size = System::Drawing::Size(50, 50);
			this->Table1_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table1_1->TabIndex = 0;
			this->Table1_1->TabStop = false;
			this->Table1_1->Click += gcnew System::EventHandler(this, &游戏房间::pictureBox1_Click);
			// 
			// Table1_2
			// 
			this->Table1_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table1_2.Image")));
			this->Table1_2->Location = System::Drawing::Point(122, 12);
			this->Table1_2->Name = L"Table1_2";
			this->Table1_2->Size = System::Drawing::Size(50, 50);
			this->Table1_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table1_2->TabIndex = 1;
			this->Table1_2->TabStop = false;
			this->Table1_2->Click += gcnew System::EventHandler(this, &游戏房间::pictureBox2_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->Table2_1);
			this->panel2->Controls->Add(this->Table2_2);
			this->panel2->Location = System::Drawing::Point(196, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(187, 100);
			this->panel2->TabIndex = 5;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(66, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(50, 50);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(63, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"第2桌";
			// 
			// Table2_1
			// 
			this->Table2_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table2_1.Image")));
			this->Table2_1->Location = System::Drawing::Point(10, 12);
			this->Table2_1->Name = L"Table2_1";
			this->Table2_1->Size = System::Drawing::Size(50, 50);
			this->Table2_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table2_1->TabIndex = 0;
			this->Table2_1->TabStop = false;
			this->Table2_1->Click += gcnew System::EventHandler(this, &游戏房间::Table2_1_Click);
			// 
			// Table2_2
			// 
			this->Table2_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table2_2.Image")));
			this->Table2_2->Location = System::Drawing::Point(122, 12);
			this->Table2_2->Name = L"Table2_2";
			this->Table2_2->Size = System::Drawing::Size(50, 50);
			this->Table2_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table2_2->TabIndex = 1;
			this->Table2_2->TabStop = false;
			this->Table2_2->Click += gcnew System::EventHandler(this, &游戏房间::Table2_2_Click);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->pictureBox7);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->Table3_1);
			this->panel3->Controls->Add(this->Table3_2);
			this->panel3->Location = System::Drawing::Point(389, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(187, 100);
			this->panel3->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(66, 12);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(50, 50);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 2;
			this->pictureBox7->TabStop = false;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(63, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"第3桌";
			// 
			// Table3_1
			// 
			this->Table3_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table3_1.Image")));
			this->Table3_1->Location = System::Drawing::Point(10, 12);
			this->Table3_1->Name = L"Table3_1";
			this->Table3_1->Size = System::Drawing::Size(50, 50);
			this->Table3_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table3_1->TabIndex = 0;
			this->Table3_1->TabStop = false;
			this->Table3_1->Click += gcnew System::EventHandler(this, &游戏房间::Table3_1_Click);
			// 
			// Table3_2
			// 
			this->Table3_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table3_2.Image")));
			this->Table3_2->Location = System::Drawing::Point(122, 12);
			this->Table3_2->Name = L"Table3_2";
			this->Table3_2->Size = System::Drawing::Size(50, 50);
			this->Table3_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table3_2->TabIndex = 1;
			this->Table3_2->TabStop = false;
			this->Table3_2->Click += gcnew System::EventHandler(this, &游戏房间::Table3_2_Click);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->pictureBox10);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->Table4_1);
			this->panel4->Controls->Add(this->Table4_2);
			this->panel4->Location = System::Drawing::Point(3, 109);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(187, 100);
			this->panel4->TabIndex = 6;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(66, 12);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(50, 50);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 2;
			this->pictureBox10->TabStop = false;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(63, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"第4桌";
			// 
			// Table4_1
			// 
			this->Table4_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table4_1.Image")));
			this->Table4_1->Location = System::Drawing::Point(10, 12);
			this->Table4_1->Name = L"Table4_1";
			this->Table4_1->Size = System::Drawing::Size(50, 50);
			this->Table4_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table4_1->TabIndex = 0;
			this->Table4_1->TabStop = false;
			this->Table4_1->Click += gcnew System::EventHandler(this, &游戏房间::Table4_1_Click);
			// 
			// Table4_2
			// 
			this->Table4_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table4_2.Image")));
			this->Table4_2->Location = System::Drawing::Point(122, 12);
			this->Table4_2->Name = L"Table4_2";
			this->Table4_2->Size = System::Drawing::Size(50, 50);
			this->Table4_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table4_2->TabIndex = 1;
			this->Table4_2->TabStop = false;
			this->Table4_2->Click += gcnew System::EventHandler(this, &游戏房间::Table4_2_Click);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->pictureBox13);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->Table5_1);
			this->panel5->Controls->Add(this->Table5_2);
			this->panel5->Location = System::Drawing::Point(196, 109);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(187, 100);
			this->panel5->TabIndex = 5;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(66, 12);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(50, 50);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox13->TabIndex = 2;
			this->pictureBox13->TabStop = false;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(63, 74);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 23);
			this->label5->TabIndex = 3;
			this->label5->Text = L"第5桌";
			// 
			// Table5_1
			// 
			this->Table5_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table5_1.Image")));
			this->Table5_1->Location = System::Drawing::Point(10, 12);
			this->Table5_1->Name = L"Table5_1";
			this->Table5_1->Size = System::Drawing::Size(50, 50);
			this->Table5_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table5_1->TabIndex = 0;
			this->Table5_1->TabStop = false;
			this->Table5_1->Click += gcnew System::EventHandler(this, &游戏房间::Table5_1_Click);
			// 
			// Table5_2
			// 
			this->Table5_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table5_2.Image")));
			this->Table5_2->Location = System::Drawing::Point(122, 12);
			this->Table5_2->Name = L"Table5_2";
			this->Table5_2->Size = System::Drawing::Size(50, 50);
			this->Table5_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table5_2->TabIndex = 1;
			this->Table5_2->TabStop = false;
			this->Table5_2->Click += gcnew System::EventHandler(this, &游戏房间::Table5_2_Click);
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel6->Controls->Add(this->pictureBox16);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Controls->Add(this->Table6_1);
			this->panel6->Controls->Add(this->Table6_2);
			this->panel6->Location = System::Drawing::Point(389, 109);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(187, 100);
			this->panel6->TabIndex = 7;
			// 
			// pictureBox16
			// 
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(66, 12);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(50, 50);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox16->TabIndex = 2;
			this->pictureBox16->TabStop = false;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(63, 74);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 23);
			this->label6->TabIndex = 3;
			this->label6->Text = L"第6桌";
			// 
			// Table6_1
			// 
			this->Table6_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table6_1.Image")));
			this->Table6_1->Location = System::Drawing::Point(10, 12);
			this->Table6_1->Name = L"Table6_1";
			this->Table6_1->Size = System::Drawing::Size(50, 50);
			this->Table6_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table6_1->TabIndex = 0;
			this->Table6_1->TabStop = false;
			this->Table6_1->Click += gcnew System::EventHandler(this, &游戏房间::pictureBox17_Click);
			// 
			// Table6_2
			// 
			this->Table6_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table6_2.Image")));
			this->Table6_2->Location = System::Drawing::Point(122, 12);
			this->Table6_2->Name = L"Table6_2";
			this->Table6_2->Size = System::Drawing::Size(50, 50);
			this->Table6_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table6_2->TabIndex = 1;
			this->Table6_2->TabStop = false;
			this->Table6_2->Click += gcnew System::EventHandler(this, &游戏房间::pictureBox18_Click);
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel7->Controls->Add(this->pictureBox19);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->Table7_1);
			this->panel7->Controls->Add(this->Table7_2);
			this->panel7->Location = System::Drawing::Point(3, 215);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(187, 100);
			this->panel7->TabIndex = 8;
			// 
			// pictureBox19
			// 
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(66, 12);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(50, 50);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox19->TabIndex = 2;
			this->pictureBox19->TabStop = false;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(63, 74);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 23);
			this->label7->TabIndex = 3;
			this->label7->Text = L"第7桌";
			// 
			// Table7_1
			// 
			this->Table7_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table7_1.Image")));
			this->Table7_1->Location = System::Drawing::Point(10, 12);
			this->Table7_1->Name = L"Table7_1";
			this->Table7_1->Size = System::Drawing::Size(50, 50);
			this->Table7_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table7_1->TabIndex = 0;
			this->Table7_1->TabStop = false;
			this->Table7_1->Click += gcnew System::EventHandler(this, &游戏房间::Table7_1_Click);
			// 
			// Table7_2
			// 
			this->Table7_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table7_2.Image")));
			this->Table7_2->Location = System::Drawing::Point(122, 12);
			this->Table7_2->Name = L"Table7_2";
			this->Table7_2->Size = System::Drawing::Size(50, 50);
			this->Table7_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table7_2->TabIndex = 1;
			this->Table7_2->TabStop = false;
			this->Table7_2->Click += gcnew System::EventHandler(this, &游戏房间::Table7_2_Click);
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel8->Controls->Add(this->pictureBox22);
			this->panel8->Controls->Add(this->label8);
			this->panel8->Controls->Add(this->Table8_1);
			this->panel8->Controls->Add(this->Table8_2);
			this->panel8->Location = System::Drawing::Point(196, 215);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(187, 100);
			this->panel8->TabIndex = 9;
			// 
			// pictureBox22
			// 
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(66, 12);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(50, 50);
			this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox22->TabIndex = 2;
			this->pictureBox22->TabStop = false;
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(63, 74);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 23);
			this->label8->TabIndex = 3;
			this->label8->Text = L"第8桌";
			// 
			// Table8_1
			// 
			this->Table8_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table8_1.Image")));
			this->Table8_1->Location = System::Drawing::Point(10, 12);
			this->Table8_1->Name = L"Table8_1";
			this->Table8_1->Size = System::Drawing::Size(50, 50);
			this->Table8_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table8_1->TabIndex = 0;
			this->Table8_1->TabStop = false;
			this->Table8_1->Click += gcnew System::EventHandler(this, &游戏房间::Table8_1_Click);
			// 
			// Table8_2
			// 
			this->Table8_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table8_2.Image")));
			this->Table8_2->Location = System::Drawing::Point(122, 12);
			this->Table8_2->Name = L"Table8_2";
			this->Table8_2->Size = System::Drawing::Size(50, 50);
			this->Table8_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table8_2->TabIndex = 1;
			this->Table8_2->TabStop = false;
			this->Table8_2->Click += gcnew System::EventHandler(this, &游戏房间::Table8_2_Click);
			// 
			// panel9
			// 
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel9->Controls->Add(this->pictureBox25);
			this->panel9->Controls->Add(this->label9);
			this->panel9->Controls->Add(this->Table9_1);
			this->panel9->Controls->Add(this->Table9_2);
			this->panel9->Location = System::Drawing::Point(389, 215);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(187, 100);
			this->panel9->TabIndex = 10;
			this->panel9->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &游戏房间::panel9_Paint);
			// 
			// pictureBox25
			// 
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(66, 12);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(50, 50);
			this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox25->TabIndex = 2;
			this->pictureBox25->TabStop = false;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(63, 74);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 23);
			this->label9->TabIndex = 3;
			this->label9->Text = L"第9桌";
			// 
			// Table9_1
			// 
			this->Table9_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table9_1.Image")));
			this->Table9_1->Location = System::Drawing::Point(10, 12);
			this->Table9_1->Name = L"Table9_1";
			this->Table9_1->Size = System::Drawing::Size(50, 50);
			this->Table9_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table9_1->TabIndex = 0;
			this->Table9_1->TabStop = false;
			this->Table9_1->Click += gcnew System::EventHandler(this, &游戏房间::Table9_1_Click);
			// 
			// Table9_2
			// 
			this->Table9_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table9_2.Image")));
			this->Table9_2->Location = System::Drawing::Point(122, 12);
			this->Table9_2->Name = L"Table9_2";
			this->Table9_2->Size = System::Drawing::Size(50, 50);
			this->Table9_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table9_2->TabIndex = 1;
			this->Table9_2->TabStop = false;
			this->Table9_2->Click += gcnew System::EventHandler(this, &游戏房间::Table9_2_Click);
			// 
			// panel10
			// 
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel10->Controls->Add(this->pictureBox28);
			this->panel10->Controls->Add(this->label10);
			this->panel10->Controls->Add(this->Table10_1);
			this->panel10->Controls->Add(this->Table10_2);
			this->panel10->Location = System::Drawing::Point(3, 321);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(187, 100);
			this->panel10->TabIndex = 11;
			// 
			// pictureBox28
			// 
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(66, 12);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(50, 50);
			this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox28->TabIndex = 2;
			this->pictureBox28->TabStop = false;
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(63, 74);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 23);
			this->label10->TabIndex = 3;
			this->label10->Text = L"第10桌";
			// 
			// Table10_1
			// 
			this->Table10_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table10_1.Image")));
			this->Table10_1->Location = System::Drawing::Point(10, 12);
			this->Table10_1->Name = L"Table10_1";
			this->Table10_1->Size = System::Drawing::Size(50, 50);
			this->Table10_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table10_1->TabIndex = 0;
			this->Table10_1->TabStop = false;
			this->Table10_1->Click += gcnew System::EventHandler(this, &游戏房间::Table10_1_Click);
			// 
			// Table10_2
			// 
			this->Table10_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Table10_2.Image")));
			this->Table10_2->Location = System::Drawing::Point(122, 12);
			this->Table10_2->Name = L"Table10_2";
			this->Table10_2->Size = System::Drawing::Size(50, 50);
			this->Table10_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Table10_2->TabIndex = 1;
			this->Table10_2->TabStop = false;
			this->Table10_2->Click += gcnew System::EventHandler(this, &游戏房间::Table10_2_Click);
			// 
			// 游戏房间
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 436);
			this->ControlBox = false;
			this->Controls->Add(this->flowLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"游戏房间";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"游戏房间";
			this->Load += gcnew System::EventHandler(this, &游戏房间::游戏房间_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1_2))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2_2))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table3_2))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table4_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table4_2))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table5_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table5_2))->EndInit();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table6_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table6_2))->EndInit();
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table7_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table7_2))->EndInit();
			this->panel8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table8_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table8_2))->EndInit();
			this->panel9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table9_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table9_2))->EndInit();
			this->panel10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table10_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table10_2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void 游戏房间_Load(System::Object^  sender, System::EventArgs^  e) {
	CheckForIllegalCrossThreadCalls = false;
	Cli_SendRequest(HEAD_PICTURELIST);
	Cli_SendRequest(HEAD_ROOMINFO);
	this->CloseButton = false;
	this->CloseButtonVisible = false;
}
		 登入 ^登入Wnd;
		// 象棋游戏 ^象棋游戏Wnd;
		 public: void UdateRoomInfo(S_TableInfo STs[10]);
				 void UpdateTable(S_TableInfo &STi);
		 String ^NoUserHead = "UserData\\HeadPic\\空用户.png";
private: System::Void pictureBox17_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(5,0);
}
private: System::Void pictureBox18_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(5,1);
}
		 void SelectSeat(int tableId,int SeatId) {
			 S_SelectSeat st; 
			 st.TableId = tableId;
			 st.SeatId = SeatId;
			 Cli_SendRequest(HEAD_USERSELECTSEAT, string((char*)& st, sizeof(st)));
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(0,0);
}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(0,1);
}
private: System::Void panel9_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void Table2_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(1, 0);
}
private: System::Void Table2_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(1, 1);
}
private: System::Void Table3_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(2, 0);
}
private: System::Void Table3_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(2, 1);
}
private: System::Void Table4_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(3, 0);
}
private: System::Void Table4_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(3, 1);
}
private: System::Void Table5_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(4, 0);
}
private: System::Void Table5_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(4, 1);
}
private: System::Void Table7_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(6, 0);
}
private: System::Void Table7_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(6, 1);
}
private: System::Void Table8_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(7, 0);
}
private: System::Void Table8_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(7, 1);
}
private: System::Void Table9_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(8, 0);
}
private: System::Void Table9_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(8, 1);
}
private: System::Void Table10_1_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(9, 0);
}
private: System::Void Table10_2_Click(System::Object^  sender, System::EventArgs^  e) {
	SelectSeat(9, 1);
}
};
}
