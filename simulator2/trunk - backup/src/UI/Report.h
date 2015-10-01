/* 
 * File:   Report.h
 * Author: peter
 *
 * Created on February 24, 2012, 8:30 AM
 */

#ifndef REPORT_H
#define REPORT_H

#include <wx/wx.h>

#include "ReportField.h"

class Report  : public wxBoxSizer {
public:
    Report(wxWindow* parent, wxSize size);
    virtual ~Report();
    int GetValue();
    void SetValue(const wxString& value);
    
    static ReportField *reportField1;
    static ReportField *reportField2;
    static ReportField *reportField3;
    static ReportField *reportField4;
    static ReportField *reportField5;
    static ReportField *reportField6;
    
private:

};

#endif
