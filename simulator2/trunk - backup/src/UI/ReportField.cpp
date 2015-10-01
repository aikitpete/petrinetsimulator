/* 
 * File:   ReportField.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 8:46 PM
 */

#include "ReportField.h"

ReportField::ReportField(wxWindow* parent, const wxString& text, const wxString& value, wxSize size)
: wxBoxSizer(wxHORIZONTAL) {

    wxStaticText *staticText1 = new wxStaticText(parent, wxID_ANY, text, wxPoint(-1, -1), wxSize(size.GetWidth() - 50, size.GetHeight()));

    wxStaticText *staticText2 = new wxStaticText(parent, wxID_ANY, value, wxPoint(-1, -1), wxSize(size.GetWidth() - 50, size.GetHeight()));

    this->Add(staticText1);
    this->Add(staticText2);

}

ReportField::~ReportField() {
}

int ReportField::GetValue() {
    wxString value = textCtrl->GetValue();
    return wxAtoi(value);

}

void ReportField::SetValue(const wxString& value) {
    //wxString strValue;
    //strValue = value;
    //textCtrl->SetValue(value);

}