#pragma once

#include <stdlib.h>

//#if !defined(__CYGWIN32__)
#include <sstream>
//#endif

#include "LinguisticValue.h"

using namespace std;

namespace FuzzyLogic {

	class SingletonValue : public LinguisticValue
	{
	public:
		//Constructor
		SingletonValue(string nValueName, double nA);

		//Destructor
		~SingletonValue(void);

		double CalculateLinguisticValue(double input);
		double CalculateMinCrispValue(double input);
		double CalculateMaxCrispValue(double input);
		double CalculateAvgCrispValue(double input);
	};
}