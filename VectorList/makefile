MAINPROG=vector_list

SOURCES:=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
# FLAGS=-std=c++17 -fsanitize=leak,address -Wall -Wpedantic -fuse-ld=gold
FLAGS=-std=c++17 -O3

all: $(SOURCES) $(MAINPROG)

$(MAINPROG): $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $@ $(LFLAGS)

.cpp.o:
	g++ $(FLAGS) -c $< -o $@

clean:
	rm *.o $(MAINPROG)
