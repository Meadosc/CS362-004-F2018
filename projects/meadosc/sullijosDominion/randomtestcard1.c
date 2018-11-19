//Random Card Test 1.
//Cord Meados 11/11/2018

//-----------------------------
//Testing the smithy card randomly.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* randomtestcard1: randomtestcard1.c dominion.o rngs.o
*  gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

//keep a count of failed tests.
int testsFailed = 0;

//suppress error printing. 1 to print. 0 to not print.
int printError = 0;

//Assert statement
void myAssert(int statement){
  if(statement == 0)
    testsFailed = testsFailed + 1;
}

int main() {

  printf("Testing Smithy\n");

  int iteration = 1000;
  for(int i = 0; i < iteration; i++){
    struct gameState G, testG;
    int k[10] = {adventurer, smithy, steward, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
    int numPlayers = rand()%3 + 2;
    int seed = rand();
    int handpos=0, choice1=0, choice2=0, choice3=0, bonus=0;

    //initialize the game for testing
    initializeGame(numPlayers, k, seed, &G);
    //copy game state to a test state for later comparison
    memcpy(&testG,&G,sizeof(struct gameState));
    //play card
    cardEffect(smithy,choice1,choice2,choice3,&testG,handpos,&bonus);

    //Test 1: draw 3 cards -----------------------------------------
    int newCards = 3, discarded = 1, player = 0;
    int shuffledCards = 0;

    if(0 == (testG.handCount[player] == G.handCount[player] + newCards - discarded)){
      if(printError){
        printf("Test Failed: handcount: %d, expected: %d, ",testG.handCount[player], G.handCount[player] + newCards - discarded);
        printf("Number of Players: %d, seed: %d\n", numPlayers, seed);
      }
      testsFailed = testsFailed + 1;
    }
    if(0 == (testG.deckCount[player] == G.deckCount[player] - newCards + shuffledCards)){
      if(printError){
        printf("Test Failed: deckcount: %d, expected: %d,  ",testG.deckCount[player], G.deckCount[player] - newCards + shuffledCards); 
        printf("Number of Players: %d, seed: %d\n", numPlayers, seed);
      }
      testsFailed = testsFailed + 1; 
    }

    if(0 == (testG.coins == G.coins)){
      if(printError){
        printf("Test Failed: coins: %d, expected: %d,  ",testG.coins, G.coins);
        printf("Number of Players: %d, seed: %d\n", numPlayers, seed);
      }
      testsFailed = testsFailed + 1; 
    }

    //Test other Players state---------------------------------------
    if(0 == (testG.handCount[1]==G.handCount[1] && testG.deckCount[1]==G.deckCount[1] && testG.discardCount[1]==G.discardCount[1])){
      if(printError){
        printf("Other players state: FAILED\n");
      }
      testsFailed = testsFailed + 1; 
    }
  }

  printf("Tests Failed: %d\n", testsFailed);

  return 0;
}













