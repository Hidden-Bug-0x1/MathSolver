CXX=clang++
STD=c++17
CXXFLAGS=-I./headers

BINS=bins/test
SO_FILE=objs/solver.so

SRCS=$(wildcard ./src/*.cpp)

$(SO_FILE): $(SRCS)
	$(RM) $(SO_FILE)
	$(CXX) -std=$(STD) -L. -shared -fPIC $(CXXFLAGS) -o $@ $^

$(BINS): $(SO_FILE)
	$(CXX) -std=$(STD) $(CXXFLAGS) -o $(BINS) $(SO_FILE) Tester.cpp