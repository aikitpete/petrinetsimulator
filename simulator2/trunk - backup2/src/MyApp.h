#define CONSOLE

#define RULES_PATH "../trunk/Resources/Rules/rules3.rul"

#ifndef MYAPP_H
#define MYAPP_H

#include <wx\wx.h>

#include "PetriNet/PNFactory.h"
#include "PetriNet/PetriNetManager.h"
#include "Utils/Observer.h"
#include "Simulation/Logger.h"
#include "FuzzyRouting/Fuzzy.h"
#include "UI/MainScreen.h"

class MyApp : public wxApp {
public:
    static Observer* Instance();
    bool OnInit();

    static Observer* Screen;
};

#endif