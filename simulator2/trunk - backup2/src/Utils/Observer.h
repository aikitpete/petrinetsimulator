/* 
 * File:   Module.h
 * Author: peter
 *
 * Created on March 5, 2012, 11:18 AM
 */

#ifndef OBSERVER_H
#define	OBSERVER_H

#include "../UI/AppState.h"

class Observer {
public:
    void Update(AppState state);

protected:
    virtual void SwitchInit()=0;
    virtual void SwitchOpen()=0;
    virtual void SwitchRunning()=0;
    virtual void SwitchStopped()=0;
    virtual void SwitchReset()=0;
    virtual void SwitchExit()=0;

private:

};

#endif	

