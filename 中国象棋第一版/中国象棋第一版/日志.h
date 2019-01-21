#pragma once
#include "联网下棋.h"
namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// 日志 摘要
	/// </summary>
	public ref class 日志 : public DockContent
	{
	public:
		日志(void)
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
		~日志()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 日志控件::UserControl1^  UserLog;
	private: System::Windows::Forms::Button^  button1;
	protected:

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
			this->UserLog = (gcnew 日志控件::UserControl1());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// UserLog
			// 
			this->UserLog->Dock = System::Windows::Forms::DockStyle::Fill;
			this->UserLog->Location = System::Drawing::Point(0, 0);
			this->UserLog->Name = L"UserLog";
			this->UserLog->Size = System::Drawing::Size(856, 486);
			this->UserLog->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(346, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 26);
			this->button1->TabIndex = 1;
			this->button1->Text = L"获取网络延迟";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &日志::button1_Click);
			// 
			// 日志
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(856, 486);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->UserLog);
			this->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"日志";
			this->Text = L"日志";
			this->Load += gcnew System::EventHandler(this, &日志::日志_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void log(String ^in) {
		UserLog->LogOutput(in);
	}
	private: System::Void 日志_Load(System::Object^  sender, System::EventArgs^  e) {
		this->CloseButton = false;
		this->CloseButtonVisible = false;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		S_PackTest PackTest;
		PackTest.SendTimeStamp = clock();
		Cli_SendRequest(HEAD_NETWORKPACKAGE, string( (char*)&PackTest,sizeof(S_PackTest)));
	}
	};
}
