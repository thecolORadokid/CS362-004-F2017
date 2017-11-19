#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int checkSteward(int currentPlayer, struct gameState *state, int choice1, int choice2, int choice3, int handPos, int initialHandCount, int initialCoins, int seed) {
	//int result = stewardCard(currentPlayer, state, choice1, choice2, choice3, handPos);
	int *bonus = 0;
	int result = cardEffect(steward, choice1, choice2, choice3, state, handPos, &bonus);
	assert(result == 0 && "Seed: %d, Failed to execute");

	if (choice1 == 1) {
		if (state->handCount[currentPlayer] != (initialHandCount + 1)) {
			printf("Seed: %d, test failed, incorrect number of cards in hand.", seed);
			printf("%d cards in hand. Expected %d.\n", state->handCount[currentPlayer], initialHandCount +1);
			return 1;
		}
		else {
			printf("Seed: %d, test passed.\n", seed);
			return 0;
		}
	}
	else if (choice1 == 2) {
		if (state->coins != initialCoins + 2) {
			printf("Seed: %d, test failed, incorrect number of coins.", seed);
			printf("%d coins. Expected %d.\n", state->coins, initialCoins+2);
			return 1;
		}
		else {
			printf("Seed: %d, test passed.\n", seed);
			return 0;
		}
	}
	else if (choice1 == 3) {
		if (state->handCount[currentPlayer] != initialHandCount - 3) {
			printf("Seed: %d, Choice: %d, test failed. Incorrect number of cards in hand.", seed, choice1);
			printf("%d cards in hand. Expected %d.\n", state->handCount[currentPlayer], initialHandCount - 3);
			return 1;
		}
		else {
			printf("Seed: %d, test passed.\n", seed);
			return 0;
		}
	}
}

int main() {
	srand(time(NULL));
	int i,j, n, seed, choice1, choice2, choice3;
	int thisPlayer = 0;
	int numTests = 20000;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	printf("Testing Steward...\n");
	struct gameState G;
	int failCount = 0;
	for (n = 0; n < numTests; n++) {
		seed = rand() % RAND_MAX;
		initializeGame(2, k, seed, &G);
		G.handCount[thisPlayer] = rand() % MAX_HAND + 1;
		for (i = 0; i < G.handCount[thisPlayer]; i++) {
			G.hand[thisPlayer][i] = rand() % (22) + 4;
		}
		int stewardPos = rand() % G.handCount[thisPlayer] ;
		G.deckCount[thisPlayer] = rand() % MAX_DECK + 1;
		for (j = 0; j < G.deckCount[thisPlayer]; j++) {
			G.hand[thisPlayer][i] = rand() % (22) + 4;
		}
		G.hand[thisPlayer][stewardPos] = steward;
		choice1 = rand() % (3) + 1;
		choice2 = rand() % (G.handCount[thisPlayer] + 1);
		choice3 = rand() % (G.handCount[thisPlayer] + 1);
	/*	while(choice2 == choice1) {
			choice2 = rand() % (G.handCount[thisPlayer]);
		}
		while (choice3 == choice1 || choice3 == choice2) {
			choice3 = rand() % (G.handCount[thisPlayer]);
		}*/
		int initialCoins = G.coins;
		int initialHandCount = G.handCount[thisPlayer];
		if (checkSteward(thisPlayer, &G, choice1, choice2, choice3, stewardPos, initialHandCount, initialCoins, seed)) {
			failCount++;
		};
	}
	
	printf("%d failures out of %d tests.", failCount, numTests);
	return 0;
}