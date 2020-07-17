#include "pch.h"
#include "MyForm.h"
#include <Windows.h>

using namespace OpenMKS;


[STAThreadAttribute]
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	AllocConsole();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::Run(gcnew MyForm());
}