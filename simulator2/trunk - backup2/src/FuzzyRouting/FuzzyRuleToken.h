#pragma once

#include "LinguisticVariable.h"
#include "FuzzyInput.h"

using namespace std;

namespace FuzzyLogic{

	//ENUM operation
	enum Operation{
		AND,OR,EMPTY
	};

	class FuzzyRuleToken
	{
		//Is there operator before token
		Operation operation;
		//Is there negation for this token
		bool negation;
		//Pointer to linguistic variable
		LinguisticVariable* linguisticVariable;
		//Name of Linguistic value
		string linguisticValueName;

	public:

		//Constructor
		FuzzyRuleToken(bool nNegation, 
			Operation nOperation, 
			LinguisticVariable* nLinguisticVariable, 
			string nLinguisticValueId);

		~FuzzyRuleToken(void);

		//Calculate token value
		double CalculateTokenOutputValue(vector<FuzzyInput*> fuzzyInputs);

		void UpdateTokenValue(double newVal);

		//GETTERS
		string GetLinguisticValueName();
		LinguisticVariable* GetLinguisticVariable();

		bool IsOutput();
		bool IsNegated();
		bool IsFirst();
		bool IsAndOperator();
		bool IsOrOperator();
	};
}