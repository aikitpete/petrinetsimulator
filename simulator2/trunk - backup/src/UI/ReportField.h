/* 
 * File:   ReportField.h
 * Author: peter
 *
 * Created on February 24, 2012, 8:46 PM
 */

#ifndef REPORTFIELD
#define REPORTFIELD

#include <wx/wx.h>

class ReportField : public wxBoxSizer {
public:
    ReportField(wxWindow* parent, const wxString& text, const wxString& value, wxSize size);
    virtual ~ReportField();
    int GetValue();
    void SetValue(const wxString& value);
    
private:
    wxTextCtrl *textCtrl;
    
    int defaultValue;
    int value;
};

#endif