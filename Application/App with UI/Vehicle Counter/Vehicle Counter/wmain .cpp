#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

void wmain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	VehicleCounter::Main form;
	Application::Run(%form);
}