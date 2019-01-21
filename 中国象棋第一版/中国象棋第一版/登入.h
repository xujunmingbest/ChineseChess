#pragma once
#include "联网下棋.h"
namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WeifenLuo::WinFormsUI::Docking;

	/// <summary>
	/// 登入 摘要
	/// </summary>
	public ref class 登入 : public DockContent
	{
	public:
		登入(void)
		{
			InitializeComponent();
			this->CloseButton = false;
			this->CloseButtonVisible = false;
			//
			//TODO:  在此处添加构造函数代码
			//消息队列的封装
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~登入()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button4;
	protected:
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(114, 203);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(119, 26);
			this->button4->TabIndex = 15;
			this->button4->Text = L"更改用户资料";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(114, 153);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 28);
			this->button3->TabIndex = 14;
			this->button3->Text = L"游客登入";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &登入::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 203);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 26);
			this->button2->TabIndex = 13;
			this->button2->Text = L"注册";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(103, 101);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(148, 25);
			this->textBox2->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(103, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 25);
			this->textBox1->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"登入";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(30, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 23);
			this->label2->TabIndex = 9;
			this->label2->Text = L"密码";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(30, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 23);
			this->label1->TabIndex = 8;
			this->label1->Text = L"用户名";
			// 
			// 登入
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 300);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"登入";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"登入";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Cli_SendRequest(HEAD_VISITORLOGIN);
	}
};
}
