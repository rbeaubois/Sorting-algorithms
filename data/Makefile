# Specify compiler
CC=g++

# Specify linker
LINK=g++

# Build all target
.PHONY : all
all : main

# Link the object files and dependent libraries into a binary
main : main.cpp
	$(LINK) -o main main.cpp

# Compile the source files into object files
main.o : main.cpp
	$(CC) -c main.cpp -o main.o

# Clean target
.PHONY : clean
clean :
	del main.exe
