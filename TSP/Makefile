CXXFLAGS := -std=c++11 -g -Wall -Werror
CXX := g++
TARGETS := TSP

all: $(TARGETS)

TSP: TSP.o 
	g++ $(CXXFLAGS) -o $@ $^

TSP.o: TSP.cpp TSP.h

clean:
	-rm -f *~
	-rm -f *.o

spotless: clean
	-rm -f $(TARGETS)
