/* 
 * File:   control.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 5:09 AM
 */

#include "ControlField.h"

ControlField::ControlField(wxWindow* parent, const wxString& text, const wxString& value, wxSize size)
: wxBoxSizer(wxHORIZONTAL) {

    wxStaticText *staticText = new wxStaticText(parent, wxID_ANY, text, wxPoint(-1, -1), wxSize(size.GetWidth()-50, size.GetHeight()));

    textCtrl = new wxTextCtrl(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(50, size.GetHeight()), wxTE_CENTER);

    this->Add(staticText);
    this->Add(textCtrl);
}

ControlField::~ControlField() {
}

int ControlField::GetValue() {
    //TODO
    
    wxString value = textCtrl->GetValue();
    return wxAtoi(value);

}

void ControlField::SetValue(const wxString& value) {
    //TODO
    
    //wxString strValue;
    //strValue = value;
    //textCtrl->SetValue(value);

}

void ControlField::Enable(bool state) {
    textCtrl->Enable(state);
}




