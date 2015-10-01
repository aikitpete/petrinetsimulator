include ../../Makefile.common

all: $(OBJECT_PATH)Routing.o $(OBJECT_PATH)SinkNode.o $(OBJECT_PATH)SourceNode.o

clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) -c $^ -o $(OBJECT_PATH)$@