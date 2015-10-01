/* 
 * File:   NodeType.h
 * Author: peter
 *
 * Created on February 28, 2012, 9:36 PM
 */

#ifndef NODETYPE_H
#define	NODETYPE_H

enum ObjectType {
    TransitionObjectType = 1,
    PlaceObjectType = 2,
    TokenObjectType = 3,
	//GeneratorObjectType = 4,
    UnknownObjectType = 5
};

enum NodeState {
    ActiveState = 1,
    InactiveState = 0
};

enum ProcessingType {
    SingleToken = 1,
    MultiToken = 2
};

#endif	/* NODETYPE_H */

