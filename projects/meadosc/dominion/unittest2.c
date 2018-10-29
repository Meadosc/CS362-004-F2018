//Unit Test 1.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the kingdomCards function.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* unittest1: unittest2.c dominion.o rngs.o
*  gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7, int k8, int k9, int k10);

int main() {
 
  int* kards;  

  //call function for testing
  kards = kingdomCards(1,2,3,4,5,6,7,8,9,10);
  if (kards[0]==1)
    printf("Test k1 == 1: PASSED\n");
  else
    printf("Test k1 == 1: FAILED\n");  
  if (kards[1]==2)
    printf("Test k2 == 2: PASSED\n");
  else
    printf("Test k2 == 2: FAILED\n");  
  if (kards[2]==3)
    printf("Test k3 == 3: PASSED\n");
  else
    printf("Test k3 == 3: FAILED\n");  
  if (kards[3]==4)
    printf("Test k4 == 4: PASSED\n");
  else
    printf("Test k4 == 4: FAILED\n");  
  if (kards[4]==5)
    printf("Test k5 == 5: PASSED\n");
  else
    printf("Test k5 == 5: FAILED\n");  
  if (kards[5]==6)
    printf("Test k6 == 6: PASSED\n");
  else
    printf("Test k6 == 6: FAILED\n");  
  if (kards[6]==7)
    printf("Test k7 == 7: PASSED\n");
  else
    printf("Test k7 == 7: FAILED\n");  
  if (kards[7]==8)
    printf("Test k8 == 8: PASSED\n");
  else
    printf("Test k8 == 8: FAILED\n");  
  if (kards[8]==9)
    printf("Test k9 == 9: PASSED\n");
  else
    printf("Test k9 == 9: FAILED\n");  
  if (kards[9]==10)
    printf("Test k10 == 10: PASSED\n");
  else
    printf("Test k10 == 10: FAILED\n");  

  return 0;
}







