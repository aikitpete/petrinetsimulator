#Define variables
GCC=g++
CFLAGS=-Wall -O2
WXFLAGS=`wx-config --cxxflags --debug=yes`
WXLINKER=`wx-config --cxxflags --libs --debug=yes`
HASHMAP=--std=gnu++0x

all: Routing.o SinkNode.o SourceNode.o

clean:
	rm *.o

Routing.o: Routing.cpp
	g++ $(CFLAGS) -c Routing.cpp -o $@

SinkNode.o: SinkNode.cpp
	g++ $(CFLAGS) -c SinkNode.cpp -o $@

SourceNode.o: SourceNode.cpp
	g++ $(CFLAGS) -c SourceNode.cpp -o $@