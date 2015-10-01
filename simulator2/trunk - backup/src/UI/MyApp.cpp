#include "MyApp.h"

IMPLEMENT_APP(MyApp)
        
Observer* MyApp::Screen;

/**
 * Initialize modules
 * @return success
 */
bool MyApp::OnInit() {	
    //1.Initialize main screen

    //TODO singleton
    Screen = MainScreen::Instance();

    //2.Initialize logger
    logger::init();
    
	//3.Initialize fuzzy
	FuzzyLogicDSL::Init(RULES_PATH);

    //4.Show screen
    Screen->Update(OpenState);
    
    return true;

}