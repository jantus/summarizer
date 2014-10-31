CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags) 
LDFLAGS=-g $(shell root-config --ldflags) 
LDLIBS=$(shell root-config --libs) 

SRCS=main.cpp Vertex.cpp Graph.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: tool

tool: $(OBJS)
	g++ $(LDFLAGS) -std=c++11 -o main $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend