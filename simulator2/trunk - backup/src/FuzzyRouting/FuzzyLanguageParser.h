#pragma once
#include <stdlib.h>

//#if !defined(__CYGWIN32__)
#include <sstream>
#include <vector>
#include <fstream>
//#endif

#include <string>
#include <assert.h>
#include <iostream>

#include "Experiments.h"
#include "LinguisticVariable.h"
#include "LinguisticValue.h"
#include "SingletonValue.h"
#include "FuzzyRuleToken.h"
#include "FuzzyRule.h"
#include "TrapezoidValue.h"

#ifndef FUZZYLANGUAGEPARSER_H
#define FUZZYLANGUAGEPARSER_H

#define LINGUISTIC_SIZE 7

using namespace std;
using namespace FuzzyLogic;

class FuzzyLanguageParser
{
public:
	Experiments* fuzzyInterface;
	FuzzyLanguageParser(Experiments* nFuzzyInterface);

	~FuzzyLanguageParser(void);

	void Parse(char* filePath);

private:
	//Check is line is comment
	bool IsComment(string token);

	bool IsRule(string token);

	void ParseFuzzyRule(vector<string> ruleTokens);

	void ParseFuzzyAtribute(vector<string> attTokens);

	vector<double> ParseLinguisticValues(string token);

	//Function that splits line by given char
	vector<string> SplitBy(string line, char splitter);

	int current;
};

#endif