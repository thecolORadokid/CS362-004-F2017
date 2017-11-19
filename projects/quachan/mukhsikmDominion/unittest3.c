/*This file is meant to be a unit test for shuffle()*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	initializeGame(numPlayers, k, seed, &G);
	int initialDeck[10], finalDeck[10];
	printf("Testing shuffling of initial deck...\n\n");
	printf("The deck is initially: ");
	for (int i = 0; i < 10; i++) {
		initialDeck[i] = G.deck[thisPlayer][i];
		printf("%d, ", initialDeck[i]);
	}
	printf("\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	shuffle(thisPlayer, &testG);
	printf("This shuffled deck is: ");
	int compareCounter = 0;
	for (int i = 0; i < 10; i++) {
		finalDeck[i] = testG.deck[thisPlayer][i];
		printf("%d, ", finalDeck[i]);
		if (initialDeck[i] == finalDeck[i]) {
			compareCounter++;
		}
	}
	printf("\n");
	if (compareCounter != 10) {
		printf("Test PASSED> Deck successfully shuffled!\n");
	}
	else if (compareCounter == 10){
		printf("Test FAILED. Decks were not shuffled.\n");
	}
	printf("\n");

	printf("Testing shuffling of a known deck...\n\n");
	printf("The deck is initially: ");
	G.deck[thisPlayer][0] = 4;
	G.deck[thisPlayer][1] = 4;
	G.deck[thisPlayer][2] = 1;
	G.deck[thisPlayer][3] = 4;
	G.deck[thisPlayer][4] = 4;
	G.deck[thisPlayer][5] = 1;
	G.deck[thisPlayer][6] = 4;
	G.deck[thisPlayer][7] = 4;
	G.deck[thisPlayer][8] = 1;
	G.deck[thisPlayer][9] = 4;

	compareCounter = 0;
	for (int i = 0; i < 10; i++) {
		initialDeck[i] = G.deck[thisPlayer][i];
		printf("%d, ", initialDeck[i]);
	}
	printf("\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	shuffle(thisPlayer, &testG);
	printf("This shuffled deck is: ");
	for (int i = 0; i < 10; i++) {
		finalDeck[i] = testG.deck[thisPlayer][i];
		printf("%d, ", finalDeck[i]);
		if (initialDeck[i] == finalDeck[i]) {
			compareCounter++;
		}
	}
	printf("\n");
	if (compareCounter != 10) {
		printf("Test PASSED. Deck successfully shuffled!\n");
	}
	else if (compareCounter == 10) {
		printf("Test FAILED. Decks were not shuffled.\n");
	}
	printf("Testing shuffling of a known deck...\n\n");
	printf("The deck is initially: ");
	G.deck[thisPlayer][0] = 1;
	G.deck[thisPlayer][1] = 2;
	G.deck[thisPlayer][2] = 3;
	G.deck[thisPlayer][3] = 4;
	G.deck[thisPlayer][4] = 5;
	G.deck[thisPlayer][5] = 6;
	G.deck[thisPlayer][6] = 7;
	G.deck[thisPlayer][7] = 8;
	G.deck[thisPlayer][8] = 9;
	G.deck[thisPlayer][9] = 10;

	compareCounter = 0;
	for (int i = 0; i < 10; i++) {
		initialDeck[i] = G.deck[thisPlayer][i];
		printf("%d, ", initialDeck[i]);
	}
	printf("\n");

	memcpy(&testG, &G, sizeof(struct gameState));
	shuffle(thisPlayer, &testG);
	printf("This shuffled deck is: ");
	for (int i = 0; i < 10; i++) {
		finalDeck[i] = testG.deck[thisPlayer][i];
		printf("%d, ", finalDeck[i]);
		if (initialDeck[i] == finalDeck[i]) {
			compareCounter++;
		}
	}
	printf("\n");
	if (compareCounter != 10) {
		printf("Test PASSED. Deck successfully shuffled!\n");
	}
	else if (compareCounter == 10) {
		printf("Test FAILED. Decks were not shuffled.\n");
	}
	return 0;
}