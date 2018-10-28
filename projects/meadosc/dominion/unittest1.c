//Unit Test 1.
//Cord Meados 10/23/2018

//-----------------------------
//Testing the compare function.
//int compare(const void* a, const void* b)
//
//Compare returns 1 if a > b, -1 if a > b,
//   and 0 if a == b.
//-----------------------------

/*-----------------------------------------------------------------------
* Include the following lines in your makefile:
*
* unittest1: unittest1.c dominion.o rngs.o
*  gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
int compare(const void*, const void*);

int main() {
  
  int pos2 = 2;
  int pos1 = 1;
  int neg2 = -2;
  int neg1 = -1;
  int zero = 0;
  int large = 10^100;
  int small = 10^-100;
  char a = a;
  char b = b;

  //check greater than TRUE, return 1. Using positive numbers.  
  if(compare(&pos2, &pos1)== 1)
    printf("Test 2>1: PASSED\n");
  else
    printf("Test 2>1: FAILED\n");

  //check greater than FALSE, return -1. Using negative numbers.
  if(compare(&neg2, &neg1) == -1)
    printf("Test -2>-1: PASSED\n");
  else
    printf("Test -2>-1: FAILED\n");

  //check equal to. use zeros.
  if(compare(&zero,&zero)==0)
    printf("Test 0==0: PASSED\n");
  else
    printf("Test 0==0: FAILED\n");

  //check large and small numbers
  if(compare(&large,&small)==1)
    printf("Test large/small: PASSED\n");
  else
    printf("Test large/small: FAILED\n");

  //check char input
  if(compare(&a,&b)==1)
    printf("Test char 1: FAILED\n");
  else if(compare(&a,&b)==0)
    printf("Test char 0: FAILED\n");
  else if(compare(&a,&b)==-1)
    printf("Test char -1: FAILED\n");
  else
    printf("Test char: PASSED\n"); 

  return 0;
}



