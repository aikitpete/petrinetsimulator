/* 
* File:   transition.cpp
* Author: peter
* 
* Created on February 24, 2012, 5:04 AM
*/

#include "Transition.h"

int Transition::currentID = 1;

Transition::Transition() : Node() {
	Node::dispatchCreateEvent();

}

void Transition::setStopped(bool value) {
	stopped = value;
	if (!Transition::isStopped()) {
		pthread_t* thread = new pthread_t;
		pthread_create(thread, NULL, process, (void*)this);//returns value
		//threadList->push_front(thread);
	}
}

Transition::Transition(string name, ProcessingType type) : Node(name, type) {
	Node::setProcessingType(type);
	int value = getNewID();
	Node::setID(value);
	Node::dispatchCreateEvent();
}

Transition::~Transition() {

}

/*
int Transition::addToken(Token* token) {
	int ret = Node::addToken(token);
	//
	if (Node::getShortage()) {
		Node::setShortage(false);        
	}
	//
	//process();

	return ret;
}
*/

Token* Transition::getToken() {
	Node* n;
	n = *inputList.begin();//TODO store

	Token* t = n->getToken();
	return t;

}

void Transition::setState(NodeState newState) {
	Node::setState(newState);

	if (newState == ActiveState) {
		setStopped(false);
	}
}

void *Transition::process(void *ptr) {

	Transition* transition = (Transition*) ptr;

	do { 

	Token* current = transition->getToken();

	if (current != NULL) {

#ifdef P_EVENT
		transition->dispatchPStartEvent();
#endif

		//Process token
		//1.BIN Routing


		//2.Dynamic Fuzzy Routing
		double result = FuzzyLogicDSL::Evaluate(1, 1, 1, 1, 0.3, 0, 1);
		cout << result << endl;

		transition->forwardToken(current);

	} else {

		pthread_mutex_t* mutex = transition->getMutex();//TODO remove from transition
		pthread_cond_t* cond_var = transition->getCondVar();

		pthread_mutex_lock(mutex);
		pthread_cond_wait(cond_var, mutex);
		pthread_mutex_unlock(mutex);

	}

	} while (!transition->isStopped());

	pthread_exit(0);

	return 0;

}

int Transition::getNewID() {
	return currentID++;
}

pthread_mutex_t* Transition::getMutex() {
	Node* n;
	n = *inputList.begin();//TODO store
	return n->getMutex();
}

pthread_cond_t* Transition::getCondVar() {
	Node* n;
	n = *inputList.begin();//TODO store
	return n->getCondVar();
}