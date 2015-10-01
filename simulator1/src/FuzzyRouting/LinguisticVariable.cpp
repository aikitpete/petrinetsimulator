#include "LinguisticVariable.h"

namespace FuzzyLogic {

	//Default constructor
	LinguisticVariable::LinguisticVariable(bool nOutput, string nVariableName, short nVariableNumber) {
                output = nOutput;
				variableName = nVariableName;
                variableNumber = nVariableNumber;
        }

        //Destructor
        LinguisticVariable::~LinguisticVariable(void) {
                //Release all LinguisticValue objects
#if defined(__GNUC__)
                std::tr1::unordered_map<string, LinguisticValue*>::const_iterator iterator;
#else
				hash_map<string, LinguisticValue*>::const_iterator iterator;
#endif
				iterator = linguisticValuesHashMap.begin();
                while(iterator != linguisticValuesHashMap.end())
                {
                        //Repeat until the end
                        LinguisticValue* temp = (LinguisticValue*)iterator->second;
                        //Remove item from hash table
                        linguisticValuesHashMap.erase(iterator);
                        //Move to first item of hash table
                        iterator = linguisticValuesHashMap.begin();
                        //Delete LinguisticValue object
                        delete temp;
                }
        }

	//Methods
	//Method add Linguistic value to hah map
	void LinguisticVariable::AddLinguisticValue(LinguisticValue* linguisticValue) {
		linguisticValuesHashMap.insert(pair<string, LinguisticValue*>(linguisticValue->ToString(), linguisticValue));
	}

	void LinguisticVariable::ResetLinguisticValues() {
		//Just for reseting linguistic values
#if defined(__GNUC__)
		std::tr1::unordered_map<string, LinguisticValue*> :: const_iterator iterator;
#else
		hash_map<string, LinguisticValue*> :: const_iterator iterator;
#endif
		iterator = linguisticValuesHashMap.begin();
		while(iterator != linguisticValuesHashMap.end())
		{
			//Repeat until the end
			LinguisticValue* temp = (LinguisticValue*)iterator->second;
			temp->SetLinguisticValue(-1);
			iterator++;
		}
	}

	LinguisticValue* LinguisticVariable::FindLinguisticValueByName(string name) {
		//Define iterator
#if defined(__GNUC__)
		std::tr1::unordered_map<string, LinguisticValue*> :: const_iterator iterator;
#else
		hash_map<string, LinguisticValue*>::const_iterator iterator;
#endif
		//Fint linguistic value by name
		iterator = linguisticValuesHashMap.find(name);
		if(iterator == linguisticValuesHashMap.end())
		{
			assert(NULL);
			return NULL;
		}
		//Return LinguisticValue
		return (LinguisticValue*)iterator->second;
	}

	LinguisticValue* LinguisticVariable::FindLinguisticValueByNumber(short number) {

		LinguisticValue* temp = linguisticValues[number];

		//Return LinguisticValue
		return temp;
	}

	vector<LinguisticValue*> LinguisticVariable::GetLinguisticValuesList() {
		vector<LinguisticValue*> linguisticValuesList;

#if defined(__GNUC__)
		std::tr1::unordered_map <string, LinguisticValue*> :: const_iterator iterator;
#else
		hash_map <string, LinguisticValue*> :: const_iterator iterator;
#endif
		iterator = linguisticValuesHashMap.begin();
		while(iterator != linguisticValuesHashMap.end())
		{
			//Repeat until the end
			LinguisticValue* temp = (LinguisticValue*)iterator->second;
			//Remove item from hash table
			linguisticValuesList.push_back(temp);
			iterator++;
		}
		return linguisticValuesList;
	}

	double LinguisticVariable::CalculateLinguisticValueByName(string name, double input) {
		LinguisticValue* value = FindLinguisticValueByName(name);
		return value->CalculateLinguisticValue(input);
	}

	//Update Linguistic value by name
	void LinguisticVariable::UpdateLinguisticValueByName(string name, double newVal) {
		//Find LinguisticValue
		LinguisticValue* value = FindLinguisticValueByName(name);

		//If there is value, we should perform operator OR
		if(value->GetLinguisticValue() != -1)
			value->SetLinguisticValue(FuzzyCalculator::OR(value->GetLinguisticValue(), newVal));
		else
			value->SetLinguisticValue(newVal); //There is no value, just set newVal
	}


	//Getters
	bool LinguisticVariable::IsOutputVariable() {
		return output;
	}

	short LinguisticVariable::GetNumber() {
		return variableNumber;
	}

	string LinguisticVariable::ToString() {
		return variableName;
	}
}