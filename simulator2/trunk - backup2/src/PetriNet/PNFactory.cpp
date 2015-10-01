/* 
 * File:   NodeFactory.cpp
 * Author: peter
 * 
 * Created on February 27, 2012, 3:13 AM
 */

#include "PNFactory.h"

//TODO use template

PNFactory::PNFactory() {
	initialized = false;
}

PNFactory::~PNFactory() {

}

PNFactory* PNFactory::GetInstance() {
	if (!Instance) {
		Instance = new PNFactory();
	}
	return Instance;
}

void PNFactory::Init() {

    if (initialized == false) {
        //transitionList = new list<Node*>();
        //placeList = new list<Node*>();
        //tokenList = new list<Token*>();
		//generatorList = new list<Generator*>();
    }
    
    initialized = true;
}

void PNFactory::Free() {
    
    initialized = false;

    Transition::resetID(); //TODO remove this
    Place::resetID();

    //transitionList.clear();//TODO something wrong???
    //placeList.clear();
    //tokenList.clear();
	//generatorList->clear();
    
    //delete transitionList;//TODO move
    //delete placeList;
    //delete tokenList;
	//delete generatorList;

}

Node* PNFactory::createNode(string name, ObjectType type, ProcessingType procType) {
    Node* ret;

    switch (type) {
	case TransitionObjectType:
            ret = new Transition(name, procType);
            transitionList.push_front(ret);
            break;
	case PlaceObjectType:
            ret = new Place(name, procType);
            placeList.push_front(ret);
            break;
	/*
	case GeneratorObjectType:
            ret = new Generator(procType, 1);
            generatorList->push_front(ret);
            break;
    */
	default:
            throw "Unknown object type request";
            return NULL;
    }
    return ret;
}

Token* PNFactory::createToken() {
    Token* ret = new Token();
    tokenList.push_front(ret);
    return ret;
}

list<Node*>* PNFactory::getTransitionList() {
    return &transitionList;
}

list<Node*>* PNFactory::getPlaceList() {
    return &placeList;
}

list<Token*>* PNFactory::getTokenList() {
    return &tokenList;
}

/*

list<Generator*>* nf::getGeneratorList() {
    return generatorList;
}

*/