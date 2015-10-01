/* 
 * File:   control.h
 * Author: peter
 *
 * Created on February 24, 2012, 5:09 AM
 */

#ifndef CONTROLFIELD_H
#define CONTROLFIELD_H

#include <wx/wx.h>

class ControlField : public wxBoxSizer {
public:
    ControlField(wxWindow* parent, const wxString& text, const wxString& value, wxSize size);
    virtual ~ControlField();
    int GetValue();
    void SetValue(const wxString& value);
    void Enable(bool state);
    
private:
    wxTextCtrl *textCtrl;
    
    int defaultValue;
    int value;
};

#endif
