CXX = g++
EXE = GenArt
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)
DEP = $(OBJ:%.o=%.d)
CPPFLAGS = -Iinclude -Wfatal-errors -Wall -MMD
LDFLAGS = -Llib
LDLIBS = -lglfw -lGLEW -lGL

default: $(EXE)
all: $(EXE)


$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(LDFLAGS) $(OBJ) $(LDLIBS)

-include $(DEP)

build/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm $(EXE) $(OBJ)


