#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: Fuzzy

individual:  Link

clean:
	rm *.o
	
Fuzzy: Experiments.cpp Fuzzy.cpp FuzzyCalculator.cpp FuzzyInput.cpp FuzzyLanguageParser.cpp FuzzyReasoner.cpp FuzzyRule.cpp FuzzyRuleToken.cpp LinguisticValue.cpp LinguisticVariable.cpp SingletonValue.cpp stdafx.cpp TrapezoidValue.cpp
	$(GCC) $(CFLAGS) $(HASHMAP) -c $^ -o $@.o
	
Link: Experiments.o Fuzzy.o FuzzyCalculator.o FuzzyInput.o FuzzyLanguageParser.o FuzzyReasoner.o FuzzyRule.o FuzzyRuleToken.o LinguisticValue.o LinguisticVariable.o SingletonValue.o stdafx.o TrapezoidValue.o
	$(GCC) $(CFLAGS) $(HASHMAP) -c $^ -o $@.o
	
%.o: %.cpp
	$(GCC) $(CFLAGS) $(HASHMAP) -c $^