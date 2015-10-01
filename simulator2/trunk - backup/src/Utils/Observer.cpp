/* 
 * File:   ModuleFactory.cpp
 * Author: peter
 * 
 * Created on March 5, 2012, 2:34 PM
 */

#include "Observer.h"

void Observer::Update(AppState newState) {

    switch (newState) {
        case InitState:
            SwitchInit();
            break;
        case ResetState:
            SwitchReset();
            break;
        case OpenState:
            SwitchOpen();
            break;
        case RunningState:
            SwitchRunning();
            break;
        case StoppedState:
            SwitchStopped();
            break;
        case ExitState:
            SwitchExit();
            break;
        default:
            throw "Unknown screen state";
    }
}
