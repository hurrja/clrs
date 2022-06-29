CXX=clang
CC=$(CXX)
LDFLAGS= -lstdc++

SOURCES = $(wildcard *.cc)

PROGRAMS = main

CXXFLAGS=-W -Wall

all:	$(PROGRAMS)

clean::
	rm $(PROGRAMS) *.o

depend:
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) > .depend

include .depend 
