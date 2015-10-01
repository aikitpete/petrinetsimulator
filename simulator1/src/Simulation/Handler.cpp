/* 
 * File:   Handler.cpp
 * Author: peter
 * 
 * Created on February 29, 2012, 6:11 AM
 */

#include "Handler.h"

Handler::Handler(){
    
}

Handler::~Handler() {
    delete instance;
}

Handler* Handler::getInstance() {
    if (!instance) {
        instance = new Handler();
    }
    return instance;
}