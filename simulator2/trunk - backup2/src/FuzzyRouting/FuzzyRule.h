#pragma once

//#if !defined(__CYGWIN32__)
#include <sstream>
#include <vector>
//#endif

#include <stdlib.h>
#include "FuzzyRuleToken.h"

using namespace std;

namespace FuzzyLogic{

	class FuzzyRule
	{
		//Rule tokens
		vector<FuzzyRuleToken*> fuzzyRuleTokens;
	public:

		//Constructor
		FuzzyRule();

		~FuzzyRule(void);

		void AddTokenToRule(FuzzyRuleToken* fuzzyRuleToken);

		//Return fuzzy tokens
		vector<FuzzyRuleToken*> GetFuzzyRuleTokens();
	};
}