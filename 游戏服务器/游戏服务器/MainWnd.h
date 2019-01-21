#pragma once
#include "��Ϸ������.h"
namespace ��Ϸ������ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainWnd ժҪ
	/// </summary>
	public ref class MainWnd : public System::Windows::Forms::Form
	{
	public:
		MainWnd(void)
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
		~MainWnd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListView^  listView1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(238, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 30);
			this->textBox1->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(27, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 23);
			this->label1->TabIndex = 5;
			this->label1->Text = L"��ǰ��������������";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(169, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 36);
			this->button1->TabIndex = 9;
			this->button1->Text = L"ˢ��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWnd::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->listView1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listView1->Location = System::Drawing::Point(0, 130);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(670, 245);
			this->listView1->TabIndex = 10;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// MainWnd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 375);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MainWnd";
			this->Text = L"��Ϸ������";
			this->Load += gcnew System::EventHandler(this, &MainWnd::MainWnd_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWnd_Load(System::Object^  sender, System::EventArgs^  e) {
		listView1->Columns->Add("Id");
		listView1->Columns->Add("����");
		listView1->Columns->Add("״̬");
		listView1->Columns->Add("��ǰ����");
		listView1->Columns->Add("ͷ��");
	}

			 String ^GetStatus(int status) {
				 switch (status) {
				 case	 GAMESTATUS_NOTLOGIN: return "û�е���";
				 case	 GAMESTATUS_LOGIN : return "�ѵ���";
				 case	 GAMESTATUS_INTABLE:return "��������";

				 case	 GAMESTATUS_OUTLINE:return "������";
				 case	 GAMESTATUS_NOTREADY:return "δ׼��";
				 case	 GAMESTATUS_READY :return "��׼��";
				 case	 GAMESTATUS_GAMEING:return "����������";
				 case	 GAMESTATUS_WATCHING:return "���ڹۿ���������";
				 case	 GAMESTATUS_LOSE:return "����";
				 case		 GAMESTATUS_WIN:return "Ӯ��";
				 
				 }
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	map<int ,S_PlayInfo> spis = GetLineLists();
	map<int, S_PlayInfo>::iterator it = spis.begin();
	listView1->Items->Clear();
	for (int i=0; it != spis.end(); it++, i++) {
		S_PlayInfo spi = it->second;
		listView1->Items->Add(spi.id.ToString());
		listView1->Items[i]->SubItems->Add(gcnew String(spi.Name));
		listView1->Items[i]->SubItems->Add(GetStatus(spi.GameStatus));
		listView1->Items[i]->SubItems->Add(spi.NowTableId.ToString());
		listView1->Items[i]->SubItems->Add(gcnew String(spi.HeadPictureName));
	}

	for (int i = 0; i < 5; i++) {
		listView1->Columns[i]->Width = -2;
	}

}
};
}
