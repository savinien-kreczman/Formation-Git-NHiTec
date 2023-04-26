CC = gcc
LD = gcc
CFLAGS = --std=c99 --pedantic -Wall
LDFLAGS =

EXEC = dictionnaire
OBJECTS = main.o dictionnary.o print.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(LD) -g -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c $< -o $@ $(CFLAGS)

dictionnary.o: dictionnary.c
	$(CC) -c $< -o $@ $(CFLAGS)

print.o: print.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~

