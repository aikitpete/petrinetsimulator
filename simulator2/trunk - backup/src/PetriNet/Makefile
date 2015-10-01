#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: Token.o Node.o Place.o Transition.o PNFactory.o PetriNetManager.o 

clean:
	rm *.o

Token.o: Token.cpp
	g++ $(CFLAGS) -c Token.cpp -o $@
	
#Dependencies

Node.o: Node.cpp
	$(GCC) $(CFLAGS) $(WXFLAGS) -c Token.o Node.cpp -o $@
	
Place.o: Place.cpp
	$(GCC) $(CFLAGS) $(WXFLAGS) -c Node.o Place.cpp -o $@
	
Transition.o: Transition.cpp ../Simulation/SimulationManager.o ../FuzzyRouting/Fuzzy..0
	$(GCC) $(CFLAGS) $(WXFLAGS) -c Node.o $^ -o $@
	
PNFactory.o: PNFactory.cpp
	$(GCC) $(CFLAGS) -c Node.o Place.o Transition.o PNFactory.cpp -o $@
	
PetriNetManager.o: PetriNetManager.cpp
	$(GCC) $(CFLAGS) -c PetriNetManager.cpp -o $@