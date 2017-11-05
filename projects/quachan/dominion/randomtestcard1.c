#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int checkSmithy(int currentPlayer, struct gameState *post, int handPos, int seed, int initialHandCount) {

	int result = smithyCard(currentPlayer, post, handPos);
	assert(result == 0 && "Failed to execute");

	if (post->handCount[currentPlayer] != initialHandCount + 2) {
		printf("Seed: %d, test failed.\n", seed);
	}
	//assert(post->handCount[currentPlayer] == initialHandCount + 2);
}
int main() {
	srand(time(NULL));
	int n, seed;
	int thisPlayer = 0;
	int numTests = 20000;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	
	printf("Testing Smithy...\n");
	struct gameState G;
	
	//initializeGame(2, k, 10, &G);
	//memcpy(&testG, &G, sizeof(struct gameState));

	for (n = 0; n < numTests; n++) {
		seed = rand() % RAND_MAX;
		initializeGame(2, k, seed, &G);
		int smithyPos = rand() % G.handCount[thisPlayer];
		G.hand[thisPlayer][smithyPos] = smithy;
		checkSmithy(thisPlayer, &G, smithyPos, seed, G.handCount[thisPlayer]);
		
	}
	printf("%d Tests complete. Unsuccessful tests shown above.", numTests);
	return 0;
}
