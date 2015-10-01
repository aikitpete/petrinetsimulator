#include "Experiments.h"

using namespace FuzzyLogic;

Experiments::Experiments(void) {
	//Create
	fr = new FuzzyReasoner();
}

Experiments::~Experiments(void) {
	//Release
	delete fr;
}

void Experiments::SetLinguisticVariablesSize(short size) {
	linguisticVariablesSize = size;
}

void Experiments::AddFuzzyRule(FuzzyRule* rule) {
	fr->AddFuzzyRule(rule);
}

double  Experiments::CalculateFuzzyRules(vector<FuzzyInput*> fuzzyInputs, short variant) {
	
	outputToken = fr->CalculateFuzzyRules(fuzzyInputs);
	assert(outputToken != NULL);
	
	switch(variant) {
	case 1:
		output = fr->DefuzzyCent(outputToken);
		break;
	case 2:
		output = fr->DefuzzyMaxAvg(outputToken);
		break;
	case 3:
		output = fr->DefuzzyMaxMax(outputToken);
		break;
	case 4:
		output = fr->DefuzzyMaxMin(outputToken);
		break;
	}
	
	return output; 
}

void Experiments::ResetTokenValues() {
	//Set all linguistic values to -1
	for (int i = 0; i<linguisticVariablesSize; i++)
	{
		//Repeat until the end
		linguisticVariables[i]->ResetLinguisticValues();
	}
}

double Experiments::GetOutputValue() {
	return output;
}

double Experiments::GetAByNumber(short variableNumber, short valueNumber) {
	LinguisticVariable* temp = FindLinguisticVariableByNumber(variableNumber);
	return temp->FindLinguisticValueByNumber(valueNumber)->GetA();
}

double Experiments::GetBByNumber(short variableNumber, short valueNumber) {
	LinguisticVariable* temp = FindLinguisticVariableByNumber(variableNumber);
	return temp->FindLinguisticValueByNumber(valueNumber)->GetB();
}

double Experiments::GetCByNumber(short variableNumber, short valueNumber) {
	LinguisticVariable* temp = FindLinguisticVariableByNumber(variableNumber);
	return temp->FindLinguisticValueByNumber(valueNumber)->GetC();
}

double Experiments::GetDByNumber(short variableNumber, short valueNumber) {
	LinguisticVariable* temp = FindLinguisticVariableByNumber(variableNumber);
	return temp->FindLinguisticValueByNumber(valueNumber)->GetD();
}

double Experiments::GetLinguisticVariableValue(short variableNumber, short valueNumber) {
	LinguisticVariable* temp1 = FindLinguisticVariableByNumber(variableNumber);
	assert(temp1 != NULL);
	return temp1->FindLinguisticValueByNumber(valueNumber)->GetLinguisticValue();
}

void Experiments::AddLinguisticVariables(LinguisticVariable* linguisticVariable) {
	linguisticVariablesHashMap.insert(pair<string, LinguisticVariable*>(linguisticVariable->ToString(), linguisticVariable));
	linguisticVariables.push_back(linguisticVariable);
}

/*
 *
 * Used when constructing rules
 *
 */
LinguisticVariable* Experiments::FindLinguisticVariableByName(string variableName) {

#if defined(__GNUC__)
	std::tr1::unordered_map <string, LinguisticVariable*> :: const_iterator iterator;
#else
	hash_map <string, LinguisticVariable*> :: const_iterator iterator;
#endif

	iterator = linguisticVariablesHashMap.find(variableName);
	return (LinguisticVariable*)iterator->second;
}

LinguisticVariable* Experiments::FindLinguisticVariableByNumber(short variableNumber) {
	return linguisticVariables[variableNumber];
}

