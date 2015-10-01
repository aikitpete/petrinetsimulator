/* 
 * File:   Report.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 8:30 AM
 */

#include "Report.h"

ReportField* Report::reportField1;
ReportField* Report::reportField2;
ReportField* Report::reportField3;
ReportField* Report::reportField4;
ReportField* Report::reportField5;
ReportField* Report::reportField6;

Report::Report(wxWindow* parent, wxSize size) : \
wxBoxSizer(wxVERTICAL) {
    SetMinSize(size);

    wxStaticText *heading = new wxStaticText(parent, wxID_ANY, wxT("Statistics:"), wxPoint(-1, -1), size);

    reportField1 = new ReportField(parent, wxT("Simulation time:"), wxT("0"), size);
    reportField2 = new ReportField(parent, wxT("Average TPS:"), wxT("0"), size);
    reportField3 = new ReportField(parent, wxT("Average response time:"), wxT("0"), size);
    reportField4 = new ReportField(parent, wxT("Message timeouts:"), wxT("0"), size);
    reportField5 = new ReportField(parent, wxT("Maximum TPS:"), wxT("0"), size);
    reportField6 = new ReportField(parent, wxT("Total transactions:"), wxT("0"), size);

    Add(heading);

    Add(reportField1);
    Add(reportField2);
    Add(reportField3);
    Add(reportField4);
    Add(reportField5);
    Add(reportField6);
}

Report::~Report() {
}

int Report::GetValue() {

	return -1;
    //TODO
}

void Report::SetValue(const wxString& value) {
    //TODO
}

