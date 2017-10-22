/*This file contains a unit test for the Adventurer card.*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main() {

	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0; 
	int seed = 1000; int numPlayers = 2; int thisPlayer = 0; 
	struct gameState G, testG; 
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room };
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	int initialNumCards, finalNumCards, initialDeckCount, finalDeckCount;

	//this is the case where the deck is full of treasure cards, so no action cards need to be discarded
	printf("Testing a deck full of treasure cards...\n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	initialNumCards = testG.handCount[thisPlayer];
	initialDeckCount = testG.deckCount[0];
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	finalNumCards = testG.handCount[thisPlayer];
	finalDeckCount = testG.deckCount[0];
	printf("Initial hand count: %d,  Expected: %d \n", initialNumCards, 5);
	printf("Final hand count: %d, Expected: %d \n", finalNumCards, initialDeckCount +1);
	if (finalNumCards != initialNumCards + 1) {
		printf("Test FAILED. Incorrect number of cards in hand.\n");
	}
	else {
		printf("Test PASSED. Correct number of cards in hand.\n");
	}
	printf("Initial deck count: %d,  Expected: %d \n",initialDeckCount, 5);
	printf("Final deck count: %d, Expected: %d\n", finalDeckCount, initialDeckCount - 2);
	if (finalDeckCount != initialDeckCount -2) {
		printf("Test FAILED. Incorrect number of cards in hand.\n");
	}
	else {
		printf("Test PASSED. Correct number of cards in deck.\n");
	}

	//this is an edge case, where all the cards in the deck are action cards, no treasure cards can be drawn
	
	G.deck[0][0] = smithy;
	G.deck[0][1] = embargo; 
	G.deck[0][2] = smithy;
	G.deck[0][3] = embargo; 
	G.deck[0][4] = smithy;
	G.deck[0][5] = embargo; 
	G.deck[0][6] = smithy;
	G.deck[0][7] = embargo;
	G.deck[0][8] = smithy;
	G.deck[0][9] = embargo;
	G.hand[0][0] = mine;
	G.hand[0][1] = mine;
	G.hand[0][2] = mine;
	G.hand[0][3] = mine;
	G.hand[0][5] = mine;
	memcpy(&testG, &G, sizeof(struct gameState));
	int result = cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	if (result == 0) {
		printf("Test FAILED. Should be stuck in infinite loop.");
	}
	else {
		printf("Test PASSED. Adventurer not used.\n");
	}
	return 0;
}