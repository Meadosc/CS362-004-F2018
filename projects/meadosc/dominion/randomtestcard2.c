//Random Card Test 3.
//Cord Meados 11/11/2018

//-----------------------------
//Testing the council_room card randomly
//-----------------------------

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int iterations = 1000;
int testsFailed = 0;


int main() {

printf("Testing Council Room\n"); 

  for(int i = 0; i<iterations; i++){
    struct gameState G, testG;
    int k[10] = {adventurer, smithy, council_room, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
    int numPlayers = rand()%3 + 2;
    int seed = rand();
    int handpos=0, choice1=0, choice2=0, choice3=0, bonus=0;

    //initialize the game for testing
    initializeGame(numPlayers, k, seed, &G);
    //copy game state to a test state for later comparison
    memcpy(&testG,&G,sizeof(struct gameState));
    //play card
    cardEffect(council_room,choice1,choice2,choice3,&testG,handpos,&bonus);

    //Test 1: draw 4 cards -----------------------------------------
    int newCards = 4, discarded = 1, player = 0;
    int shuffledCards = 0;
    
    //printf("handcount: %d, expected: %d  ",testG.handCount[player], G.handCount[player] + newCards - discarded);
    if(0 ==(testG.handCount[player] == G.handCount[player] + newCards - discarded)){
      testsFailed = testsFailed + 1;
    }
    //printf("deckcount: %d, expected: %d  ",testG.deckCount[player], G.deckCount[player] - newCards + shuffledCards);
    if(0 == (testG.deckCount[player] == G.deckCount[player] - newCards + shuffledCards)){
      testsFailed = testsFailed + 1;
    }
    //printf("coins: %d, expected: %d  ",testG.coins, G.coins);
    if(0 == (testG.coins == G.coins)){
      testsFailed = testsFailed + 1;
    }

    //Test 2: number of buys +1 -------------------------------------
    //printf("number of Buys: %d, expected: %d  ",testG.numBuys, G.numBuys + 1);
    if(0 == (testG.numBuys == G.numBuys + 1))
      testsFailed = testsFailed + 1;

    //Test 3: Each other player draws a card ------------------------
    //printf("Other Players hand: %d, expected: %d  ",testG.handCount[1], G.handCount[1]+1);
    if(0 == (testG.handCount[1] == G.handCount[1]+1));
      testsFailed = testsFailed + 1;

    //printf("Other Players deck: %d, expected: %d  ", testG.deckCount[1], G.deckCount[1]-1);
    if(0 == (testG.deckCount[1]==G.deckCount[1]-1));  
      testsFailed = testsFailed + 1;

    //Test other Players state---------------------------------------
    //printf("Testing other player's state: ");
    if(0 == (testG.discardCount[1]==G.discardCount[1]));
      testsFailed = testsFailed + 1;


  }

  printf("Tests Failed: %d\n", testsFailed);

  return 0;
}













