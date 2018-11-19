//Unit Test 4.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the supplyCount function.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* unittest1: unittest4.c dominion.o rngs.o
*  gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

//declare  so the compiler doesn't give a warning
int supplyCount(int card, struct gameState *state);

int main() {
  struct gameState G;
  G.supplyCount[0] = 2;
  //int k[10] = {adventurer, smithy, steward, embargo, minion, village, mine, cutpurse, sea_hag, tribute}; 
  //int numPlayers = 2;
  //int seed = 100;

  //initialize the game for testing
  //initializeGame(numPlayers, k, seed, &G);


  if((supplyCount(0,&G)) == 2)
    printf("Test supplyCount : PASSED\n");
  else
    printf("Test supplyCount: FAILED\n");
  
  return 0;
}











