/* 
 * File:   Generator.cpp
 * Author: peter
 * 
 * Created on February 25, 2012, 4:43 AM
 */

#include "Generator.h"

Generator::Generator(int seed, int tps) {
	setRandom(seed);
	interarrival = 1000 / tps;
}

Generator::~Generator() {

}

void Generator::setRandom(int seed) {
	srand(seed);
}

double Generator::getValue(int min, int max) {
	return (rand() / double(RAND_MAX)) * (max-min) + min;
}

double Generator::getDistance(int min, int max) {
	return (rand() / double(RAND_MAX)) * (max-min) + min;
}

double Generator::getSpeed(int min, int max) {
	return (rand() / double(RAND_MAX)) * (max-min) + min;
}

double Generator::getApproaching(int min, int max) {
	return (rand() / double(RAND_MAX)) * (max-min) + min;
}

int Generator::getInterarrival() {
	return interarrival;
}