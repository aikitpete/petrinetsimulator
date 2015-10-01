/* 
* File:   engine.cpp
* Author: peter
* 
* Created on February 24, 2012, 3:14 AM
*/

#include "SimulationManager.h"

void sim::Init() {

	sta::Init();
	gm::Init();

	setStarted(false);
	setPaused(false);

}

void sim::Start() {

	setStarted(true);

	sta::Start();

	//Generators are started
	gm::resumeAll();

	pthread_t* thread = new pthread_t;

	ThreadParameters* par = new ThreadParameters();

	pthread_create(thread, NULL, simulate, (void*) par);
	
}

void sim::Stop() {

	if (!isStarted()) {
		return;
	}

	//Generators are stopped
	gm::stopAll();
	sta::Stop();

	setStarted(false);

	cout << "PetriNet timeVal: " << sta::getTotalTime() << endl;
    cout << "PetriNet averageTPS " << sta::getAverageTPS() << endl; //test
      
}

void sim::Free() {
	sta::Free();
	gm::Free();
}

void *sim::simulate(void *ptr) {
	
	do {
		Sleep(CHECK_TIME);
	} while (sta::getTotalTime() < TIMEOUT && !isPaused());

	MainScreen::Instance()->Update(StoppedState);

	pthread_exit(0);

	return ptr;
}

void sim::setStarted(bool value) {
	started = value;
}

void sim::setPaused(bool value) {
	paused = value;
}

bool sim::isStarted() {
	return started;
}

bool sim::isPaused() {
	return paused;
}

