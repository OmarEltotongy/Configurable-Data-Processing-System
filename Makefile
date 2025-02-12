CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = main
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))
all: $(TARGET)
$(TARGET): $(OBJ)
$(CXX) $(CXXFLAGS) -o $@ $^
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
@mkdir -p $(BUILDDIR)
$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@