#pragma once
#include "��������.h"
namespace �й������һ�� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ��־ ժҪ
	/// </summary>
	public ref class ��־ : public DockContent
	{
	public:
		��־(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~��־()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ��־�ؼ�::UserControl1^  UserLog;
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->UserLog = (gcnew ��־�ؼ�::UserControl1());
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
			this->button1->Text = L"��ȡ�����ӳ�";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &��־::button1_Click);
			// 
			// ��־
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(856, 486);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->UserLog);
			this->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"��־";
			this->Text = L"��־";
			this->Load += gcnew System::EventHandler(this, &��־::��־_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void log(String ^in) {
		UserLog->LogOutput(in);
	}
	private: System::Void ��־_Load(System::Object^  sender, System::EventArgs^  e) {
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
