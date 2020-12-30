.SILENT: all clean compile run
all: clean compile run

APP_NAME=csr1
CXX=clang++
CXXFLAGS=-O3 -DNDEBUG -Wall -Wextra -Werror -pedantic
SRC=main.cxx

clean:
	rm -rf *.o *.exe

compile:
	$(CXX) $(CXXFLAGS) -o $(APP_NAME).exe $(SRC)

run: ./$(APP_NAME).exe
	./$(APP_NAME).exe