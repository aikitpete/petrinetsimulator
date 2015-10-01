/* 
 * File:   Timer.h
 * Author: peter
 *
 * Created on March 12, 2012, 12:44 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include <iostream>

#if defined(WIN64)
	#include "time.h"
#elif defined(WIN32)
	#include "time.h"
#elif defined(UNIX)
	#include "time.h"
	#include "sys/time.h"
#endif

//TODO change to timer
class SimTime {
public:
    SimTime();
    SimTime(const SimTime& orig);
    virtual ~SimTime();

    double getTime();

private:
    void tagArrival();
    void tagDeparture();

    double arrivalTime;
    double departureTime;
};

#endif	/* TIMER_H */

