CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -fno-inline -fPIC -fPIE

Aufgabe3: Aufgabe3.o unit.o student.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Aufgabe3.o: Aufgabe3.cpp student.h
	$(CXX) $(CXXFLAGS) -c $<

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f student.o Aufgabe3.o Aufgabe3

.PHONY: clean
