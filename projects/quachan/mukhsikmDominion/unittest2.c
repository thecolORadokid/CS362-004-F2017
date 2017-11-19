/*This file is meant to test playCard() functionality*/

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
	initializeGame(numPlayers, k, seed, &G);
	printf("Testing playCard()...\n\n");
	G.hand[thisPlayer][0] = smithy;
	G.hand[thisPlayer][1] = copper;
	G.hand[thisPlayer][2] = silver;
	G.hand[thisPlayer][3] = gold;
	G.hand[thisPlayer][4] = estate;

	int initialNumActions;
	//test to see if card is played in the correct phase
	printf("Testing phase functionality...\n");
	G.phase = -1;
	memcpy(&testG, &G, sizeof(struct gameState));
	int result = playCard(0, 0, 0, 0, &testG);
	if (result == -1) {
		printf("Test PASSED. Could not play card when not the right phase.\n\n");
	}
	else if (result == 0) {
		printf("Test FAILED. Card played when it was not supposed to.\n\n");
	}

	G.phase = 0;
	memcpy(&testG, &G, sizeof(struct gameState));
	initialNumActions = testG.numActions;
	result = playCard(0, 0, 0, 0, &testG);
	if (result == 0) {
		printf("Test PASSED. Card played card when appropriate.\n");
		if (testG.numActions == (initialNumActions - 1)) {
			printf("Correct number of actions after function call.\n\n");
		}
		else {
			printf("Incorrect number of actions after function call.\n\n");
		}
	}
	else if (result == -1) {
		printf("Test FAILED. Card played when it was not supposed to.\n\n");
	}
	//check to see if enough actions exist
	printf("Testing number of actions functionality...\n");
	G.numActions = 0;
	memcpy(&testG, &G, sizeof(struct gameState));
	result = playCard(0, 0, 0, 0, &testG);
	if (result == -1) {
		printf("Test PASSED. No actions to take.\n\n");
	}
	else if (result == 0) {
		printf("Test FAILED. Action taken when none were available.\n\n");
	}
	G.numActions = 1;
	memcpy(&testG, &G, sizeof(struct gameState));
	initialNumActions = testG.numActions;
	result = playCard(0, 0, 0, 0, &testG);
	if (result == 0) {
		printf("Test PASSED. Action taken when available.\n");
		if (testG.numActions == (initialNumActions - 1)) {
			printf("Correct number of actions after function call.\n\n");
		}
		else {
			printf("Incorrect number of actions after function call.\n\n");
		}
	}
	else if (result == -1) {
		printf("Test FAILED. Action taken when unavailable.\n");
	}

	//check to see if a treasure card is trying to be played
	printf("Testing card input functionality...\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	result = playCard(1, 0, 0, 0, &testG);
	if (result == -1) {
		printf("Test PASSED. Treasure card cannot be played.\n\n");
	}
	else if (result == 0) {
		printf("Test FAILED. Cannot play treasure card.\n");
	}

	//make sure coins are updated.
	//would like to test this but a good use case does not exist with the cards in this deck
	return 0;
}