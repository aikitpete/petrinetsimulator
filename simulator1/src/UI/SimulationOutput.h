/* 
 * File:   simulationoutput.h
 * Author: peter
 *
 * Created on February 24, 2012, 4:43 AM
 */

#ifndef SIMULATIONOUTPUT_H
#define SIMULATIONOUTPUT_H

#include <wx/wx.h>

class SimulationOutput : public wxTextCtrl {
public:
    SimulationOutput(wxWindow* parent, wxWindowID id, \
        const wxPoint& pos, const wxSize& size);
    virtual ~SimulationOutput();
    
    void AppendText(wxString& message);
private:
    
};

#endif

