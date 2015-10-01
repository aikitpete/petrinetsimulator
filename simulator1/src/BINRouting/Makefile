include ../../Makefile.common

all: $(OBJECT_PATH)BINReader.o $(OBJECT_PATH)BINRouting.o $(OBJECT_PATH)BINTree.o $(OBJECT_PATH)BINTreeNode.o

clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) -c $^ -o $(OBJECT_PATH)$@