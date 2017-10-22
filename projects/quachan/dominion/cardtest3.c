/*This file is a unit test for the Embargo card.*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	//Test to see if the correct number of coins was given to the player
	int totalSupplies = sizeof(testG.supplyCount) / sizeof(testG.supplyCount[0]);
	printf("Testing embargoCard()...\n\n");
	printf("Testing function at every supply position...\n");
	for (int i = 0; i < totalSupplies; i++) {
		G.hand[thisPlayer][0] = embargo;
		G.hand[thisPlayer][0] = copper;
		G.hand[thisPlayer][0] = copper;
		G.hand[thisPlayer][0] = estate;
		G.hand[thisPlayer][0] = copper;
		memcpy(&testG, &G, sizeof(struct gameState));
		int initialNumCoins = testG.coins;
		int initialNumCards = testG.handCount[thisPlayer];
		cardEffect(embargo, i, choice2, choice3, &testG, handpos, &bonus);
		if (testG.embargoTokens[i] == 1) {
			printf("Test PASSED! Embargo token placed correctly for card %d.\n", i);
		}
		else if (testG.supplyCount[i] == -1) {
			printf("No card supply for card %d\n", i);
		}
		else {
			printf("TEST FAILED! No embargo token place for card %d.\n", i);
		}
	}

	memcpy(&testG, &G, sizeof(struct gameState));
	int initialNumCoins = testG.coins;
	int initialNumCards = testG.handCount[thisPlayer];
	cardEffect(embargo, choice1, choice2, choice3, &testG, handpos, &bonus);
	//check to see if action was executed correctly

	printf("\n Testing coin functionality...\n");
	if (testG.coins != initialNumCoins + 2) {
		printf("Test FAILED! Incorrect number of coins given.\n");
	}
	if (testG.coins == initialNumCoins +2){
		printf("Test PASSED! Correct number of coins given.\n");
	}
	// check to see if clean up stage was correct
	printf("\n Testing discard functionality. \n");
	if (testG.handCount[0] != initialNumCards - 1) {
		printf("Test FAILED! Improper discard functionality.\n");
	}
	if (testG.handCount[0] == initialNumCards - 1) {
		printf("Test PASSED! Proper discard functionality.\n");
	}
	return 0;
}