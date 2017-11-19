#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int checkAdventurer(int currentPlayer, struct gameState *state, int handPos, int drawntreasure, int seed, int initalHandCount) {
	int temphand[MAX_HAND];
	int z = 0;
	int cardDrawn = 0;
	int result = adventurerEffect(state, currentPlayer, drawntreasure, z, cardDrawn, temphand);
	assert(result == 0 && "Seed: %d, Failed to execute.\n");
	if (state->handCount[currentPlayer] != initalHandCount + 1) {
		printf("Seed: %d, test failed, incorrect number of cards in hand.\n", seed);
	}
	else {
		printf("Seed: %d, test passed.\n", seed);
	}
}

int main() {
	srand(time(NULL));
	int i, j, n, seed, initialHandCount;
	int thisPlayer = 0;
	int numTests = 20000;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	printf("Testing Adventurer...\n");
	struct gameState G;

	for (n = 0; n < numTests; n++) {
		seed = rand() % RAND_MAX;
		initializeGame(2, k, seed, &G);
		G.handCount[thisPlayer] = rand() % MAX_HAND + 1 ;
		initialHandCount = G.handCount[thisPlayer];
		G.deckCount[thisPlayer] = rand() % MAX_DECK + 1;
		int adventurerPos = rand() % G.handCount[thisPlayer];
		for (i = 0; i < G.handCount[thisPlayer]; i++) {
			G.hand[thisPlayer][i] = rand() % (22) + 4;
		}
		G.hand[thisPlayer][adventurerPos] = adventurer;
		for (j = 0; j < G.deckCount[thisPlayer]; j++) {
			G.hand[thisPlayer][i] = rand() % (22) + 4;
		}
		checkAdventurer(thisPlayer, &G, adventurerPos, 0, seed, initialHandCount);
	}
	printf("TEST COMPLETE. Errors listed above.");
	return 0;
}