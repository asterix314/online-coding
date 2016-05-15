#include <stdio.h>
#include <string.h>


/***
 counterfeit flags bit pattern example
 1 = possible counterfeit

 ----LKJIHGFEDCBA ----LKJIHGFEDCBA
 0000000101000000 0000000000100111
 [ heavy guesses] [ light guesses]
 
***/

// return the counterfeit bit pattern by analysing the weighting 
int deduce(char rtilt[], char left[], char right[]) {

  int left_bits = 0;
  int right_bits = 0;
  int guesses = 0;

  // collect the left and right coins
  int len = strlen(left);
  for(int i=0; i<len; i++) {
      left_bits |= 1 << (left[i] - 'A');
      right_bits |= 1 << (right[i] - 'A');
  }
  
  switch (rtilt[0]) {
  case 'u': // right up: (left) > (right)
    guesses = (left_bits << (sizeof(int) * 4)) + right_bits;
    break;
  case 'd': // right down: (right) > (left)
    guesses = (right_bits << (sizeof(int) * 4)) + left_bits;
    break;
  default: // even: ~(right + left) = ~(right + left)
    guesses = 0xfff ^ (left_bits | right_bits);
    guesses += guesses << (sizeof(int) * 4);
  }
  
  return guesses;
}


int main() {

  int n = 0;
  if (1 != scanf("%d", &n))
    return 0;

  int guesses;
  int counterfeit;
  int heavy;
  char left[8];
  char right[8];
  char rtilt[8];

  // n cases
  for (int i=0; i<n; i++) {
    guesses = -1; // all are suspect
    // 3 weightings
    for (int j=0; j<3; j++) {
      if (3 != scanf("%s %s %s", left, right, rtilt)) 
	return 0;
      guesses &= deduce(rtilt, left, right);
    }
  
    // find first set (1 if odd)
    counterfeit = __builtin_ffs(guesses);
    heavy = counterfeit > sizeof(int) * 4;
    printf("%c is the counterfeit coin and it is %s.\n",
	   'A' - 1 + (heavy ? counterfeit - sizeof(int) * 4 : counterfeit),
	   heavy ? "heavy" : "light");
  }
  return 0;
}
