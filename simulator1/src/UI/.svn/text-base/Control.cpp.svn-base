/* 
 * File:   Report.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 8:30 AM
 */

#include "Control.h"

Control::Control(wxWindow* parent, wxSize size) : \
wxBoxSizer(wxVERTICAL)
{
    SetMinSize(size);
    
    wxStaticText *heading = new wxStaticText(parent, wxID_ANY, wxT("Configuration:"), wxPoint(-1, -1), size);
    
    ControlField *controlField1 = new ControlField(parent, wxT("Workload [1-5]:"), wxT("3"), size);
    ControlField *controlField2 = new ControlField(parent, wxT("Processing time [1-5]:"), wxT("3"), size);
    ControlField *controlField3 = new ControlField(parent, wxT("Response time [1-5]:"), wxT("3"), size);
    ControlField *controlField4 = new ControlField(parent, wxT("Message timeout [1-5]:"), wxT("3"), size);
    ControlField *controlField5 = new ControlField(parent, wxT("Routing alternative [1-3]:"), wxT("1"), size);

    Add(heading);
    
    Add(controlField1);
    Add(controlField2);
    Add(controlField3);
    Add(controlField4);
    Add(controlField5);
}



Control::~Control() {
}

int Control::GetValue() {
	return -1;
    //TODO
}

void Control::SetValue(const wxString& value) {
    //TODO
}

void Control::Enable(bool state) {
    //TODO
    /*
    wxSizerItemList& itemList = GetChildren();
    for (wxSizerItemList::iterator i = itemList.begin(); i != itemList.end(); ++i)
    {
        ControlField *controlField = wxStaticCast((*i)->GetWindow(), ControlField);
        controlField->Enable(state);
    }
     */
}

