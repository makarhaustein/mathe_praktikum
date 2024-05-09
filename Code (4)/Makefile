CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
LIBS  = -lGL -lpthread -lX11

all: quadratur

quadratur.o: quadratur.cpp unit.h
	$(CXX) $(CXXFLAGS) -c $<

quadratur: quadratur.o unit.o IGL.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f quadratur *.o

.PHONY: clean