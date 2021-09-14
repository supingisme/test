CXX = g++
CXXFLAGS = -std=c++11
LIBS = -lncurses
BIN = tetris.exe

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ $(LIBS)

%.o: %.c
	$(CXX) -c $< -o $@ 

clean:
	rm -f *.o
	rm $(BIN)

