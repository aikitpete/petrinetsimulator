#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: ConfReader.o FuzzyConfReader.o SimConfReader.o

clean:
	rm *.o

ConfReader.o: ConfReader.cpp
	g++ $(CFLAGS) -c ConfReader.cpp -o $@

FuzzyConfReader.o: FuzzyConfReader.cpp
	g++ $(CFLAGS) -c FuzzyConfReader.cpp -o $@

SimConfReader.o: SimConfReader.cpp
	g++ $(CFLAGS) -c SimConfReader.cpp -o $@