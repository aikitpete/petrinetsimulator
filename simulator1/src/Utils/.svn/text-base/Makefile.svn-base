include ../../Makefile.common

all: $(OBJECT_PATH)Observer.o $(OBJECT_PATH)Singleton.o

clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) -c $^ -o $(OBJECT_PATH)$@