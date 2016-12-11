
#include "main.h"
#include "chopper_ctrl.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	MyFrame *myframe = new MyFrame(NULL, wxID_ANY, wxString("Chopper Ctrl"));
	myframe->Show(true);

	return true;
}



