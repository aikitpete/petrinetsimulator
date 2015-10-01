/* 
 * File:   Times.cpp
 * Author: peter
 * 
 * Created on March 12, 2012, 2:14 PM
 */

#include "Times.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//TODO expanding size

Times::Times() {
	sem_init(&times_semaphore, 0, 1);
    timesList = new list<double>();
}

Times::Times(const Times& orig) {
	
}

Times::~Times() {
    delete timesList;
}

void Times::addTime(double time) {
	/********** Critical Section *******************/
	sem_wait(&times_semaphore);
	timesList->push_front(time);
	sem_post(&times_semaphore);
}

long Times::getTotal() {
	long ret;

	/********** Critical Section *******************/
	sem_wait(&times_semaphore);
	ret = (long) timesList->size();
	sem_post(&times_semaphore);

    return ret;
};