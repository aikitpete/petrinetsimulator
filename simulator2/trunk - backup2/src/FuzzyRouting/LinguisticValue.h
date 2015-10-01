#pragma once
#include <stdlib.h>

//#if !defined(__CYGWIN32__)
#include <sstream>
//#endif

using namespace std;

namespace FuzzyLogic {

	class LinguisticValue
	{
	protected:
		//Points
		double A;
		double B;
		double C;
		double D;
		//Linguistic value name
		string valueName;
		//Value
		double linguisticValue;

		double trapezoidBalance;

	public:
		virtual double CalculateLinguisticValue(double input)=0;
		virtual double CalculateMinCrispValue(double input)=0;
		virtual double CalculateMaxCrispValue(double input)=0;
		virtual double CalculateAvgCrispValue(double input)=0;

		//Setters
		void SetLinguisticValue(double nLinguisticValue);

		//Getters
		double GetLinguisticValue();
		double GetA();
		double GetB();
		double GetC();
		double GetD();
		double GetTrapezoidBalance();
		string ToString();
	};
}