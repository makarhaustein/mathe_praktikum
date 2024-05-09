CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
LIBS  = -lGL -lpthread -lX11

all: aufgabe3

aufgabe3.o: aufgabe3.cpp unit.h
	$(CXX) $(CXXFLAGS) -c $<

aufgabe3: aufgabe3.o unit.o IGL.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f aufgabe3 *.o

.PHONY: clean