CXX=g++
CXXFLAGS=-Wall -std=c++17

scanner: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o scanner

clean:
	rm -f scanner
