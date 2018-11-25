CXX = g++

HDRDIR = include
SRCDIR = src
OBJDIR = obj
EXE = GenArt

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
CPPFLAGS = -I$(HDRDIR) -Wfatal-errors -Wall
LDFLAGS = -Llib
LDLIBS = -lglfw -lGLEW -lGL

default: $(EXE)
all: $(EXE)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CPPFLAGS)

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(LDFLAGS) $(OBJ) $(LDLIBS)

clean:
	rm $(EXE) $(OBJ)


