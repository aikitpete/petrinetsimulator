include Makefile.common

all: src
	

clean: 
	-(cd $(SOURCE_PATH) && $(MAKE) clean)

src: 
	(cd $(SOURCE_PATH) && $(MAKE) all)
	$(GCC) $(WXFLAGS) $(SOURCE_PATH)MyApp.cpp $(SOURCE_PATH)PetriNet/PNFactory.o $(SOURCE_PATH)PetriNet/PetriNetManager.o $(SOURCE_PATH)Utils/Observer.o $(SOURCE_PATH)Simulation/Logger.o $(SOURCE_PATH)FuzzyRouting/Fuzzy.o $(SOURCE_PATH)UI/MainScreen.o $(WXLINKER) -o $(BUILD_PATH)$(FILENAME)
	
once:
	$(GCC) $(WXFLAGS) $(SOURCE_PATH)MyApp.cpp $(WXLINKER) -o $(BUILD_PATH)$(FILENAME)

libs:
	$(GCC) $(WXFLAGS) $(SOURCE_PATH)MyApp.cpp $(SOURCE_PATH)PetriNet/PNFactory.o $(SOURCE_PATH)PetriNet/PetriNetManager.o $(SOURCE_PATH)Utils/Observer.o $(SOURCE_PATH)Simulation/Logger.o $(SOURCE_PATH)FuzzyRouting/Fuzzy.o $(SOURCE_PATH)UI/MainScreen.o $(WXLINKER) -L$(SOURCE_PATH)PetriNet -L$(SOURCE_PATH)EFTSwitch -L$(SOURCE_PATH)Configuration -L$(SOURCE_PATH)Simulation -L$(SOURCE_PATH)UI -L$(SOURCE_PATH)Utils -L$(SOURCE_PATH)FuzzyRouting -L$(SOURCE_PATH)BINRouting -o $(BUILD_PATH)$(FILENAME)

.PHONY: src