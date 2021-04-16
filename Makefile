CXX=clang++
STD=c++17
CXXFLAGS=-I./headers

DIR_HEADER=headers
HEADERS=$(wildcard $(DIR_HEADER)/*.h)

DIR_SRC=src 
SRCS=$(wildcard ./src/*.cpp)

DIR_OBJ=objs
OBJS=$(patsubst $(DIR_OBJ)/%.o, $(DIR_SRC)/%.cpp, $(SRCS))

DIR_BIN=bins
BINS=$(DIR_BIN)/test
# $(OJBS)
$(OBJS): $(SRCS)
	@echo "$(wildcard ./src/*.cpp)"
	@echo "Inside make objects"
	$(CXX) -std=$(STD) $(CXXFLAGS) $< -o $@

# $(BINS): $(OJBS)
# 	$(CXX) -std=$(STD) $(DIR_OBJ)/%.o -o $@

clean:
	$(RM) $(DIR_OBJ)/* $(DIR_BIN)/*