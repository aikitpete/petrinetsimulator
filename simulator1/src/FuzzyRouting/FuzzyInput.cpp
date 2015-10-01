#include "FuzzyInput.h"

namespace FuzzyLogic {

	FuzzyInput::FuzzyInput(double nInputValue) {
		inputValue = nInputValue;
	}

	FuzzyInput::~FuzzyInput(void) {
	}

	//Setters
	void FuzzyInput::SetInputValue(double newVal) {
		inputValue = newVal;
	}

	//Getters
	double FuzzyInput::GetInputValue() {
		return inputValue;
	}

}