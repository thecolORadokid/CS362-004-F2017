/*This file tests the smithy card functionality*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main() {
	struct gameState G, testG;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	initializeGame(2, k, 10, &G);
	G.hand[0][0] = smithy;
	memcpy(&testG, &G, sizeof(struct gameState));
	int initialNumCards = testG.handCount[0];
	printf("Testing Smithy... \n\n");
	printf("Testing initial number of cards in hand...\n");
	printf("Initial number of cards in hand: %d, Expected %d. \n", initialNumCards, initialNumCards);
	if (initialNumCards == 5) {
		printf("Test PASSED. Correct number of cards to begin with.\n\n");
	}
	else {
		printf("Test FAILED. Incorrect number of starting cards.\n\n");
	}
	smithyCard(0, &testG, 1);
	printf("Calling smityCard()...\n");
	printf("Final number of cards in hand: %d, Expected %d\n", testG.handCount[0], initialNumCards + 2);
	if (testG.handCount[0] == initialNumCards + 2) {
		printf("Test PASSED. Correct number of cards drawn.");
	}
	else {
		printf("TEST FAILED! Incorrect number of cards in hand. \n");
	}
	return 0;
}