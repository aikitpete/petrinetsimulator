include ../../Makefile.common

all: $(OBJECT_PATH)ConfReader.o $(OBJECT_PATH)FuzzyConfReader.o $(OBJECT_PATH)SimConfReader.o

clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) -c $^ -o $(OBJECT_PATH)$@