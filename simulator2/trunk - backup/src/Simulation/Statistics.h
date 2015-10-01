/* 
 * File:   statistics.h
 * Author: peter
 *
 * Created on February 24, 2012, 5:04 AM
 */

#ifndef STATISTICS_H
#define	STATISTICS_H

#include "Times.h"
#include "assert.h"

#include "StopWatch.h"

#include "GeneratorManager.h"

namespace sta {
//public:
	void Init();
    void Start();
    void Stop();
	void Free();

    double getAverageTPS();
    long getAverageRT();
    long getTimeout();
    long getMaximum();
    long getTotal();
	double getTotalTime();

    void checkMaximum();
    void addSimulationTime(double simTime);
    void addTime(double time);

//private:
    static Times* times;

    static long total; //total number of processed transactions
    static long timeout; //total number of time outed transactions
    static long max; //maximum number of transactions in system

	static stopWatch* watch;

};

#endif	/* STATISTICS_H */

