/* 
 * File:   Singleton.h
 * Author: peter
 *
 * Created on March 1, 2012, 8:43 AM
 */

#ifndef SINGLETON_H
#define	SINGLETON_H

#include <assert.h>
#include <stdlib.h>

template<class T>
class Singleton {
    static T* singleton;
public:

    Singleton(T& t) {
        assert(singleton != NULL);
        singleton = t;
    }

    virtual ~Singleton<T>() {
        if (singleton)
            delete singleton;
    }

    static T& GetInstance() {
        assert(singleton != NULL);
        return singleton;
    }

private:

};

#endif	/* SINGLETON_H */

