/* 
 * File:   Place.h
 * Author: peter
 *
 * Created on February 28, 2012, 6:31 AM
 */

#ifndef PLACE_H
#define	PLACE_H

#include <pthread.h>
#include "ObjectType.h"
#include "Node.h"
#include "../Simulation/Statistics.h"

class Token;

class Place : public Node {
public:
    Place();
    Place(string name, ProcessingType type);
    virtual ~Place();

    void addToken(Token* token);
    Token* getToken();

    void setState(NodeState newState);

    ObjectType getType() {
        return PlaceObjectType;
    }
    
    static void resetID() {
        currentID = 1;
    };

	pthread_mutex_t* getMutex();
	pthread_cond_t* getCondVar();

private:
    int getNewID();
    static int currentID;

};

#endif	/* PLACE_H */

