/* 
 * File:   token.cpp
 * Author: peter
 * 
 * Created on February 24, 2012, 5:04 AM
 */

#include "Token.h"

using namespace std;

int Token::currentTID = 1;

Token::Token() {
    int value = Token::getNewID();
    setID(value);

	watch = new stopWatch();
	watch->start();

}

Token::~Token() {
	watch->stop();
	delete watch;
}

int Token::getID() {
    return tokenID;
}

double Token::getTime() {
	return watch->elapsedTime();
}

int Token::getNewID() {
    return currentTID++;
}