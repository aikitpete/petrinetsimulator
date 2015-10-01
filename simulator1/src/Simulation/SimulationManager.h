/* 
 * File:   engine.h
 * Author: peter
 *
 * Created on February 24, 2012, 3:14 AM
 */

#ifndef SIMULATIONMANAGER_H
#define	SIMULATIONMANAGER_H

#define TIMEOUT 5
#define MAX_TOKENS 10
#define CHECK_TIME 5

#include <pthread.h>

#include "Statistics.h"

namespace sim {
//public:   
	void Init();
    void Start();
    void Stop();
	void Free();

	void *simulate(void *ptr);

	void setStarted(bool value);
	void setPaused(bool value);

	bool isStarted();
	bool isPaused();

//private:
    static bool started;
    static bool paused;
};

	struct ThreadParameters {

		ThreadParameters() {

		};

	};

#endif