#include "GeneratorManager.h"
#pragma warning (disable : 4700)

void gm::Init() {
	//TODO threads = new pthread_t[max];

	 if (initialized == false) {
        threadList = new list<pthread_t*>();
		initialized = true;
    }
   
	setStopped(false);
	setPaused(true);
}

void gm::Free() {
	initialized = false;

    threadList->clear();
    
    delete threadList;
}

void gm::addNewGenerator(Node* node, int seed, int tps) {

	pthread_t* thread = new pthread_t;
	
	Generator* generator = new Generator(seed, tps);

	ThreadParameters* par = new ThreadParameters(node, generator);

	pthread_create(thread, NULL, generate, (void *)par);//returns value

	threadList->push_front(thread);

}

void *gm::generate(void *ptr) {

	ThreadParameters* par = (ThreadParameters*) ptr;
	Node* node = par->node;
	Generator* generator = par->generator;

#ifndef SHORT_RUN
	do {
#else
	for(int i=0;i<10;i++) {
#endif

		Token* token = nf::createToken();//TODO improve generation

		//Fuzzy
		token->distance = generator->getValue(0,5);
		token->approaching = generator->getValue(0,50);
		token->speed = generator->getValue(-50,50);

		if (isPaused()) {
			
			pthread_mutex_lock(&mutex);
			pthread_cond_wait(&condition_var, &mutex);
			pthread_mutex_unlock(&mutex);

		}

		node->addToken(token);

#ifndef ONE_INTERARRIVAL
		Sleep(GENERATOR_INTERVAL);
#else
		Sleep(generator->getInterarrival());
#endif

#ifndef SHORT_RUN
	} while(!stopped);
#else
	}
#endif

	pthread_exit(0);

	return 0;
}

void gm::stopAll() {
	setStopped(true);
}

void gm::pauseAll() {
	setPaused(true);
}

void gm::resumeAll() {

	setPaused(false);

	pthread_mutex_lock(&mutex);
	pthread_cond_broadcast(&condition_var);
	pthread_mutex_unlock(&mutex);
}

bool gm::isStopped() {
	return stopped;
}
void gm::setStopped(bool state) {

	stopped = state;
}

bool gm::isPaused() {
	return paused;
}

void gm::setPaused(bool state) {
	paused = state;
}