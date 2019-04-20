#include "MyForm.h"
#include"library.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Xml;




[STAThread]
void main(array<String^>^args)
{
	library^read=gcnew library();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	oopproject2::MyForm form(read);
	Application::Run(%form);
	
}

