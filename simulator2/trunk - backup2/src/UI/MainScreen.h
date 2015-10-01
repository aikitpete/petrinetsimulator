#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <wx\wx.h>
#include <string>

#include "../Utils/Observer.h"
#include "../Simulation/EventType.h"
#include "Buttons.h"
#include "SimulationOutput.h"
#include "AppState.h"
#include "Control.h"
#include "Report.h"

class MainScreen : public wxFrame, public Observer {
public:
    static MainScreen* Instance(); //TODO use singleton class  
    
	MainScreen(const wxString &name, const wxSize &size);
   
	
	void Display(std::string message);
    void Clear();
    void Update(AppState state);

    void OnInit(wxCommandEvent& event);
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnReset(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
	

private:
	
	void SwitchInit();
    void SwitchOpen();
    void SwitchRunning();
    void SwitchStopped();
    void SwitchReset();
    void SwitchExit();

    int GetScreenWidth() {
        return GetSize().GetWidth();
    };

    int GetScreenHeight() {
        return GetSize().GetHeight();
    };

    static MainScreen *instance;

    Control *control;
    Buttons *buttons;
    Report *report;
    SimulationOutput *simulationOutput;
	
    DECLARE_EVENT_TABLE();
};

#endif