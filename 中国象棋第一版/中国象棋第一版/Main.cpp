#include <windows.h>
#include "主界面.h"
#include "联网下棋.h"


using namespace 中国象棋第一版;

void SystemStart() {
	Directory::CreateDirectory(gcnew String(HEADSAVEPATH));
	Directory::CreateDirectory(gcnew String(MANUALSAVEPATH));
}

[STAThreadAttribute]
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//void main() {
	
	SystemStart();
	CliOpen(SERVERIP, "20000");
	OpenMasterControl();
	Application::Run(gcnew 主界面());
}
