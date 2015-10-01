/* 
 * File:   place.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 5:04 AM
 */

#include "Place.h"

int Place::currentID = 1;

Place::Place() : Node() {
    throw "wrong constructor";
}

Place::Place(string name, ProcessingType type) : Node(name, type) {
    int value = getNewID();
    Node::setID(value);
    Node::dispatchCreateEvent();

	mutex = PTHREAD_MUTEX_INITIALIZER;
	condition_var = PTHREAD_COND_INITIALIZER;

}

Place::~Place() {

}

void Place::addToken(Token* token) {

    //Check if node is terminal
    if (Node::getOutputNumber() == 0) {
        int time = token->getTime();//TODO continue
        sta::addTime(time);//TODO static
		delete token;
		return;
    }

	//Add token to node's token list
    Node::addToken(token);

	pthread_mutex_lock(&mutex);
	pthread_cond_broadcast(&condition_var);
	pthread_mutex_unlock(&mutex);

    return;
}

Token* Place::getToken() {
    Token* ret;
    ret = Node::getToken();

    return ret;
}

void Place::setState(NodeState newState) {
    Node::setState(newState);

}

int Place::getNewID() {
    return currentID++;
}

pthread_mutex_t* Place::getMutex() {
	return &mutex;
}

pthread_cond_t* Place::getCondVar() {
	return &condition_var;
}