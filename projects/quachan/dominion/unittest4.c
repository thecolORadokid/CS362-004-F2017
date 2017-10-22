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

	printf("Testing isGameOver()...\n");
	G.supplyCount[province] = 0;
	memcpy(&testG, &G, sizeof(struct gameState));
	int result = isGameOver(&testG);
	if (result) {
		printf("Test PASSED. Game ended with Province supply at 0.\n\n");
	}
	else {
		printf("Test FAILED. Province supply depleted, game not ended.\n");
	}

	G.supplyCount[smithy] = 0;
	G.supplyCount[adventurer] = 0;
	G.supplyCount[mine] = 0;
	memcpy(&testG, &G, sizeof(struct gameState));
	result = isGameOver(&testG);

	if (result) {
		printf("Test PASSED. Game ended with 3 empty supply piles.\n\n");
	}
	else {
		printf("Test FAILED. 3 empty piles.\n");
	}
	return 0;
}