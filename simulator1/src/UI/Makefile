include ../../Makefile.common

all: $(OBJECT_PATH)Buttons.o $(OBJECT_PATH)Control.o $(OBJECT_PATH)ControlField.o $(OBJECT_PATH)Report.o $(OBJECT_PATH)ReportField.o $(OBJECT_PATH)SimulationOutput.o  $(OBJECT_PATH)MainScreen.o
	
clean:
	$(REMOVE_OBJECTS)

$(OBJECT_PATH)%.o: %.cpp
	$(GCC) $(CFLAGS) $(WXFLAGS) -c $^ -o $(OBJECT_PATH)$@