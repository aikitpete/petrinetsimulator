#ifndef FUZZY_H
#define FUZZY_H

#include "stdafx.h"
#include "FuzzyLanguageParser.h"
#include "FuzzyReasoner.h"
#include "FuzzyRule.h"
#include "FuzzyRuleToken.h"
#include "LinguisticVariable.h"
#include "LinguisticValue.h"
#include "FuzzyInput.h"
#include "Experiments.h"
#include <iostream>

#define EXPERIMENTS 10000

namespace FuzzyLogicDSL {

	static FuzzyLogic::Experiments* experiment;

	void Init(char* file);

	double Evaluate(double d1, double d2, double d3, double d4, double d5, double d6, short variant);

	void GetResult();

}

#endif