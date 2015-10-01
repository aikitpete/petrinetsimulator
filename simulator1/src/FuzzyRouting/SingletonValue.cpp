#include "SingletonValue.h"

namespace FuzzyLogic {

	//Constructor
	SingletonValue::SingletonValue(string nValueName, double nA) {
		A = nA;
		valueName = nValueName;
		linguisticValue = -1;
		trapezoidBalance = 1;
	}

	//Destructor
	SingletonValue::~SingletonValue(void) {

	}

	double SingletonValue::CalculateLinguisticValue(double input) {
		//Normalize variables
		if(input == A)
			return 1;
		else
			return 0;
	}

	double SingletonValue::CalculateMinCrispValue(double input) {
		//Normalize variables
		if(input == 1)
			return A;
		else
			return 0;
	}

	double SingletonValue::CalculateMaxCrispValue(double input) {
		//Normalize variables
		if(input == 1)
			return A;
		else
			return 0;
	}

	double SingletonValue::CalculateAvgCrispValue(double input) {
		//Normalize variables
		if(input == 1)
			return A;
		else
			return 0;
	}

}