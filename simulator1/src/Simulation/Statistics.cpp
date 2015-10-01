/* 
 * File:   statistics.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 5:04 AM
 */

#include "Statistics.h"

using namespace std;

void sta::Init() {
    times = new Times();
	watch = new stopWatch();
}

void sta::Start() {
    watch->start();
}

void sta::Stop() {
    //Time value is stored
	watch->stop();
    
}

void sta::Free() {
	delete watch;
    delete times;
}

/**
 * Gets the average number of transactions in system
 * @return average # of transactions
 */
double sta::getAverageTPS() {
    return times->getTotal() / watch->elapsedTime();
}

/**
 * Gets the average response time for a transaction
 * @return average response time
 */
long sta::getAverageRT() {
	return -1;
}

/**
 * Gets # of time outed transactions
 * @return total # of time outed transactions
 */
long sta::getTimeout() {
	return -1;
}

/**
 * Gets maximum # of transactions in system
 * @return maximum # of transactions
 */
long sta::getMaximum() {
	return -1;
}

/**
 * Gets total # of transactions
 * @return total of transactions
 */
long sta::getTotal() {
	return -1;
}

/**
 * Gets total # of transactions
 * @return total of transactions
 */
double sta::getTotalTime() {
	return watch->elapsedTime();
}

/**
 * Adds new transaction time record
 */
void sta::addTime(double time) {
    times->addTime(time);
	if (times->getTotal()==MAX_TOKENS) {
		sim::setPaused(true);
	}
}

/**
 * Checks if new maximum for # of transactions in system
 */
void sta::checkMaximum() {

}

