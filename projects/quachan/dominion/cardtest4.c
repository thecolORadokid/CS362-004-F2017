#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int handpos = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	initializeGame(numPlayers, k, seed, &G);
	printf("Testing Mine Card...\n");
	/* choice1 is hand# of money to trash, choice2 is supply# of money to put in hand */
	printf("Testing choice 2 = copper...\n\n");
	int trashCount = 0;
	for (int i = 1; i < G.handCount[thisPlayer]; i++) {
		int choice2 = copper;
		G.hand[thisPlayer][0] = mine;
		G.hand[thisPlayer][1] = copper;
		G.hand[thisPlayer][2] = silver;
		G.hand[thisPlayer][3] = gold;
		G.hand[thisPlayer][4] = estate;
		int initialHandCount = G.handCount[thisPlayer];
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = cardEffect(mine, i, choice2, 0, &testG, handpos, &bonus);
		//printf("Treasure to discard: %d\n Supply Choice: %d\n\n", testG.hand[thisPlayer][i], choice2);
		if (result == 0) {
			trashCount++;
			printf("%d trashed for %d\n", i, choice2);
			printf("Final Hand Count: %d\n", testG.handCount[thisPlayer]);
			printf("Hand contains: ");
			for (int j = 0; j < testG.handCount[thisPlayer]; j++) {
				printf("%d ,", testG.hand[thisPlayer][j]);
			}
			/*printf("Final Hand Count: %d\n", testG.handCount[thisPlayer]);
			printf("Hand contains: ");
				for (int j = 0; j < testG.handCount[thisPlayer]; j++) {
				printf("%d ,", testG.hand[thisPlayer][j]);*/
		}
	}
	if (trashCount == 0) {
		printf("Test PASSED. No exchange for copper.\n");
	}
	else {
		printf("Test FAILED. Shouldn't have exchanged for copper.\n");
	}
	if (testG.handCount[thisPlayer] != 4) {
		printf("Test FAILED. Incorrect number of cards in hand.\n\n");
	}
	else {
		printf("Test PASSED. Correct number of cards in hand.\n\n");
	}
	printf("Testing choice 2 = silver...\n\n");
	trashCount = 0;
	for(int i = 1; i < G.handCount[thisPlayer]; i++) {
		int choice2 = silver;
		G.hand[thisPlayer][0] = mine;
		G.hand[thisPlayer][1] = copper;
		G.hand[thisPlayer][2] = silver;
		G.hand[thisPlayer][3] = gold;
		G.hand[thisPlayer][4] = estate;
		int initialHandCount = G.handCount[thisPlayer];
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = cardEffect(mine, i, choice2, 0, &testG, handpos, &bonus);
		if (result == 0) {
			trashCount++;
			printf("%d trashed for %d\n", G.hand[thisPlayer][i], choice2);
			printf("Final Hand Count: %d\n", testG.handCount[thisPlayer]);
			printf("Hand contains: ");
			for (int j = 0; j < testG.handCount[thisPlayer]; j++) {
				printf("%d ,", testG.hand[thisPlayer][j]);
			}
		}
		printf("\n");
	}
	if (trashCount == 1) {
		printf("Test PASSED. Copper for silver.\n");
	}
	else {
		printf("Test FAILED. Incorrect number of exchanges.\n");
	}
	if (testG.handCount[thisPlayer] != 4) {
		printf("Test FAILED. Incorrect number of cards in hand.\n\n");
	}
	else {
		printf("Test PASSED. Correct number of cards in hand.\n\n");
	}
	printf("\nTesting choice 2 = gold...\n\n");
	trashCount = 0;
	for (int i = 1; i < G.handCount[thisPlayer]; i++) {
		int choice2 = gold;
		G.hand[thisPlayer][0] = mine;
		G.hand[thisPlayer][1] = copper;
		G.hand[thisPlayer][2] = silver;
		G.hand[thisPlayer][3] = gold;
		G.hand[thisPlayer][4] = estate;
		int initialHandCount = G.handCount[thisPlayer];
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = cardEffect(mine, i, choice2, 0, &testG, handpos, &bonus);
		if (result == 0) {
			trashCount++;
			printf("%d trashed for %d\n", G.hand[thisPlayer][i], choice2);
			printf("Final Hand Count: %d\n", testG.handCount[thisPlayer]);
			printf("Hand contains: ");
			for (int j = 0; j < testG.handCount[thisPlayer]; j++) {
				printf("%d ,", testG.hand[thisPlayer][j]);
			}
		}
		printf("\n");
	}
	if (trashCount == 2) {
		printf("Test PASSED. Copper and silver for gold.\n");
	}
	else {
		printf("Test FAILED. Incorrect number of exchanges.\n");
	}
	if (testG.handCount[thisPlayer] != 4) {
		printf("Test FAILED. Incorrect number of cards in hand.\n\n");
	}
	else {
		printf("Test PASSED. Correct number of cards in hand.\n\n");
	}
	return 0;
}
