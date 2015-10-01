include ../Makefile.common

all: binrouting configuration eftswitch petrinet simulation ui utils
	

clean: 
	-(cd BINRouting && $(MAKE) clean)
	-(cd Configuration && $(MAKE) clean)
	-(cd EFTSwitch && $(MAKE) clean)
	-(cd PetriNet && $(MAKE) clean)
	-(cd Simulation && $(MAKE) clean)
	-(cd UI && $(MAKE) clean)
	-(cd Utils && $(MAKE) clean)

binrouting: 
	(cd BINRouting && $(MAKE) all)

configuration: 
	(cd Configuration && $(MAKE) all)

eftswitch: 
	(cd EFTSwitch && $(MAKE) all)

petrinet: 
	(cd PetriNet && $(MAKE) all)

simulation: 
	(cd Simulation && $(MAKE) all)

ui: 
	(cd UI && $(MAKE) all)

utils: 
	(cd Utils && $(MAKE) all)

.PHONY: binrouting configuration eftswitch petrinet simulation ui utils