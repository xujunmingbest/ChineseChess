#pragma once
#include "登入.h"
#include "游戏房间.h"
#include "日志.h"
#include "象棋游戏.h"
#include "棋谱复盘.h"
using namespace 中国象棋第一版;

namespace 中国象棋第一版 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WeifenLuo::WinFormsUI::Docking;
	/// <summary>
	/// 主界面 摘要
	/// </summary>
	public ref class 主界面 : public System::Windows::Forms::Form
	{
	public:
		主界面(void)
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~主界面()
		{
			if (components)
			{
				delete components;
			}
		}
	private: WeifenLuo::WinFormsUI::Docking::DockPanel^  dockPanel1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;


	public: AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;

	private: System::Windows::Forms::ToolStripMenuItem^  断线ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  棋谱复盘ToolStripMenuItem;
	public:

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
			WeifenLuo::WinFormsUI::Docking::DockPanelSkin^  dockPanelSkin1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPanelSkin());
			WeifenLuo::WinFormsUI::Docking::AutoHideStripSkin^  autoHideStripSkin1 = (gcnew WeifenLuo::WinFormsUI::Docking::AutoHideStripSkin());
			WeifenLuo::WinFormsUI::Docking::DockPanelGradient^  dockPanelGradient1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPanelGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient1 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::DockPaneStripSkin^  dockPaneStripSkin1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPaneStripSkin());
			WeifenLuo::WinFormsUI::Docking::DockPaneStripGradient^  dockPaneStripGradient1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPaneStripGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient2 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::DockPanelGradient^  dockPanelGradient2 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPanelGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient3 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::DockPaneStripToolWindowGradient^  dockPaneStripToolWindowGradient1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPaneStripToolWindowGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient4 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient5 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::DockPanelGradient^  dockPanelGradient3 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPanelGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient6 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			WeifenLuo::WinFormsUI::Docking::TabGradient^  tabGradient7 = (gcnew WeifenLuo::WinFormsUI::Docking::TabGradient());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(主界面::typeid));
			this->dockPanel1 = (gcnew WeifenLuo::WinFormsUI::Docking::DockPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->断线ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->棋谱复盘ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// dockPanel1
			// 
			this->dockPanel1->ActiveAutoHideContent = nullptr;
			this->dockPanel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dockPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dockPanel1->DockBackColor = System::Drawing::SystemColors::Control;
			this->dockPanel1->Location = System::Drawing::Point(0, 28);
			this->dockPanel1->Name = L"dockPanel1";
			this->dockPanel1->Size = System::Drawing::Size(684, 423);
			dockPanelGradient1->EndColor = System::Drawing::SystemColors::ControlLight;
			dockPanelGradient1->StartColor = System::Drawing::SystemColors::ControlLight;
			autoHideStripSkin1->DockStripGradient = dockPanelGradient1;
			tabGradient1->EndColor = System::Drawing::SystemColors::Control;
			tabGradient1->StartColor = System::Drawing::SystemColors::Control;
			tabGradient1->TextColor = System::Drawing::SystemColors::ControlDarkDark;
			autoHideStripSkin1->TabGradient = tabGradient1;
			dockPanelSkin1->AutoHideStripSkin = autoHideStripSkin1;
			tabGradient2->EndColor = System::Drawing::SystemColors::ControlLightLight;
			tabGradient2->StartColor = System::Drawing::SystemColors::ControlLightLight;
			tabGradient2->TextColor = System::Drawing::SystemColors::ControlText;
			dockPaneStripGradient1->ActiveTabGradient = tabGradient2;
			dockPanelGradient2->EndColor = System::Drawing::SystemColors::Control;
			dockPanelGradient2->StartColor = System::Drawing::SystemColors::Control;
			dockPaneStripGradient1->DockStripGradient = dockPanelGradient2;
			tabGradient3->EndColor = System::Drawing::SystemColors::ControlLight;
			tabGradient3->StartColor = System::Drawing::SystemColors::ControlLight;
			tabGradient3->TextColor = System::Drawing::SystemColors::ControlText;
			dockPaneStripGradient1->InactiveTabGradient = tabGradient3;
			dockPaneStripSkin1->DocumentGradient = dockPaneStripGradient1;
			tabGradient4->EndColor = System::Drawing::SystemColors::ActiveCaption;
			tabGradient4->LinearGradientMode = System::Drawing::Drawing2D::LinearGradientMode::Vertical;
			tabGradient4->StartColor = System::Drawing::SystemColors::GradientActiveCaption;
			tabGradient4->TextColor = System::Drawing::SystemColors::ActiveCaptionText;
			dockPaneStripToolWindowGradient1->ActiveCaptionGradient = tabGradient4;
			tabGradient5->EndColor = System::Drawing::SystemColors::Control;
			tabGradient5->StartColor = System::Drawing::SystemColors::Control;
			tabGradient5->TextColor = System::Drawing::SystemColors::ControlText;
			dockPaneStripToolWindowGradient1->ActiveTabGradient = tabGradient5;
			dockPanelGradient3->EndColor = System::Drawing::SystemColors::ControlLight;
			dockPanelGradient3->StartColor = System::Drawing::SystemColors::ControlLight;
			dockPaneStripToolWindowGradient1->DockStripGradient = dockPanelGradient3;
			tabGradient6->EndColor = System::Drawing::SystemColors::GradientInactiveCaption;
			tabGradient6->LinearGradientMode = System::Drawing::Drawing2D::LinearGradientMode::Vertical;
			tabGradient6->StartColor = System::Drawing::SystemColors::GradientInactiveCaption;
			tabGradient6->TextColor = System::Drawing::SystemColors::ControlText;
			dockPaneStripToolWindowGradient1->InactiveCaptionGradient = tabGradient6;
			tabGradient7->EndColor = System::Drawing::Color::Transparent;
			tabGradient7->StartColor = System::Drawing::Color::Transparent;
			tabGradient7->TextColor = System::Drawing::SystemColors::ControlDarkDark;
			dockPaneStripToolWindowGradient1->InactiveTabGradient = tabGradient7;
			dockPaneStripSkin1->ToolWindowGradient = dockPaneStripToolWindowGradient1;
			dockPanelSkin1->DockPaneStripSkin = dockPaneStripSkin1;
			this->dockPanel1->Skin = dockPanelSkin1;
			this->dockPanel1->TabIndex = 0;
			this->dockPanel1->ActiveContentChanged += gcnew System::EventHandler(this, &主界面::dockPanel1_ActiveContentChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->断线ToolStripMenuItem,
					this->棋谱复盘ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 28);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 断线ToolStripMenuItem
			// 
			this->断线ToolStripMenuItem->Name = L"断线ToolStripMenuItem";
			this->断线ToolStripMenuItem->Size = System::Drawing::Size(51, 24);
			this->断线ToolStripMenuItem->Text = L"断线";
			this->断线ToolStripMenuItem->Click += gcnew System::EventHandler(this, &主界面::断线ToolStripMenuItem_Click);
			// 
			// 棋谱复盘ToolStripMenuItem
			// 
			this->棋谱复盘ToolStripMenuItem->Name = L"棋谱复盘ToolStripMenuItem";
			this->棋谱复盘ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->棋谱复盘ToolStripMenuItem->Text = L"棋谱复盘";
			this->棋谱复盘ToolStripMenuItem->Click += gcnew System::EventHandler(this, &主界面::棋谱复盘ToolStripMenuItem_Click);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(355, -5);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(250, 33);
			this->axWindowsMediaPlayer1->TabIndex = 4;
			// 
			// 主界面
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 451);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->dockPanel1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"主界面";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"主界面";
			this->Load += gcnew System::EventHandler(this, &主界面::主界面_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void 主界面_Load(System::Object^  sender, System::EventArgs^  e) {
			登入Wnd->Show(this->dockPanel1);
			游戏房间Wnd->Show(this->dockPanel1);
			日志Wnd->Show(this->dockPanel1);
		CheckForIllegalCrossThreadCalls = false;
	}
			 bool IsFormOpened(String^ Name) { //判断窗体是不是已经打开

				 for each(IDockContent^ content in dockPanel1->Contents)
				 {
					 if (content->DockHandler->TabText == Name)
					 {
						 //content.DockHandler.Activate();
						 //
						 //rBool = true;
						 content->DockHandler->Activate();
						 return true;
						 break;
					 }
				 }
				 return false;
			 }
			public: 登入 ^登入Wnd = gcnew 登入();
			public: 游戏房间 ^游戏房间Wnd = gcnew 游戏房间();
			public: 日志 ^日志Wnd = gcnew 日志();

					void Show象棋游戏() {
						Global::象棋游戏Wnd = gcnew 象棋游戏(axWindowsMediaPlayer1);
						Thread^t = gcnew Thread(gcnew ThreadStart(this, &主界面::_Show象棋游戏));
						t->Start();
					}
					void _Show象棋游戏() {
						Global::象棋游戏Wnd->Visible = false;
						Global::象棋游戏Wnd->ShowDialog();
						Global::象棋游戏Wnd = nullptr;
					}
					void Log(String ^in) {
						日志Wnd->log(in);
					}
	private: System::Void 登入ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	}

private: System::Void 游戏房间ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void 日志ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void 断线ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	CliClose();
}
		 棋谱复盘^ 棋谱复盘Wnd;
private: System::Void 棋谱复盘ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!IsFormOpened("棋谱复盘")) {
		棋谱复盘^ 棋谱复盘Wnd = gcnew 棋谱复盘;
		this->Size = 棋谱复盘Wnd->Size + Drawing::Size(100, 100);
		棋谱复盘Wnd->Show(this->dockPanel1);
	}
}
private: System::Void dockPanel1_ActiveContentChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
