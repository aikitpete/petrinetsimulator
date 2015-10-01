/* 
 * File:   Handler.h
 * Author: peter
 *
 * Created on February 26, 2012, 10:41 PM
 */

#ifndef LOGGER_H
#define	LOGGER_H

//#if !defined(__CYGWIN32__)
#include <sstream>
//#endif

#include <iostream>//TODO extend ostream
#include <string>

#include "../UI/MainScreen.h"
#include "../PetriNet/ObjectType.h"
#include "LogType.h"
#include "EventType.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

namespace logger {   

//public:
    void init();

    void logEvent(EventType type);
    void logEvent(ObjectType type, int id);

#ifdef T_EVENT

    void logEvent(ObjectType type, int id, int tokens);
    void logEvent(ObjectType type, int id, int tokens, int tid);

#endif

    void logEvent(ObjectType type, int id, LogType ltype);

//private:
    void log(std::string message);
    char determineType(ObjectType type);
    std::string determineLType(LogType ltype);
    
    static MainScreen *screen;     //TODO use singleton

};

#endif
