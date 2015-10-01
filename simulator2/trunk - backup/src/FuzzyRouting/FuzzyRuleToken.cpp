#include "FuzzyRuleToken.h"

namespace FuzzyLogic {

	//Constructor
	FuzzyRuleToken::FuzzyRuleToken(bool nNegation, 
		Operation nOperation, 
		LinguisticVariable* nLinguisticVariable, 
		string nLinguisticValueId) {
		negation = nNegation;
		operation = nOperation;
		linguisticVariable = nLinguisticVariable;
		linguisticValueName = nLinguisticValueId;
	}

	FuzzyRuleToken::~FuzzyRuleToken(void) {

	}

	//Calculate token value
	double FuzzyRuleToken::CalculateTokenOutputValue(vector<FuzzyInput*> fuzzyInputs) {
		//Find linguistic variable
		FuzzyInput* temp = fuzzyInputs.at(linguisticVariable->GetNumber()-1);
		double input = temp->GetInputValue();
		//Calculate linguistic value
		return linguisticVariable->CalculateLinguisticValueByName(linguisticValueName, input);
	}

	void FuzzyRuleToken::UpdateTokenValue(double newVal) {
		//Just update token value
		linguisticVariable->UpdateLinguisticValueByName(linguisticValueName, newVal);
	}

	//GETTERS
	string FuzzyRuleToken::GetLinguisticValueName() {
		return linguisticValueName;
	}

	LinguisticVariable* FuzzyRuleToken::GetLinguisticVariable() {
		return linguisticVariable;
	}

	bool FuzzyRuleToken::IsOutput() {
		return linguisticVariable->IsOutputVariable();
	}

	bool FuzzyRuleToken::IsNegated() {
		return negation;
	}

	bool FuzzyRuleToken::IsFirst() {
		if(operation == EMPTY) 
			return true;
		return false;
	}

	bool FuzzyRuleToken::IsAndOperator() {
		if(operation == AND) 
			return true;
		return false;
	}

	bool FuzzyRuleToken::IsOrOperator() {
		if(operation == OR) 
			return true;
		return false;
	}

}