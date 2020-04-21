CC=gcc
CFLAGS=-Wall
EXECUTABLE=list
list: list.o main.c
	$(CC) $(CFLAGS) list.o main.c -o $(EXECUTABLE)
list.o: list.h 
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
