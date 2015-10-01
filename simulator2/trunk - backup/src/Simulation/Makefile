#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: BINGenerator.o Filter.o Generator.o Handler.o SimTime.o stopWatch.o Thread.o Times.o GeneratorManager.o Statistics.o SimulationManager.o Logger.o

clean:
	rm *.o

BINGenerator.o: BINGenerator.cpp
	g++ $(CFLAGS) -c BINGenerator.cpp -o $@

Filter.o: Filter.cpp
	g++ $(CFLAGS) -c Filter.cpp -o $@

Generator.o: Generator.cpp
	g++ $(CFLAGS) -c Generator.cpp -o $@

Handler.o: Handler.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c Handler.cpp -o $@
	
SimTime.o: SimTime.cpp
	g++ $(CFLAGS) -c SimTime.cpp -o $@
	
stopWatch.o: stopWatch.cpp
	g++ $(CFLAGS) -c stopWatch.cpp -o $@
	
Thread.o: Thread.cpp
	g++ $(CFLAGS) -c Thread.cpp -o $@
	
Times.o: Times.cpp
	g++ $(CFLAGS) -c Times.cpp -o $@

#Dependencies

GeneratorManager.o: GeneratorManager.cpp ../PetriNet/Node.o ../PetriNet/Token.o ../PetriNet/PNFactory.o
	g++ $(CFLAGS) -c  $^ -o $@
	
Statistics.o: Statistics.cpp
	g++ $(CFLAGS) -c Statistics.cpp -o $@
	
SimulationManager.o: SimulationManager.cpp Statistics.o
	g++ $(CFLAGS) -c $^ -o $@
	
Logger.o: Logger.cpp
	g++ $(CFLAGS) -c ../UI/MainScreen.o Logger.cpp -o $@