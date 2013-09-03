
OBJECTS=tramp.o dcpu.o dcpumanager.o main.o
TARGET=emulator

CCFLAGS=-std=c++11

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	g++ -o $@ $? $(CCFLAGS)

%.o : %.cpp
	g++ -c -o $@ $? $(CCFLAGS)

tramp.o : tramp.asm
	nasm -f elf64 tramp.asm

clean:
	rm $(TARGET) $(OBJECTS) 2>/dev/null
