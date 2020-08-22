VPATH = $(SRCDIR):$(wildcard src/*):$(wildcard src/**/*)

BUILDDIR= ./build
INCLUDEDIR= ./include
SRCDIR= ./src
COBJ= input.o main.o output.o process.o randomgen.o
LDARGS= -lncurses

all: game

game: $(COBJ)
	@echo "Linking Final Executable..."
	@(cd build; g++ $(LDARGS) -o game $^)

run: game
	@(cd build; ./game)

%.o: %.cpp
	@echo "Building C++ Objects..."
	@g++ -O2 -c -o build/$@ $<

clean:
	@echo "Clearing files from previous build..."
	@rm -f build/*
