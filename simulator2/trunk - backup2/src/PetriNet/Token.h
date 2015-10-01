/* 
 * File:   token.h
 * Author: peter
 *
 * Created on February 24, 2012, 5:04 AM
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <pthread.h>
#include <iostream>

#include "../Simulation/StopWatch.h"
//#include "SimTime.h"
#include "../Simulation/Generator.h"

using namespace std;

class Token {
public:
    Token();
    virtual ~Token();

    int getID();
	double getTime();

	//Fuzzy values
	double distance;
	double approaching;
    double speed;

private:
    int tokenID;

    double arrivalTime;
    double departureTime;
    
	stopWatch* watch;
    //SimTime* time;

    static int currentTID;

    int getNewID();

    void setID(int value) {
        tokenID = value;
    }
};

#endif