/* 
 * File:   Buttons.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 9:06 PM
 */

#include "Buttons.h"

wxButton* Buttons::start;
wxButton* Buttons::exit;
wxButton* Buttons::reset;

Buttons::Buttons(wxWindow* parent, wxSize size) : \
wxBoxSizer(wxHORIZONTAL) {

    start = new wxButton(parent, 1, wxT("Start"));
    reset = new wxButton(parent, 3, wxT("Reset"));
    exit = new wxButton(parent, wxID_EXIT, wxT("Quit"));

    Add(start, wxALIGN_CENTER | wxEXPAND);
    Add(reset, wxALIGN_CENTER | wxEXPAND);
    Add(exit, wxALIGN_CENTER | wxEXPAND);
}

Buttons::~Buttons() {
    delete start;
    delete exit;
    delete reset;
}

void Buttons::SwitchSButton(AppState state) {
    switch (state) {
        case OpenState:
            start->SetLabel(wxT("Start"));
            start->SetId(1);
            start->Enable(true);
            reset->Enable(false);
            break;
        case StoppedState:
            start->SetLabel(wxT("Start"));
            start->SetId(1);
            start->Enable(false);
            reset->Enable(true);
            break;
        case RunningState:
            start->SetLabel(wxT("Stop"));
            start->SetId(2);
            start->Enable(true);
            reset->Enable(false);
            break;
        default:
            throw "Unrecognized button state";
    }
}