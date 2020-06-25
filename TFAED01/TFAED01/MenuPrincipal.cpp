#include "MenuPrincipal.h"
using namespace TFAED01;
[STAThreadAttribute]
int main(array<System::String^> ^args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew TFAED01::MenuPrincipal);
	return 0;
}
