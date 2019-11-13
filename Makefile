CC = gcc
CFLAGS = -pedantic -Wall

EXECUTABLE = testUnitTest
OBJECT_FILES = unittest.test.o unittest.o

# Executable
testUnitTest: unittest.test.o unittest.o
	$(CC) $(CFLAGS) -o testUnitTest unittest.test.o unittest.o

# Object files
unittest.test.o: tests/unittest.test.c
	$(CC) $(CFLAGS) -c tests/unittest.test.c

unittest.o: unittest.c
	$(CC) $(CFLAGS) -c unittest.c

.PHONY: all, clean

all: $(EXECUTABLE)

clean:
	rm -v $(EXECUTABLE) $(OBJECT_FILES)