#include "FuzzyReasoner.h"

using namespace FuzzyLogic;

//Constructor
FuzzyReasoner::FuzzyReasoner(void) {

}

FuzzyReasoner::~FuzzyReasoner(void) {
	//Release all rules
	for(unsigned int i = 0; i < fuzzyRulesVector.size(); i++)
		delete (FuzzyRule*)fuzzyRulesVector[i];
}

//Add fuzzy rule
void FuzzyReasoner::AddFuzzyRule(FuzzyRule* fuzzyRule) {
	fuzzyRulesVector.push_back(fuzzyRule);
}

//Start reasoner for fuzzy rulles
FuzzyRuleToken* FuzzyReasoner::CalculateFuzzyRules(vector<FuzzyInput*> fuzzyInputs) {
	//Reset all values

	FuzzyRuleToken* outputObject;

	//Calculate all fuzzy rules
	for(unsigned int i = 0; i < fuzzyRulesVector.size(); i++)
	{
		outputObject = FuzzyRuleReasoner((FuzzyRule*)fuzzyRulesVector[i], fuzzyInputs);
	}

	//Return output object
	return outputObject;
}

//Start fuzzy rule reasoner
FuzzyRuleToken* FuzzyReasoner::FuzzyRuleReasoner(FuzzyRule* fuzzyRule, vector<FuzzyInput*> fuzzyInputs) {
	double resultVal = 0;
	for(unsigned int i = 0; i < fuzzyRule->GetFuzzyRuleTokens().size(); i++)
	{
		//Get fuzzy rule token
		FuzzyRuleToken* token = fuzzyRule->GetFuzzyRuleTokens()[i];
		
		if(token->IsOutput())
		{
			//Update output object
			token->UpdateTokenValue(resultVal);
			//Return result token
			return token;
		}
		else
		{
			double tokenVal = token->CalculateTokenOutputValue(fuzzyInputs);
			token->UpdateTokenValue(tokenVal);
			if(token->IsNegated())
				tokenVal = 1 - tokenVal;	//Negate value
			if(i == 0)
				resultVal = tokenVal;		//Set value
			else if(token->IsOrOperator())
				resultVal = FuzzyCalculator::OR(resultVal, tokenVal); //OR operator
			else if(token->IsAndOperator())
				resultVal = FuzzyCalculator::AND(resultVal, tokenVal); //AND operator

		}
	}
	assert(NULL);
	return NULL;
}

double FuzzyReasoner::DefuzzyMaxAvg(FuzzyRuleToken *outputToken) {
	//For every output value
	LinguisticVariable* lVar = outputToken->GetLinguisticVariable();
	vector<LinguisticValue*> valuesList = lVar->GetLinguisticValuesList();

	double max=0;
	LinguisticValue* best;
	LinguisticValue* val;

	//Calculating defuzzy value
	for(unsigned int i = 0; i < valuesList.size(); i++)
	{
		val = valuesList.at(i);
		//cout << val->GetLinguisticValue() << endl;
		if (val->GetLinguisticValue() >= max) {
			max = val->GetLinguisticValue();
			best = val;
		}

	}

	return best->CalculateAvgCrispValue(best->GetLinguisticValue());
}



double FuzzyReasoner::DefuzzyMaxMax(FuzzyRuleToken *outputToken) {
	//For every output value
	LinguisticVariable* lVar = outputToken->GetLinguisticVariable();
	vector<LinguisticValue*> valuesList = lVar->GetLinguisticValuesList();

	double max=0;
	LinguisticValue* best;
	LinguisticValue* val;

	//Calculating defuzzy value
	for(unsigned int i = 0; i < valuesList.size(); i++)
	{
		val = valuesList.at(i);

		if (val->GetLinguisticValue() >= max) {
			max = val->GetLinguisticValue();
			best = val;
		}

	}

	return best->CalculateMaxCrispValue(best->GetLinguisticValue());
}

double FuzzyReasoner::DefuzzyMaxMin(FuzzyRuleToken *outputToken) {
	//For every output value
	LinguisticVariable* lVar = outputToken->GetLinguisticVariable();
	vector<LinguisticValue*> valuesList = lVar->GetLinguisticValuesList();

	double max=0;
	LinguisticValue* best;
	LinguisticValue* val;

	//Calculating defuzzy value
	for(unsigned int i = 0; i < valuesList.size(); i++)
	{
		val = valuesList.at(i);

		if (val->GetLinguisticValue() >= max) {
			max = val->GetLinguisticValue();
			best = val;
		}

	}

	return best->CalculateMinCrispValue(best->GetLinguisticValue());
}

//Defuzzification
double FuzzyReasoner::DefuzzyCent(FuzzyRuleToken *outputToken) {
	//For every output value
	LinguisticVariable* lVar = outputToken->GetLinguisticVariable();
	vector<LinguisticValue*> valuesList = lVar->GetLinguisticValuesList();

	double upEquation = 0;
	double downEquation = 0;
	//Calculating defuzzy value
	for(unsigned int i = 0; i < valuesList.size(); i++)
	{
		LinguisticValue* val = valuesList.at(i);
		upEquation += val->GetLinguisticValue()
			* val->GetTrapezoidBalance(); 
		downEquation += val->GetLinguisticValue();
	}
	//Return output value of system
	if(downEquation == 0)
		return 0;
	return upEquation / downEquation;
}
