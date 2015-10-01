#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: Buttons.o Control.o ControlField.o Report.o ReportField.o SimulationOutput.o  MainScreen.o MyApp.o

clean:
	rm *.o

Buttons.o: Buttons.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c Buttons.cpp -o $@

Control.o: Control.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c Control.cpp -o $@

ControlField.o: ControlField.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c ControlField.cpp -o $@
	
Report.o: Report.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c Report.cpp -o $@
	
ReportField.o: ReportField.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c ReportField.cpp -o $@
	
SimulationOutput.o: SimulationOutput.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c SimulationOutput.cpp -o $@
	
#Dependencies

MainScreen.o: MainScreen.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c MainScreen.cpp -o $@
	
MyApp.o: MyApp.cpp
	g++ $(CFLAGS) $(WXFLAGS) -c MyApp.cpp -o $@