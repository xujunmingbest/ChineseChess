#include <windows.h>
#include "������.h"
#include "��������.h"


using namespace �й������һ��;

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
	Application::Run(gcnew ������());
}
