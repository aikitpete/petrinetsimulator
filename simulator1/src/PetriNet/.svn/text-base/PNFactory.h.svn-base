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

namespace nf {

//public:
	
//	PNFactory();
//	virtual ~PNFactory();
	
//	static PNFactory* GetInstance();
	
    void Init();
    void Free();

    Node* createNode(string name, ObjectType type, ProcessingType procType);

    Token* createToken();

	list<Node*>* getTransitionList();
    list<Node*>* getPlaceList();
    list<Token*>* getTokenList();
	//list<Generator*>* getGeneratorList();

//private:

    static list<Node*> transitionList;
    static list<Node*> placeList;
    static list<Token*> tokenList;
	//static list<Generator*>* generatorList;
    
//	static PNFactory* Instance;

    static bool initialized;

};

#endif	



