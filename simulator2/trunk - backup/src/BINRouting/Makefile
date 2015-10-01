#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: BINReader.o BINRouting.o BINTree.o BINTreeNode.o

clean:
	rm *.o

BINReader.o: BINReader.cpp
	g++ $(CFLAGS) -c BINReader.cpp -o $@

BINRouting.o: BINRouting.cpp
	g++ $(CFLAGS) -c BINRouting.cpp -o $@

BINTree.o: BINTree.cpp
	g++ $(CFLAGS) -c BINTree.cpp -o $@

BINTreeNode.o: BINTreeNode.cpp
	g++ $(CFLAGS) -c BINTreeNode.cpp -o $@