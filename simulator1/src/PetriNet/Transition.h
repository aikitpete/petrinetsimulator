/* 
 * File:   Transition.h
 * Author: peter
 *
 * Created on February 28, 2012, 6:30 AM
 */

#ifndef TRANSITION_H
#define	TRANSITION_H

//Fuzzy
#include "../FuzzyRouting/Fuzzy.h"

#include "../Simulation/SimulationManager.h"

#include "ObjectType.h"
//#include "Token.h"
#include "Node.h"

class Token;

class Transition : public Node {
public:
    Transition();
    Transition(string name, ProcessingType type);
    virtual ~Transition();

    //int addToken(Token* token);
    Token* getToken();
    void setState(NodeState newState);

    ObjectType getType() {
        return TransitionObjectType;
    }

	void setStopped(bool value);

	bool isStopped() {
        return stopped;
    };

    static void resetID() {
        currentID = 1;
    };

	pthread_mutex_t* getMutex();
	pthread_cond_t* getCondVar();


private:
    int getNewID();
    static int currentID;

	bool stopped;

	static void *process(void *ptr);

};

#endif

