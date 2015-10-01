/* 
 * File:   Buttons.h
 * Author: peter
 *
 * Created on February 24, 2012, 9:06 PM
 */

#ifndef BUTTONS_H
#define BUTTONS_H

#include <wx/wx.h>
#include "AppState.h"

class Buttons : public wxBoxSizer {
public:
    Buttons(wxWindow* parent, wxSize size);
    virtual ~Buttons();
    
    void SwitchSButton(AppState state);
    
private:   
    static wxButton* start;
    static wxButton* exit;
    static wxButton* reset;
};

#endif