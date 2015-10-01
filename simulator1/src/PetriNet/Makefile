include ../../Makefile.common

all: $(OBJECT_PATH)Token.o $(OBJECT_PATH)Node.o $(OBJECT_PATH)Place.o $(OBJECT_PATH)Transition.o $(OBJECT_PATH)PNFactory.o $(OBJECT_PATH)PetriNetManager.o 
	
clean:
	

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) $(WXFLAGS) -c $^ -o $(OBJECT_PATH)$@