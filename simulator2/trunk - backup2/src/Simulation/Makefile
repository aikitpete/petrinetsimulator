include ../../Makefile.common

all: $(OBJECT_PATH)BINGenerator.o $(OBJECT_PATH)Filter.o $(OBJECT_PATH)Generator.o $(OBJECT_PATH)SimTime.o $(OBJECT_PATH)stopWatch.o $(OBJECT_PATH)Thread.o $(OBJECT_PATH)Times.o $(OBJECT_PATH)Handler.o $(OBJECT_PATH)GeneratorManager.o $(OBJECT_PATH)Statistics.o $(OBJECT_PATH)SimulationManager.o $(OBJECT_PATH)Logger.o
	
clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) $(WXFLAGS) -c $^ -o $(OBJECT_PATH)$@