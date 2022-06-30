CXX=clang++
CC=$(CXX)
LDFLAGS=
CXXFLAGS=-Wall -Wextra

SOURCES = $(wildcard *.cc)

PROGRAMS = main

all:	$(PROGRAMS)

clean:
	rm $(PROGRAMS) *.o

depend:
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) > .depend

include .depend 
