CXX = g++
CXXFLAGS = -Wall -g
test: test.o
	$(CXX) $(CXXFLAGS) -o test test.o
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp
clean: 
	rm test *.o
