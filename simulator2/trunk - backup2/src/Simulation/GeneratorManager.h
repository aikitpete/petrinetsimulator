/* 
* File:   GeneratorManager.h
* Author: peter
*
* Created on February 25, 2012, 4:43 AM
*/

//TODO merge with PNFactory

#ifndef GENERATORMANAGER_H
#define	GENERATORMANAGER_H

#define GENERATOR_INTERVAL 0

#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <list>

#include "../PetriNet/Node.h"
#include "../PetriNet/Token.h"
#include "../PetriNet/PNFactory.h"
#include "Generator.h"

namespace gm {
	//public:
	void Init();
	void Free();
	void addNewGenerator(Node* node, int seed, int tps);

	//Fuzzy
	void *generate(void *);

	void stopAll();
	void pauseAll();
	void resumeAll();

	//private:
	bool isStopped();
	void setStopped(bool state);
	bool isPaused();
	void setPaused(bool state);

	static list<pthread_t*>* threadList;

	static bool stopped;
	static bool paused;

	static bool initialized;

	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	static pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

	//static int max;
	//static int current;

	struct ThreadParameters {

		Node* node;
		Generator* generator;

		ThreadParameters(Node* n, Generator* g) {
			node = n;
			generator = g;
		};

	};
};

#endif