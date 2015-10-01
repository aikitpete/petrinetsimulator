#pragma once

#include <iostream>

#if defined(__GNUC__)
//#if !defined(__CYGWIN32__)
#include <tr1/unordered_map>
//#endif
#else
#include <hash_map>
#endif

#include "FuzzyReasoner.h"
#include "FuzzyRule.h"
#include "FuzzyRuleToken.h"
#include "LinguisticVariable.h"
#include "LinguisticValue.h"
#include "FuzzyInput.h"

using namespace std;

namespace FuzzyLogic {

	/*Class used to perform fuzzy experiments*/
	class Experiments
	{
		//FuzzyReasoner instance
		FuzzyReasoner* fr;
		FuzzyRuleToken* outputToken;
		vector<LinguisticVariable*> linguisticVariables;
		short linguisticVariablesSize;

#if defined(__GNUC__)		
		std::tr1::unordered_map<string,LinguisticVariable*> linguisticVariablesHashMap;
#else
		hash_map<string,LinguisticVariable*> linguisticVariablesHashMap;
#endif

		double output;
	public:
		Experiments(void);
		~Experiments(void);

		void SetLinguisticVariablesSize(short size);
		
		void AddFuzzyRule(FuzzyRule* rule);
		double CalculateFuzzyRules(vector<FuzzyInput*> fuzzyInputs, short kind);
		void ResetTokenValues();

		double GetOutputValue();

		double GetAByNumber(short variableNumber, short valueNumber);
		double GetBByNumber(short variableNumber, short valueNumber);
		double GetCByNumber(short variableNumber, short valueNumber);
		double GetDByNumber(short variableNumber, short valueNumber);

		double GetLinguisticVariableValue(short variableNumber, short valueNumber);

		void AddLinguisticVariables(LinguisticVariable* linguisticVariable);

		LinguisticVariable* FindLinguisticVariableByName(string variableName);
		LinguisticVariable* FindLinguisticVariableByNumber(short variableNumber);
	};

}