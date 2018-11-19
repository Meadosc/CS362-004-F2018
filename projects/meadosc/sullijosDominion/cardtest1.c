//Card Test 1.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the smithy card.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* cardtest1: cardtest1.c dominion.o rngs.o
*  gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//I'm tired of writing this over and over again
void myAssert(int statement){
  if(statement == 1)
    printf("PASSED\n");
  else
    printf("FAILED\n");

}

int main() {
  struct gameState G, testG;
  int k[10] = {adventurer, smithy, steward, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
  int numPlayers = 2;
  int seed = 100;
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

  printf("Testing Smithy\n");
  printf("handcount: %d, expected: %d  ",testG.handCount[player], G.handCount[player] + newCards - discarded);
  myAssert(testG.handCount[player] == G.handCount[player] + newCards - discarded);
  printf("deckcount: %d, expected: %d  ",testG.deckCount[player], G.deckCount[player] - newCards + shuffledCards);
  myAssert(testG.deckCount[player] == G.deckCount[player] - newCards + shuffledCards);
  printf("coins: %d, expected: %d  ",testG.coins, G.coins);
  myAssert(testG.coins == G.coins);

  //Test other Players state---------------------------------------
  printf("Testing other player's state: ");
  myAssert(testG.handCount[1]==G.handCount[1] && testG.deckCount[1]==G.deckCount[1] && testG.discardCount[1]==G.discardCount[1]);
 
  return 0;
}













