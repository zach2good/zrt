.PHONY: clean

# Declaration of variables
CC = g++
CC_FLAGS = -O2 -std=c++11 -Wall
 
# File names
EXEC = run.exe
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) && $(EXEC)
 
# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm $(EXEC) && rm -f $(OBJECTS)