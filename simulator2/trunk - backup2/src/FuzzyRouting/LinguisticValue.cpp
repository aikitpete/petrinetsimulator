#include "LinguisticValue.h"

namespace FuzzyLogic {

	//Setters
	void LinguisticValue::SetLinguisticValue(double nLinguisticValue) {
		linguisticValue = nLinguisticValue;
	}

	//Getters
	double LinguisticValue::GetLinguisticValue() {
		if(linguisticValue == -1)
			return 0;
		return linguisticValue;
	}

	double LinguisticValue::GetA() {
		return A;
	}

	double LinguisticValue::GetB() {
		return B;
	}

	double LinguisticValue::GetC() {
		return C;
	}

	double LinguisticValue::GetD() {
		return D;
	}

	double LinguisticValue::GetTrapezoidBalance() {
		return trapezoidBalance;
	}

	string LinguisticValue::ToString() {
		return valueName;
	}

}