#include "MainWnd.h"
#include "��Ϸ������.h"

using namespace ��Ϸ������;
using namespace System::Drawing;

[STAThreadAttribute]
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
void main() {
	ServOpen(20000);
	Application::Run(gcnew MainWnd());

}
