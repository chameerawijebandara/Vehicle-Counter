#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int CALLBACK WinMain(
  _In_ HINSTANCE hInstance,
  _In_ HINSTANCE hPrevInstance,
  _In_ LPSTR     lpCmdLine,
  _In_ int       nCmdShow
)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	VehicleCounter::Main form;
	Application::Run(%form);
}