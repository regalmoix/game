VPATH = $(SRCDIR):$(wildcard src/*):$(wildcard src/**/*)

BUILDDIR= ./build
INCLUDEDIR= ./include
SRCDIR= ./src

CCARGS= -lncurses -I $(INCLUDEDIR)

all: game

game:
	g++ $(CCARGS) -o $(BUILDDIR)/game $(SRCDIR)/main.cpp

clean:
	rm -f game outputfile test
