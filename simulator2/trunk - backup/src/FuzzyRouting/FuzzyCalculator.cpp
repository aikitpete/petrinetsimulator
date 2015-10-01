#include "FuzzyCalculator.h"

namespace FuzzyLogic {

		//Implementation of fuzzy operators

		//Operator AND
		double FuzzyCalculator::AND(double a, double b) {
			if(a < b)
				return a;
			return b;
		}

		//Operator OR
		double FuzzyCalculator::OR(double a, double b) {
			if(a > b)
				return a;
			return b;
		}

}