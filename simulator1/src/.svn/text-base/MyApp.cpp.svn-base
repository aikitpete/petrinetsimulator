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
	char* rules = (char *)malloc(strlen(RULES_PATH) + 1 * sizeof(char));
	if(rules == NULL){
		fprintf(stderr, "Could not allocate memory for strcpy.\n");
		return false;
	}
	strcpy(rules, RULES_PATH);
	FuzzyLogicDSL::Init(rules);

    //4.Show screen
    Screen->Update(OpenState);
    
    return true;

}