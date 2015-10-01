#pragma once

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

//#if !defined(__CYGWIN32__)
#include <sstream>
#include <vector>
//#endif

#include "FuzzyRule.h"
#include "LinguisticVariable.h"
#include "FuzzyCalculator.h"
#include "FuzzyInput.h"

using namespace std;

namespace FuzzyLogic {

	class FuzzyReasoner
	{
		//Vector of Fuzzy rules
		vector<FuzzyRule*> fuzzyRulesVector; 
	public:
		FuzzyReasoner(void);
		~FuzzyReasoner(void);

		//Add fuzzy rule
		void AddFuzzyRule(FuzzyRule* fuzzyRule);

		//Start reasoner for fuzzy rulles
		FuzzyRuleToken* CalculateFuzzyRules(vector<FuzzyInput*> fuzzyInputs);

		//Start fuzzy rule reasoner
		FuzzyRuleToken* FuzzyRuleReasoner(FuzzyRule* fuzzyRule, vector<FuzzyInput*> fuzzyInputs);

		//Defuzzyfication
		double DefuzzyMaxAvg(FuzzyRuleToken *outputToken);
		double DefuzzyMaxMin(FuzzyRuleToken *outputToken);
		double DefuzzyMaxMax(FuzzyRuleToken *outputToken);
		double DefuzzyCent(FuzzyRuleToken *outputToken);
	};

}