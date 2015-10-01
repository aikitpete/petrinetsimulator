/* 
* File:   Node.h
* Author: peter
*
* Created on February 25, 2012, 5:08 PM
*/

#ifndef NODE_H
#define	NODE_H

#include <cstdlib>
#include <stdlib.h>
#include <pthread.h>
#include <list>
#include <semaphore.h>

#include "../Simulation/Logger.h"
#include "Token.h"
#include "ObjectType.h"
#include "../Simulation/LogType.h"
#include <math.h>

class Node {
public:
	Node();
	Node(string name, ProcessingType type);
	//Node(const Node&);
	virtual ~Node();

	int receiveToken();
	void forwardToken(Token* token);

	void addInput(Node* node);
	void addOutput(Node* node);

	int getTokenNumber();

	int getOutputNumber() {
		int ret = (int) outputList.size();
		return ret;
	}

	string getName();
	void setName(string id);

	virtual void addToken(Token* token);
	virtual Token* getToken();

	virtual void setState(NodeState newState) {
		state = newState;
	}

	virtual ObjectType getType() {
		return UnknownObjectType;
	}

	virtual pthread_mutex_t* getMutex()=0;
	virtual pthread_cond_t* getCondVar()=0;

	pthread_mutex_t mutex;
	pthread_cond_t condition_var;

protected:
	void dispatchCreateEvent();

#ifdef T_EVENT

	void dispatchTokenEvent();
	void dispatchTokenEvent(Token* token);

#endif

	void dispatchPStartEvent();
	void dispatchPEndEvent();

	NodeState getState() {
		return state;
	}

	ProcessingType getProcessingType() {
		return processingType;
	}

	void setProcessingType(ProcessingType type) {
		processingType = type;
	}

	void setID(int value) {
		ID = value;
	}

	list<Node*> inputList;
	list<Node*> outputList;

private:

	virtual int getNewID() {
		return 0;
	}; //TODO use abstract?
	int receiveToken(Node* n);
	ProcessingType processingType;
	list<Token*> tokenList;
	NodeState state;
	int ID;
	bool shortage;
	string name;

	sem_t token_semaphore;
};

#endif	/* NODE_H */

