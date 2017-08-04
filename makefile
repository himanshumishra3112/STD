# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET=state

all: $(TARGET)

$(TARGET): state.o
	$(CC) state.o  -o $(TARGET)

state.o: state.cpp
	 $(CC) -c state.cpp
clean:
	$(RM) $(TARGET)
	$(RM) $(TARGET).o
