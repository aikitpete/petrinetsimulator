/* 
* File:   Generator.h
* Author: peter
*
* Created on February 25, 2012, 4:43 AM
*/

#ifndef GENERATOR_H
#define	GENERATOR_H

#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>

class Generator {

public:
	Generator(int seed, int tps);
	~Generator();

	//Fuzzy
	double getValue(int min, int max);
	double getDistance(int min, int max);
	double getApproaching(int min, int max);
	double getSpeed(int min, int max);

	int getInterarrival();

private:
	void setRandom(int seed);
	int interarrival;
};

#endif

