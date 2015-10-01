#pragma once

namespace FuzzyLogic {

	/*Class used to interpret fuzzy operators*/
	class FuzzyCalculator
	{
	public:
		//Implementation of fuzzy operators
		
		//Operator AND
		static double AND(double a, double b);

		//Operator OR
		static double OR(double a, double b);
	};

}