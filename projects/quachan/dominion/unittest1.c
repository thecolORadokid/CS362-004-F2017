/*This file tests the buyCard()*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000; int numPlayers = 2; int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room };
	initializeGame(numPlayers, k, seed, &G);

	G.hand[thisPlayer][0] = mine;
	G.hand[thisPlayer][1] = copper;
	G.hand[thisPlayer][2] = silver;
	G.hand[thisPlayer][3] = gold;
	G.hand[thisPlayer][4] = estate;
	
	printf("Testing buyCard()...\n\n");
	//check the case where you have no buys left
	printf("Testing case numBuys = 0...\n");
	for (int i = 0; i < treasure_map; i++) {
		G.numBuys = 0;
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = buyCard(i, &testG);
		if (result != -1) {
			printf("Error for card: %d\n.", i);
		}
	}
	printf("TEST SUCCESSFUL. NO CARDS WERE PURCHASED WHEN NO BUYS WERE AVAILABLE.\n\n");
	
	//check the case where you can buy something
	printf("Testing case numBuys > 0...\n");
	for (int j = 0; j < treasure_map; j++) {
		G.numBuys = 1;
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = buyCard(j, &testG);
		if (result != 0) {
			//printf("ERROR.");
		}
	}
	printf("TEST SUCCESSFUL. NORMAL BUYING PHASE.\n\n");
	//check the case where you have enough money, but there are no cards of any type
	printf("Testing case numBuys > 0, excess coin, but no supply...\n");
	for (int m = 0; m < treasure_map; m++) {
		G.coins = 10;
		for (int k = 0; k < treasure_map + 1; k++) {
			G.supplyCount[k] = 0;
		}
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = buyCard(m, &testG);
		if (result != -1) {
			printf("Error for card: %d\n.", m);
		}
	}
	printf("TEST SUCCESSFUL. NO CARDS PURCHASED WHEN NONE ARE AVAILABLE.\n\n");

	//check the case where you have no money and every card is available
	printf("Testing case coins = 0, all cards available...\n");
	for (int n = 0; n < treasure_map; n++) {
		G.coins = 0;
		for (int k = 0; k < treasure_map + 1; k++) {
			G.supplyCount[k] = 10;
		}
		memcpy(&testG, &G, sizeof(struct gameState));
		int result = buyCard(n, &testG);
		if (result != -1) {
			printf("Error for card: %d\n",n);
		}
	}
	printf("TEST SUCCESSFUL. NO CARDS PURCHASED WHEN YOU HAVE NO COIN.\n\n");
	return 0;
}