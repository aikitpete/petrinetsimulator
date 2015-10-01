/* 
 * File:   Handler.h
 * Author: peter
 *
 * Created on February 29, 2012, 6:11 AM
 */

#ifndef HANDLER_H
#define	HANDLER_H

#include <wx/wx.h>

class Handler : public wxEvtHandler {
public:
    Handler* getInstance();
private:
    Handler();
    virtual ~Handler();
    
    Handler* instance;
};

#endif	/* HANDLER_H */

