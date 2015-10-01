/* 
 * File:   Times.h
 * Author: peter
 *
 * Created on March 12, 2012, 2:14 PM
 */

#ifndef TIMES_H
#define	TIMES_H

#define ARRAY_INCREMENT = 50

#include <cstdlib>
#include <stdlib.h>
#include <semaphore.h>
#include <list>

#include "iostream"

class Times {
public:
    Times();
    Times(const Times& orig);
    virtual ~Times();

    void addTime(double time);
    
    long getTotal();

private:
    std::list<double>* timesList;

	sem_t times_semaphore;
};

#endif	/* TIMES_H */

