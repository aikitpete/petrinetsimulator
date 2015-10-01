#pragma once

#include <assert.h>

//#if !defined(__CYGWIN32__)
#include <vector>
//#endif

#if defined(__GNUC__)
//#if !defined(__CYGWIN32__)
#include <tr1/unordered_map>
//#endif
#else
#include <hash_map>
#endif

#include "LinguisticValue.h"
#include "FuzzyCalculator.h"

using namespace std;

namespace FuzzyLogic{

	class LinguisticVariable
	{
	private:
		//Variable number
		short variableNumber;

		//Variable name
		string variableName;

		//Is variable input or output
		bool output;

		//Hash table of linguistic values
#if defined(__GNUC__)
		std::tr1::unordered_map<string, LinguisticValue*>linguisticValuesHashMap;
#else
		hash_map<string, LinguisticValue*>linguisticValuesHashMap;
#endif
		LinguisticValue** linguisticValues;

	public:

		//Default constructor
		LinguisticVariable(bool nOutput, string nVariableName, short nVariableNumber);

		//Destructor
		~LinguisticVariable(void);

		//Methods
		//Method add Linguistic value to hash map
		void AddLinguisticValue(LinguisticValue* linguisticValue);

		void ResetLinguisticValues();

		LinguisticValue* FindLinguisticValueByName(string name);
		LinguisticValue* FindLinguisticValueByNumber(short number);

		vector<LinguisticValue*> GetLinguisticValuesList();

		double CalculateLinguisticValueByName(string name, double input);
		double CalculateLinguisticValueByNumber(short number, double input);

		//Update Linguistic value
		void UpdateLinguisticValueByName(string name, double newVal);
		void UpdateLinguisticValueByNumber(short number, double newVal);


		//Getters
		bool IsOutputVariable();
		short GetNumber();
		string ToString();
	};
}