CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

unittestresult.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c

	echo "unittest1.c:" >> unittestresult.out
	gcc -o unittest1 -g unittest1.c -g dominion.o rngs.o  $(CFLAGS)
	unittest1 >> unittestresult.out
	gcov unittest1.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest2.c:" >> unittestresult.out
	gcc -o unittest2 -g unittest2.c -g dominion.o rngs.o  $(CFLAGS)
	unittest2 >> unittestresult.out
	gcov unittest2.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest3.c:" >> unittestresult.out
	gcc -o unittest3 -g unittest3.c -g dominion.o rngs.o  $(CFLAGS)
	unittest3 >> unittestresult.out
	gcov unittest3.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "unittest4.c:" >> unittestresult.out
	gcc -o unittest4 -g unittest4.c -g dominion.o rngs.o  $(CFLAGS)
	unittest4 >> unittestresult.out
	gcov unittest4.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest1.c:" >> unittestresult.out
	gcc -o cardtest1 -g cardtest1.c -g dominion.o rngs.o  $(CFLAGS)
	cardtest1 >> unittestresult.out
	gcov cardtest1.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest2.c:" >> unittestresult.out
	gcc -o cardtest2 -g cardtest2.c -g dominion.o rngs.o  $(CFLAGS)
	cardtest2 >> unittestresult.out
	gcov cardtest2.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest3.c:" >> unittestresult.out
	gcc -o cardtest3 -g cardtest3.c -g dominion.o rngs.o  $(CFLAGS)
	cardtest3 >> unittestresult.out
	gcov cardtest3.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

	echo "cardtest4.c:" >> unittestresult.out
	gcc -o cardtest4 -g cardtest4.c -g dominion.o rngs.o  $(CFLAGS)
	cardtest4 >> unittestresult.out
	gcov cardtest4.c -b >> unittestresult.out
	gcov dominion.c >> unittestresult.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c -g dominion.o rngs.o  $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c -b >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c -g dominion.o rngs.o  $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c -b >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c -g dominion.o rngs.o  $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittests: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 unittestresult.out

randomtests: randomtestcard1 randomtestcard2 randomtestadventurer randomtestcard1.out randomtestcard2.out randomtestadventurer.out

all: playdom unittests randomtests

clean:
	rm -f *.o playdom.exe playdom *.gcov *.gcda *.gcno *.so *.out cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 cardtest1.exe cardtest2.exe cardtest3.exe cardtest4.exe unittest1.exe unittest2.exe unittest3.exe unittest4.exe randomtestcard1 randomtestcard2 randomtestadventurer randomtestcard1.exe randomtestcard2.exe randomtestadventurer.exe
