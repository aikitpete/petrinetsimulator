#include "Fuzzy.h"

void FuzzyLogicDSL::Init(char* file) {
	//Create instance of Experiments
	experiment = new Experiments();
	FuzzyLanguageParser* p = new FuzzyLanguageParser(experiment);
	p->Parse(file);
}

double FuzzyLogicDSL::Evaluate(double d1, double d2, double d3, double d4, double d5, double d6, short variant) {
	//Hash_map for storing inputs
	vector<FuzzyInput*> fuzzyInputs;

	//Put some values to inputs
	FuzzyInput* input1 = new FuzzyInput(d1);
	FuzzyInput* input2 = new FuzzyInput(d2);
	FuzzyInput* input3 = new FuzzyInput(d3);
	FuzzyInput* input4 = new FuzzyInput(d4);
	FuzzyInput* input5 = new FuzzyInput(d5);
	FuzzyInput* input6 = new FuzzyInput(d6);

	//Insert inputs to the vector
	fuzzyInputs.push_back(input1);
	fuzzyInputs.push_back(input2);
	fuzzyInputs.push_back(input3);
	fuzzyInputs.push_back(input4);
	fuzzyInputs.push_back(input5);
	fuzzyInputs.push_back(input6);

	//Calculate fuzzy Logic output signal
	experiment->CalculateFuzzyRules(fuzzyInputs, variant);

	return experiment->GetOutputValue();
}

void FuzzyLogicDSL::GetResult() {
	//Get some additional informations from fuzzy logic 
	double output = experiment->GetOutputValue();

	double v1 = experiment->GetLinguisticVariableValue(7,1);
	double v2 = experiment->GetLinguisticVariableValue(7,2);
	double v3 = experiment->GetLinguisticVariableValue(7,3);

	double max = 0.0;
	string ret;

	if (v1 > max) {
		max = v1;
		ret = "Low";
	}

	if (v2 > max) {
		max = v2;
		ret = "Avg";
	}

	if (v3 > max) {
		max = v3;
		ret = "Hi";
	}

//#ifdef PRINT
	printf("Val1: %3.4f Val2: %3.4f Val3: %3.4f Dec: %s Cent: %3.4f\n", v1, v2, v3, ret.c_str(), output);
//#endif
}