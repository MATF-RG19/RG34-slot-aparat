PROGRAM   = 01
CC        = gcc
CFLAGS    = -g -Wall
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): main.o crtanje.o kordinatni.o
	$(CC) -o $(PROGRAM) main.o crtanje.o kordinatni.o $(LDFLAGS) -lm

kordinatni.o: kordinatni.c
	$(CC) -c $(CFLAGS) -o kordinatni.o kordinatni.c $(LIBS)
	
crtanje.o: crtanje.c
	$(CC) -c $(CFLAGS) -o crtanje.o crtanje.c $(LIBS)
# congrats.o: congrats.c
# 	$(CC) -c $(CFLAGS) -o congrats.o congrats.c $(LIBS)
	
.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


