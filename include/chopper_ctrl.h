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

#ifndef CHOPPER_CTRL_H
#define CHOPPER_CTRL_H

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/intl.h>
#include "chopper.h"

#ifndef APP_CATALOG
#define APP_CATALOG "app"  // replace with the appropriate catalog name
#endif


// begin wxGlade: ::dependencies
#include <wx/tglbtn.h>
// end wxGlade

// begin wxGlade: ::extracode
// end wxGlade


class MyFrame: public wxFrame {
public:
    // begin wxGlade: MyFrame::ids
    // end wxGlade

    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    // begin wxGlade: MyFrame::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: MyFrame::attributes
    wxToggleButton* button_1;
    wxToggleButton* button_2;
    // end wxGlade

	// Need chopper.h and libtbi.lib in ToolbitSDK
	Chopper* chopper;
	
    DECLARE_EVENT_TABLE();

public:
    void ToggleButton(wxCommandEvent &event); // wxGlade: <event_handler>
	void OnIdle(wxIdleEvent& event);
}; // wxGlade: end class


#endif // CHOPPER_CTRL_H