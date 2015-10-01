include ../../Makefile.common

all: $(OBJECT_PATH)Experiments.o $(OBJECT_PATH)Fuzzy.o $(OBJECT_PATH)FuzzyCalculator.o $(OBJECT_PATH)FuzzyInput.o $(OBJECT_PATH)FuzzyLanguageParser.o $(OBJECT_PATH)FuzzyReasoner.o $(OBJECT_PATH)FuzzyRule.o $(OBJECT_PATH)/FuzzyRuleToken.o $(OBJECT_PATH)/LinguisticValue.o $(OBJECT_PATH)LinguisticVariable.o $(OBJECT_PATH)SingletonValue.o $(OBJECT_PATH)stdafx.o $(OBJECT_PATH)TrapezoidValue.o

clean:
	
	
$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) $(HASHMAP) -c $^ -o $(OBJECT_PATH)$@