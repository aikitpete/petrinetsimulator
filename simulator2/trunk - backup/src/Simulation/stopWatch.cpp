#include "stopWatch.h"

stopWatch::stopWatch() {
	diffTime = 0.0;
	running = false;
	QueryPerformanceFrequency((LARGE_INTEGER*)&tick);
}

stopWatch::~stopWatch() {

}

void stopWatch::start() {
	if (!running) {
		markTime();
		running = true;
	}
}

void stopWatch::stop() {
	if (running) {
		diffTime = getTime();
		running = false;
	}
}

double stopWatch::elapsedTime() {
	if (running) return (getTime());
	else return (diffTime);
}

void stopWatch::markTime() {
	QueryPerformanceCounter((LARGE_INTEGER*)&t1);
}

double stopWatch::getTime() {
	QueryPerformanceCounter(&t2);
	return ((t2.QuadPart-t1.QuadPart)/(double) tick.QuadPart);
}