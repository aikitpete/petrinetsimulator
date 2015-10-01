/* 
* File:   Node.cpp
* Author: peter
* 
* Created on February 25, 2012, 5:08 PM
*/

#include "Node.h"

//using logger::logEvent;

Node::Node() {
	throw "Wrong node constructor";
}

Node::Node(string id, ProcessingType type) {
	setProcessingType(type);
	state = InactiveState;
	setName(id);

	sem_init(&token_semaphore, 0, 1);
}

Node::~Node() {

}

/**
* Receives token from previous node in chain
*/
int Node::receiveToken() {

	Node* n;

	ProcessingType t = getProcessingType();

	if (t == SingleToken) {

		n = *inputList.begin();

		return receiveToken(n);

	} else if (t == MultiToken) {

		list<Node*>::iterator i;

		for (i = inputList.begin(); i != inputList.end(); ++i) {

			if (i == inputList.begin()) {

				n = *i;
				Token* t = n->getToken();
				addToken(t);

			} else {

				n = (Node*) * i;
				n->getToken();
			}
		}
		return false;
	}
	return true;
}

/**
* Forward token to next node in chain
*/
void Node::forwardToken(Token* token) {

	Node* n;

	if (processingType == SingleToken) {

		n = outputList.front();
		n->addToken(token);

	} else if (processingType == MultiToken) {

		list<Node*>::iterator i;

		for (i = outputList.begin(); i != outputList.end(); ++i) {

			//TODO
			n = * i;
			n->addToken(token);

		}

	} else {
		throw "Processing error";
	}

}

/**
* Add input node
* @param node
*/
void Node::addInput(Node* node) {
	inputList.push_front(node);
}

/**
* Add output node
* @param node
*/
void Node::addOutput(Node* node) {
	outputList.push_front(node);
}

int Node::getTokenNumber() {
	/********** Critical Section *******************/
	sem_wait(&token_semaphore);
	int ret = (int) tokenList.size();//TODO edit
	sem_post(&token_semaphore);

	return ret;
}

string Node::getName() {
	return name;
}

void Node::setName(string value) {
	name = value;
}

/**
* Insert new token
* @param token
*/
void Node::addToken(Token* token) {
	/********** Critical Section *******************/
	sem_wait(&token_semaphore);
	tokenList.push_front(token);
	sem_post(&token_semaphore);

#ifdef T_EVENT
	dispatchTokenEvent();
#endif

}

/**
* Remove token
* @return 
*/
Token* Node::getToken() {
	//If node is not active return NULL
	if (state == InactiveState) {
		return NULL;
	}

	int i = getTokenNumber();//TODO remove

	if (i == 0) {
		return NULL;
	}

	/********** Critical Section *******************/
	sem_wait(&token_semaphore);
	Token *ret = tokenList.back();
	tokenList.pop_back();
	sem_post(&token_semaphore);

#ifdef T_EVENT

	dispatchTokenEvent();

#endif

	return ret;
}

void Node::dispatchCreateEvent() {
	ObjectType type = getType();
	logger::logEvent(type, ID);
}

#ifdef T_EVENT

void Node::dispatchTokenEvent() {
	ObjectType type = getType();
	int tokens = getTokenNumber();
	logger::logEvent(type, ID, tokens);
}

void Node::dispatchTokenEvent(Token * token) {
	ObjectType type = getType();
	int tokenID = token->getID();
	int tokens = getTokenNumber();
	logger::logEvent(type, ID, tokens, tokenID);
}

#endif

#ifdef P_EVENT

void Node::dispatchPStartEvent() {
	ObjectType type = getType();
	logger::logEvent(type, ID, ProcessingStart);
}

void Node::dispatchPEndEvent() {
	ObjectType type = getType();
	logger::logEvent(type, ID, ProcessingEnd);
}

#endif

int Node::receiveToken(Node* n) {
	Token* token;
	token = n->getToken();

	if (token) {
		addToken(token);
	} else {
		return false;
	}

	return true;
}