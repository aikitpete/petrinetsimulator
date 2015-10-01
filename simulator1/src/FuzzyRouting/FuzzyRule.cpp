#include "FuzzyRule.h"

namespace FuzzyLogic {

	//Constructor
	FuzzyRule::FuzzyRule() {

	}

	FuzzyRule::~FuzzyRule(void) {
		//Delete all tokens
		for(unsigned int i = 0; i < fuzzyRuleTokens.size(); i++)
			delete fuzzyRuleTokens[i];
	}

	void FuzzyRule::AddTokenToRule(FuzzyRuleToken* fuzzyRuleToken)
	{
		fuzzyRuleTokens.push_back(fuzzyRuleToken);
	}

	//Return fuzzy tokens
	vector<FuzzyRuleToken*> FuzzyRule::GetFuzzyRuleTokens(){return fuzzyRuleTokens;}

}