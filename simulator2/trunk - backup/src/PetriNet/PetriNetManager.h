/* 
 * File:   petrinet.h
 * Author: peter
 *
 * Created on February 24, 2012, 5:04 AM
 */

///*

#ifndef PETRINET_H
#define PETRINET_H

#include <list>

#include "../Simulation/GeneratorManager.h"
#include "ObjectType.h"
#include "PNFactory.h"
#include "../Simulation/SimTime.h"

class Token;
class Node;

namespace pn {
    
//public:
    void Init();
    void Free();

    void update(NodeState newState);
    void updateState(list<Node*>* nodes, NodeState newState);
    void joinNodes(Node* node1, Node* node2);

};

#endif

//*/



