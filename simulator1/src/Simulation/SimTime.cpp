/* 
 * File:   Timer.cpp
 * Author: peter
 * 
 * Created on March 12, 2012, 12:44 PM
 */

#include "SimTime.h"

using namespace std;

SimTime::SimTime() {
    tagArrival();
}

SimTime::SimTime(const SimTime& orig) {
}

SimTime::~SimTime() {
}

/**
 * Marks end time
 */
void SimTime::tagDeparture() {
    
	
	//struct timeval departure;
    //gettimeofday(&departure, NULL);
    //departureTime = departure.tv_sec + departure.tv_usec / 1000000.0;
}

/**
 * Marks start time
 */
void SimTime::tagArrival() {
    
	
	//struct timeval arrival;
    //gettimeofday(&arrival, NULL);
    //arrivalTime = arrival.tv_sec + arrival.tv_usec / 1000000.0;
}

double SimTime::getTime() {
    
	return -1;

	//tagDeparture();
    //cout << "SimTime: " << departureTime - arrivalTime << endl;
    //return departureTime - arrivalTime;
}