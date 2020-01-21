CC=g++ -O2 -Wall
CFLAGS=
LDFLAGS=-L../systemc-2.3.3/lib-linux -lsystemc -lpthread
EXEC=main
SRC=./src/main.cpp \
	./src/DataIn.cpp \
	./src/DataOut.cpp \
	./src/RadixSort.cpp \
	./src/CheckSort.cpp \

OBJ= $(SRC:.cpp=.o)

CFLAGS=

all: $(EXEC)
	./bin/main

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean: $(OBJ)
	rm ./src/*.o

mrproper: clean
	rm $(EXEC)
