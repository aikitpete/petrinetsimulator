/* 
 * File:   Handler.cpp
 * Author: peter
 * 
 * Created on February 26, 2012, 10:41 PM
 */


#include "Logger.h"

void logger::init() { //TODO
    screen = MainScreen::Instance();
}

void logger::logEvent(EventType type) {
    stringstream ss;
    switch (type) {
        case InitEvent:
            logger::screen->Clear();
            ss << "Petri net initialized\n";
            break;
        case StartEvent:
            screen->Clear();
            ss << "Simulation started\n";
            break;
        case StopEvent:
            ss << "Simulation stopped\n";
            break;
    }
    string message = ss.str();
    logger::log(message);
}

void logger::logEvent(ObjectType type, int id) {
    stringstream ss;
    ss << "Create: " << logger::determineType(type) << id << "\n";
    string message = ss.str();
    logger::log(message);
}

#ifdef T_EVENT

void logger::logEvent(ObjectType type, int id, int tokens) {
    stringstream ss;
    ss << "Token: " << logger::determineType(type) << id << " " << tokens << "\n";
    string message = ss.str();
    logger::log(message);
}

void logger::logEvent(ObjectType type, int id, int tokens, int tid) {
    stringstream ss;
    ss << "Token: " << logger::determineType(type) << id << " " << tokens << " tokens\n";
    string message = ss.str();
    logger::log(message);
}

#endif

#ifdef P_EVENT

void logger::logEvent(ObjectType type, int id, LogType ltype) {
    stringstream ss;
    ss << "Process: " << logger::determineType(type) << id << " " << logger::determineLType(ltype) << "\n";
    string message = ss.str();
    logger::log(message);
}

#endif

void logger::log(string message) {
    logger::screen->Display(message);
    
#ifdef CONSOLE
    cout << message;
#endif
    
}

char logger::determineType(ObjectType type) {
    switch (type) {
	case TransitionObjectType:
            return 'T';
	case PlaceObjectType:
            return 'P';
    default:
            throw "Unrecognized node";
    }
}

std::string logger::determineLType(LogType ltype) {
    switch (ltype) {
        case ProcessingStart:
            return "started";
        case ProcessingEnd:
            return "stopped";
        default:
            throw "Unrecognized event";
            //return 'U';
    }
}
