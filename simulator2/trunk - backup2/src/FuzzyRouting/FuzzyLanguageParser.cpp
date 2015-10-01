#include "FuzzyLanguageParser.h"

using namespace FuzzyLogic;

FuzzyLanguageParser::FuzzyLanguageParser(Experiments* nFuzzyInterface) {
	fuzzyInterface = nFuzzyInterface;
	fuzzyInterface->SetLinguisticVariablesSize(LINGUISTIC_SIZE);
}

FuzzyLanguageParser::~FuzzyLanguageParser(void) {
}

void FuzzyLanguageParser::Parse(char* filePath) {
	current = 1;
	ifstream ifs(filePath);
	string line;
	while( getline( ifs, line ) )
	{

#ifdef PRINT

		cout << line << endl;

#endif

		vector<string> tokens = SplitBy(line,' ');
		//Skip lines without text
		if(tokens.size() > 0)
		{
			//Skip comments
			if(!IsComment(tokens[0]))
			{
				if(IsRule(tokens[0]))
					ParseFuzzyRule(tokens);
				else
					ParseFuzzyAtribute(tokens);
			}
		}
	}
	//Close stream
	ifs.close();
}

//Check is line is comment
bool FuzzyLanguageParser::IsComment(string token) {
	//Return true if is comment
	if(token.at(0) == '%')
		return true;
	return false;
}

bool FuzzyLanguageParser::IsRule(string token) {
	//Return true if is rule
	if(token == "IF")
		return true;
	return false;
}

void FuzzyLanguageParser::ParseFuzzyRule(vector<string> ruleTokens) {
	//Rule example
	//IF distance = low AND approaching NOT slow THEN signal=breake
	//SKIP IF token
	bool negated = false;
	string leftSide;
	string rightSide;
	Operation operation = EMPTY; 
	FuzzyRule* rule = new FuzzyRule();

	for(unsigned int i = 1; i < ruleTokens.size(); i++)
	{
		//Check for operator
		//OPERATORS =, Operator(AND, OR), NOT, THEN
		if((ruleTokens[i] == "AND") || (ruleTokens[i] == "OR"))
		{
			if(ruleTokens[i] == "AND")
				operation = AND;
			else
				operation = OR;
		}
		else if((ruleTokens[i] == "=") || (ruleTokens[i] == "NOT"))
		{
			leftSide = ruleTokens[i - 1];
			//Next token is right side
			if(ruleTokens[i] == "NOT")
				negated = true;
			rightSide = ruleTokens[++i];

			//ADD TOKEN TO RULE
			LinguisticVariable* linVar = fuzzyInterface->FindLinguisticVariableByName(leftSide);
			assert(linVar != NULL);
			rule->AddTokenToRule(new FuzzyRuleToken(negated,operation,linVar,rightSide));
			//RESET
			operation = EMPTY;
			negated = false;
		}
	}
	fuzzyInterface->AddFuzzyRule(rule);
}

void FuzzyLanguageParser::ParseFuzzyAtribute(vector<string> attTokens) {
	//Distance Input Low (0,0,1,2) Average (1,2,3,4) High (3,4,5,5)
	//Linguistic variable name
	//Input or output 
	//Linguistic value name
	//Values A,B,C,D
	string linguisticVariableName = attTokens.at(0);
	bool output = true;
	if (attTokens.at(1) == "Input")
		output = false;
	//Creating new linguistic variable
	LinguisticVariable *linguisticVariable = new LinguisticVariable(output, linguisticVariableName, current);
	current++;

	//Adding linguistic values to variable
	for(unsigned int i = 2; i < attTokens.size(); i++)
	{
		string linguisticValueName = attTokens.at(i++);
		vector<double> linguisticValues = ParseLinguisticValues(attTokens.at(i));
		LinguisticValue* linValue;
		if (linguisticValues.size() == 4) {
			//Use trapezodial function
			linValue = new TrapezoidValue(linguisticValueName,
			linguisticValues[0],
			linguisticValues[1],
			linguisticValues[2],
			linguisticValues[3]);
		} else if (linguisticValues.size() == 1) {
			//Use singleton function
			linValue = new SingletonValue(linguisticValueName,
			linguisticValues[0]);
		}
		linguisticVariable->AddLinguisticValue(linValue);
	}
	fuzzyInterface->AddLinguisticVariables(linguisticVariable);
}

vector<double> FuzzyLanguageParser::ParseLinguisticValues(string token) {
	vector<double> linguisticValues;
	//Remove first and last char
	token = token.erase(0,1);
	token = token.erase(token.size() - 1, 1);
	vector<string> values = SplitBy(token, ',');

	//Values size should be 4!
	for(unsigned int i = 0; i < values.size(); i++)
		linguisticValues.push_back(strtod(values.at(i).c_str(),NULL));
	return linguisticValues;
}

//Function that split line by given char
vector<string> FuzzyLanguageParser::SplitBy(string line, char splitter) {
	vector<string> tokens;
	string token;
	for(unsigned int i = 0; i < line.size(); i++)
	{
		if(line.at(i) == splitter)
		{
			tokens.push_back(token);
			token = "";
		}
		else
			token += line.at(i);
	}
	//Add last possible token
	if(token.size() > 0)
		tokens.push_back(token);
	return tokens;
}
