PROGRAM   = slot
CC        = gcc
CFLAGS    = -g -Wall
LDFLAGS   = -lGL -lGLU -lglut

$(PROGRAM): main.o crtanje.o kordinatni.o image.o osvetljenje.o igrice.o teksture.o
	$(CC) -o $(PROGRAM) main.o crtanje.o kordinatni.o image.o osvetljenje.o igrice.o teksture.o $(LDFLAGS) -lm

kordinatni.o: kordinatni.c
	$(CC) -c $(CFLAGS) -o kordinatni.o kordinatni.c $(LIBS)
crtanje.o: crtanje.c
	$(CC) -c $(CFLAGS) -o crtanje.o crtanje.c $(LIBS)
osvetljenje.o: osvetljenje.c
	$(CC) -c $(CFLAGS) -o osvetljenje.o osvetljenje.c $(LIBS)
igrice.o: igrice.c
	$(CC) -c $(CFLAGS) -o igrice.o igrice.c $(LIBS)
teksture.o: teksture.c
	$(CC) -c $(CFLAGS) -o teksture.o teksture.c $(LIBS)
.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


