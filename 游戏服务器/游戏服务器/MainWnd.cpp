#include "MainWnd.h"
#include "游戏服务器.h"

using namespace 游戏服务器;
using namespace System::Drawing;

[STAThreadAttribute]
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
void main() {
	ServOpen(20000);
	Application::Run(gcnew MainWnd());

}
