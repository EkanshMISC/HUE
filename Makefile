exec = hue.exe

sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)

CC = gcc
flags = -g

all: $(exec)

$(exec): $(objects)
	$(CC) $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	$(CC) -c $(flags) $< -o $@

install:
	@if [ ! -d "C:/bin" ]; then mkdir -p "C:/bin"; fi
	cp hue.exe C:/bin/hue.exe


clean:
	del /Q *.exe
	del /Q *.o
	del /Q src\*.o