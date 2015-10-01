#pragma once

#include <stdlib.h>

//#if !defined(__CYGWIN32__)
#include <sstream>
//#endif

#include <math.h>

#include "LinguisticValue.h"

using namespace std;

namespace FuzzyLogic {

	class TrapezoidValue : public LinguisticValue
	{
	public:
		//Constructor
		TrapezoidValue(string nValueName, double nA, double nB, double nC, double nD);

		//Destructor
		~TrapezoidValue(void);

		double CalculateLinguisticValue(double input);
		double CalculateMinCrispValue(double input);
		double CalculateMaxCrispValue(double input);
		double CalculateAvgCrispValue(double input);
	};
}