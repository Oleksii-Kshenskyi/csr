.SILENT: all clean compile run
all: clean compile run

APP_NAME=csr1
ARGS=random_crap.conf
CXX=clang++
CXXFLAGS=-O3 -DNDEBUG -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Werror -pedantic -std=c++17
INCDIR=include
SRCDIR=src
SRC=$(SRCDIR)/parse.cxx $(SRCDIR)/strwrap.cxx $(SRCDIR)/vecwrap.cxx $(SRCDIR)/util.cxx $(SRCDIR)/cli.cxx $(SRCDIR)/main.cxx 

clean:
	rm -rf *.o *.exe

compile:
	$(CXX) $(CXXFLAGS) -o $(APP_NAME).exe -I$(INCDIR) $(SRC)

run: ./$(APP_NAME).exe
	./$(APP_NAME).exe $(ARGS)