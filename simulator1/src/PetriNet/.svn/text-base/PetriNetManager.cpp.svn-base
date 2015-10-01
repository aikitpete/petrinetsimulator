/* 
 * File:   petrinet.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 5:04 AM
 */

#include "PetriNetManager.h"

void pn::Init() {

	//PNFactory* instance = PNFactory::GetInstance();

    nf::Init();

	//Input Node Queue

    Node* p1 = nf::createNode("p1", PlaceObjectType, SingleToken);
    Node* p2 = nf::createNode("p2", PlaceObjectType, SingleToken);
	Node* p3 = nf::createNode("p3", PlaceObjectType, SingleToken);

	//Input Node

    Node* t1 = nf::createNode("t1", TransitionObjectType, SingleToken);
	Node* t2 = nf::createNode("t2", TransitionObjectType, SingleToken);
	Node* t3 = nf::createNode("t3", TransitionObjectType, SingleToken);

	//Routing Queue

	Node* p4 = nf::createNode("p4 (routing queue)", PlaceObjectType, SingleToken);
	
	//Routing

	Node* t4 = nf::createNode("t4 (routing)", TransitionObjectType, SingleToken);

	//Output Node Queue

	Node* p5 = nf::createNode("p5", PlaceObjectType, SingleToken);
    Node* p6 = nf::createNode("p6", PlaceObjectType, SingleToken);
	Node* p7 = nf::createNode("p7", PlaceObjectType, SingleToken);

	//Output Node

	Node* t5 = nf::createNode("t5", TransitionObjectType, SingleToken);
	Node* t6 = nf::createNode("t6", TransitionObjectType, SingleToken);
	Node* t7 = nf::createNode("t7", TransitionObjectType, SingleToken);

	//Output

	Node* p8 = nf::createNode("p8", PlaceObjectType, SingleToken);
    Node* p9 = nf::createNode("p9", PlaceObjectType, SingleToken);
	Node* p10 = nf::createNode("p10", PlaceObjectType, SingleToken);

	//Input Node Queue & Input Node
	
    joinNodes(p1, t1);
    joinNodes(p2, t2);
	joinNodes(p3, t3);

	//Input Node & Routing Queue

    joinNodes(t1, p4);
    joinNodes(t2, p4);
	joinNodes(t3, p4);
	
	//Routing Queue & Routing

    joinNodes(p4, t4);

	//Routing & Output Node Queue

    joinNodes(t4, p5);
    joinNodes(t4, p6);
	joinNodes(t4, p7);

	//Output Node Queue & Output

	joinNodes(p5, t5);
    joinNodes(p6, t6);
	joinNodes(p7, t7);

	//Output & Final Place

    joinNodes(t5, p8);
    joinNodes(t6, p9);
	joinNodes(t7, p10);
	
	//Connect Generator

	gm::addNewGenerator(p1, 1, 250);
	gm::addNewGenerator(p2, 2, 250);
	gm::addNewGenerator(p3, 3, 250);

}

void pn::Free() {
	//PNFactory* instance = PNFactory::GetInstance();
    nf::Free();
}

void pn::update(NodeState newState) {
    //PNFactory* instance = PNFactory::GetInstance();
    updateState(nf::getPlaceList(), newState);
    updateState(nf::getTransitionList(), newState);

}

void pn::updateState(list<Node*>* nodes, NodeState newState) {
    list<Node*>::iterator i;
    Node* n;
    for (i = nodes->begin(); i != nodes->end(); ++i) {
        n = (Node*) * i;
        n->setState(newState);
    }
}

void pn::joinNodes(Node* node1, Node* node2) {
    node1->addOutput(node2);
    ObjectType t = node2->getType();
    if (t == TransitionObjectType) {
        node2->addInput(node1);
    }
}