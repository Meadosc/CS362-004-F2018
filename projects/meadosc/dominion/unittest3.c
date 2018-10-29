//Unit Test 3.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the whoseTurn function.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* unittest1: unittest2.c dominion.o rngs.o
*  gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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

//declare compare so the compiler doesn't give a warning
int whoseTurn(struct gameState *state);

int main() {
  struct gameState G;
  G.whoseTurn = 1;

  if(whoseTurn(&G) == 1)
    printf("Test whoseTurn: PASSED\n");
  else
    printf("Test whoseTrun: FAILED\n");

  return 0;
}









