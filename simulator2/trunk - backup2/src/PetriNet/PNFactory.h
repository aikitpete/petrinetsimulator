/* 
 * File:   NodeFactory.h
 * Author: peter
 *
 * Created on February 27, 2012, 3:13 AM
 */

#ifndef NODEFACTORY_H
#define	NODEFACTORY_H

#include <list>

#include "Transition.h"
#include "Token.h"
#include "Place.h"
//#include "Generator.h"

//class Node;

//class Transition;//this can't be used
//class Place;

class PNFactory {

    public:
	
	PNFactory();
	virtual ~PNFactory();
	
	static PNFactory* GetInstance();
	static PNFactory* Instance;
	
    void Init();
    void Free();

    Node* createNode(string name, ObjectType type, ProcessingType procType);

    Token* createToken();

    list<Node*> transitionList;
    list<Node*> placeList;
    list<Token*> tokenList;
	//static list<Generator*>* generatorList;

    list<Node*>* getTransitionList();
    list<Node*>* getPlaceList();
    list<Token*>* getTokenList();
	//list<Generator*>* getGeneratorList();
    
    bool initialized;

};

#endif	



