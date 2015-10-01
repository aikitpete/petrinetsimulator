#include "MainScreen.h"
#include "../PetriNet/PetriNetManager.h" // TODO remove

//#define W_WIDTH = 640
//#define W_HEIGHT = 480
//#define W_TITLE = 'wxT("EFTSwitchSim")'

BEGIN_EVENT_TABLE(MainScreen, wxFrame)
EVT_BUTTON(1, MainScreen::OnStart)
EVT_BUTTON(2, MainScreen::OnStop)
EVT_BUTTON(3, MainScreen::OnReset)
EVT_BUTTON(wxID_EXIT, MainScreen::OnQuit)
END_EVENT_TABLE()

MainScreen* MainScreen::instance;

MainScreen* MainScreen::Instance() {
    if (!instance) {
        instance = new MainScreen(wxT("EFTSwitchSim"), wxSize(640, 480));
        instance->Update(InitState);
    }
    assert(instance != NULL);
    return instance;
}

MainScreen::MainScreen(const wxString &name, const wxSize &size)
: wxFrame(NULL, wxID_ANY, name, wxDefaultPosition, size) {
	
    SetMinSize(GetSize());
    SetMaxSize(GetSize());

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    control = new Control(this, wxSize(GetScreenWidth() / 2, 30));

    report = new Report(this, wxSize(GetScreenWidth() / 2, 30));

    buttons = new Buttons(this, wxSize(GetScreenWidth() / 2, 30));

    simulationOutput = new SimulationOutput(this, wxID_ANY, wxPoint(-1, -1),
            wxSize(GetScreenWidth() / 2, GetScreenHeight()));

    vbox->Add(control);
    vbox->Add(buttons, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
    vbox->Add(report);

    hbox->Add(vbox, wxALIGN_RIGHT | wxEXPAND);
    hbox->Add(simulationOutput, wxEXPAND);

    this->SetSizer(hbox);


    //Menubar


    wxMenuBar *menubar = new wxMenuBar;
    wxMenu *file = new wxMenu;
    wxMenu *statistics = new wxMenu;

    menubar->Append(file, wxT("&File"));
    menubar->Append(statistics, wxT("&Statistics"));
    SetMenuBar(menubar);


    //Statusbar


    CreateStatusBar();

    Centre();
	
}

//MainScreen::~MainScreen() {
//
//}

void MainScreen::Display(std::string message) {
    wxString mystring(message.c_str(), wxConvUTF8);
    simulationOutput->AppendText(mystring);
}

void MainScreen::Clear() {
    simulationOutput->SetValue(wxT(""));
}

void MainScreen::Update(AppState state) {
    Observer::Update(state);
}

void MainScreen::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    instance->Update(ExitState);
}

void MainScreen::OnStart(wxCommandEvent& WXUNUSED(event)) {
    instance->Update(RunningState);
}

void MainScreen::OnStop(wxCommandEvent& WXUNUSED(event)) {
    instance->Update(StoppedState);
}

void MainScreen::OnReset(wxCommandEvent& WXUNUSED(event)) {
    instance->Update(ResetState);
}

void MainScreen::SwitchInit() {
    buttons->SwitchSButton(OpenState);
}

void MainScreen::SwitchOpen() {
    logger::logEvent(InitEvent);
	sim::Init();
    pn::Init();
    SetStatusText(_("Simulation stopped"));
    Show(true);
}

void MainScreen::SwitchRunning() {
    buttons->SwitchSButton(RunningState);  
    SetStatusText(_("Simulation started"));
    logger::logEvent(StartEvent);
    control->Enable(false);
    sim::Start();
    pn::update(ActiveState);
}

void MainScreen::SwitchStopped() {
	pn::update(InactiveState);
    sim::Stop();
    buttons->SwitchSButton(StoppedState);
    SetStatusText(_("Simulation stopped"));
    logger::logEvent(StopEvent);
}

void MainScreen::SwitchReset() {
    buttons->SwitchSButton(OpenState);
    pn::Free();
	sim::Free();
    instance->Update(OpenState);
}

void MainScreen::SwitchExit() {
    pn::Free();
	sim::Free();
    Close(true);
}