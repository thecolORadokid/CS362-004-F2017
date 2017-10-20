CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme -g testme.c -g $(CFLAGS)


all: testme

clean:
	rm -f *.o testme testme.exe
