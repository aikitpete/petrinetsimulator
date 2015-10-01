/* 
 * File:   NodeFactory.h
 * Author: peter
 *
 * Created on February 27, 2012, 3:13 AM
 */

#ifndef NODEFACTORY_H
#define	NODEFACTORY_H

#include "Token.h"
#include "Transition.h"
#include "Place.h"
//#include "Generator.h"

#include <list>

class Node;

//class Transition;//this can't be used
//class Place;

namespace nf {

    //public:
    void Init();
    void Free();

    Node* createNode(string name, ObjectType type, ProcessingType procType);

    Token* createToken();

    static list<Node*>* transitionList;
    static list<Node*>* placeList;
    static list<Token*>* tokenList;
	//static list<Generator*>* generatorList;

    list<Node*>* getTransitionList();
    list<Node*>* getPlaceList();
    list<Token*>* getTokenList();
	//list<Generator*>* getGeneratorList();
    
    static bool initialized;

};

#endif	



