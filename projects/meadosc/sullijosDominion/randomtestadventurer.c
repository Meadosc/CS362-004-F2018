//Card Test 4.
//Cord Meados 11/11/2018

//-----------------------------
//Testing the adventurer card randomly.
//-----------------------------

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testsFailed = 0;
int iterations = 1000;

int main() {
  printf("Testing Adventurer\n");


  for(int i = 0; i<iterations; i++){
    struct gameState G, testG;
    int k[10] = {adventurer, smithy, council_room, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
    int numPlayers = rand()%3+2;
    int seed = rand();
    int handpos=0, choice1=0, choice2=0, choice3=0, bonus=0;

    //initialize the game for testing
    initializeGame(numPlayers, k, seed, &G);
    //copy game state to a test state for later comparison
    memcpy(&testG,&G,sizeof(struct gameState));
    //play card
    cardEffect(adventurer,choice1,choice2,choice3,&testG,handpos,&bonus);

    //Test 1: draw 2 cards (Treasure cards) ---------------------------
    int newCards = 2, discarded = 1, player = 0;
    //printf("handcount: %d, expected: %d  ",testG.handCount[player], G.handCount[player] + newCards - discarded);
    if(0 == (testG.handCount[player] == G.handCount[player] + newCards - discarded))
      testsFailed = testsFailed + 1;

    //printf("coins: %d, expected: %d  ",testG.coins, G.coins);
    if(0 == (testG.coins == G.coins))
      testsFailed = testsFailed + 1;

    //Test other Players state---------------------------------------
    //printf("Testing other player's state: ");
    if(0 == (testG.deckCount[1]==G.deckCount[1] && testG.handCount[1]==G.handCount[1] && testG.discardCount[1]==G.discardCount[1]))
      testsFailed = testsFailed + 1;

  }

  printf("Tests failed: %d\n", testsFailed);

  return 0;
}













