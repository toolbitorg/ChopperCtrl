// -*- C++ -*-
//
// generated by wxGlade 0.7.2 on Sat Dec 03 20:17:52 2016
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include "chopper_ctrl.h"

// begin wxGlade: ::extracode
// end wxGlade



MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxCAPTION|wxCLOSE_BOX)
{
    // begin wxGlade: MyFrame::MyFrame
    button_1 = new wxToggleButton(this, wxID_ANY, _("Port1"));
    button_2 = new wxToggleButton(this, wxID_ANY, _("Port2"));

    set_properties();
    do_layout();
    // end wxGlade

	chopper = new Chopper();
	if (!chopper->isConnected()) {
		button_1->Disable();
		button_2->Disable();
	}
	else {
		// Set current ports status to toggle buttons
		uint32_t port = chopper->getUsbPortStatus();
		button_1->SetValue(port & 0x01);
		button_2->SetValue(port & 0x02);
#ifdef __linux__
		if(port & 0x01)
			button_1->SetBackgroundColour(wxColour(wxT("SKY BLUE")));
		else
			button_1->SetBackgroundColour(wxColour(wxT("WHITE")));
		if (port & 0x02)
			button_2->SetBackgroundColour(wxColour(wxT("SKY BLUE")));
		else
			button_2->SetBackgroundColour(wxColour(wxT("WHITE")));
#endif
	}
}


MyFrame::~MyFrame()
{
	delete chopper;
}


void MyFrame::set_properties()
{
    // begin wxGlade: MyFrame::set_properties
	SetTitle(_("Chopper Ctrl"));
	// end wxGlade
}


void MyFrame::do_layout()
{
    // begin wxGlade: MyFrame::do_layout
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxGridSizer* grid_sizer_1 = new wxGridSizer(1, 2, 0, 0);
    grid_sizer_1->Add(button_1, 0, 0, 0);
    grid_sizer_1->Add(button_2, 0, 0, 0);
    sizer_1->Add(grid_sizer_1, 1, 0, 0);
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    Layout();
    // end wxGlade
}


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    // begin wxGlade: MyFrame::event_table
    EVT_TOGGLEBUTTON(wxID_ANY, MyFrame::ToggleButton)
    // end wxGlade
	EVT_IDLE(MyFrame::OnIdle)
END_EVENT_TABLE();


void MyFrame::ToggleButton(wxCommandEvent &event)
{
	if (button_1->GetValue()) {
		chopper->enableUsbPort(1);
#ifdef __linux__
		button_1->SetBackgroundColour(wxColour(wxT("SKY BLUE")));
#endif
	}
	else {
		chopper->disableUsbPort(1);
#ifdef __linux__
		button_1->SetBackgroundColour(wxColour(wxT("WHITE")));
#endif
	}
	if (button_2->GetValue()) {
		chopper->enableUsbPort(2);
#ifdef __linux__
		button_2->SetBackgroundColour(wxColour(wxT("SKY BLUE")));
#endif
	}
	else {
		chopper->disableUsbPort(2);
#ifdef __linux__
		button_2->SetBackgroundColour(wxColour(wxT("WHITE")));
#endif
	}

    event.Skip();
}

void MyFrame::OnIdle(wxIdleEvent& event)
{
	if (!chopper->isConnected()) {
		delete chopper;
		chopper = new Chopper();

		if (!chopper->isConnected())
		{
			button_1->Disable();
			button_2->Disable();
		}
		else {
			// Set current ports status to toggle buttons
			uint32_t port = chopper->getUsbPortStatus();
			button_1->SetValue(port & 0x01);
			button_2->SetValue(port & 0x02);
			button_1->Enable();
			button_2->Enable();
		}
	}
}

// wxGlade: add MyFrame event handlers

