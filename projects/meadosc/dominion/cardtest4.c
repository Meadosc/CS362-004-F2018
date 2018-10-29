//Card Test 4.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the adventurer card.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* cardtest4: cardtest4.c dominion.o rngs.o
*  gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
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
  int k[10] = {adventurer, smithy, council_room, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
  int numPlayers = 2;
  int seed = 100;
  int handpos=0, choice1=0, choice2=0, choice3=0, bonus=0;

  //initialize the game for testing
  initializeGame(numPlayers, k, seed, &G);
  //copy game state to a test state for later comparison
  memcpy(&testG,&G,sizeof(struct gameState));
  //play card
  cardEffect(adventurer,choice1,choice2,choice3,&testG,handpos,&bonus);

  //Test 1: draw 2 cards (Treasure cards) ---------------------------
  int newCards = 2, discarded = 1, player = 0;

  printf("Testing Adventurer\n");
  printf("handcount: %d, expected: %d  ",testG.handCount[player], G.handCount[player] + newCards - discarded);
  myAssert(testG.handCount[player] == G.handCount[player] + newCards - discarded);
  printf("coins: %d, expected: %d  ",testG.coins, G.coins);
  myAssert(testG.coins == G.coins);

  //Test other Players state---------------------------------------
  printf("Testing other player's state: ");
  myAssert(testG.deckCount[1]==G.deckCount[1] && testG.handCount[1]==G.handCount[1] && testG.discardCount[1]==G.discardCount[1]);
 
  return 0;
}













