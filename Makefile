CXX=clang++
STD=c++17
CXXFLAGS=-I./headers

BINS=bins/test
SO_FILE=objs/solver.so

SRCS=$(wildcard ./src/*.cpp)

$(SO_FILE): $(SRCS)
	$(CXX) -std=$(STD) -L. -shared -fPIC $(CXXFLAGS) -o $@ $(SRCS)

$(BINS): Tester.cpp
	$(CXX) -std=$(STD) $(CXXFLAGS) $< -o $@