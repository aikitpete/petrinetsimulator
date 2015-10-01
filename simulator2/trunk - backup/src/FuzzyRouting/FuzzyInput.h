#pragma once
#include <stdlib.h>

//#if !defined(__CYGWIN32__)
#include <sstream>
#include <vector>
//#endif

using namespace std;

namespace FuzzyLogic {
	/*Class used to input data*/
	class FuzzyInput
	{
		//Input value for fuzzy system
		double inputValue;
	public:
		FuzzyInput(double nInputValue);
		~FuzzyInput(void);
		
		//Setters
		void SetInputValue(double newVal);

		//Getters
		string GetVariableName();
		double GetInputValue();
	};

}