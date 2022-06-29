SHELL=/bin/bash
CXX=clang
LDFLAGS= -lstdc++

OBJECTS = main.o
SOURCES = main.C

PROGRAMS = max-subarray

CXXFLAGS=-W -Wall

all:	$(PROGRAMS)

max-subarray:	$(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

clean::
	rm $(PROGRAMS) *.o

depend:
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) > .depend

include .depend 
