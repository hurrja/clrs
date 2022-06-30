CXX=clang++
CC=$(CXX)
LDFLAGS=
CXXFLAGS=-W -Wall

SOURCES = $(wildcard *.cc)

PROGRAMS = main

all:	$(PROGRAMS)

clean:
	rm $(PROGRAMS) *.o

depend:
	$(CXX) -MM $(CXXFLAGS) $(SOURCES) > .depend

include .depend 
