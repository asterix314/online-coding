#include <stdio.h>
#include <strings.h>

// return the counterfeit bit pattern by analysing the weighting 
int deduce(char rtilt[], char left[], char right[]) {
  int light = 0;
  int heavy = 0;
  int left_bits = 0;
  int right_bits = 0;
  int k = strlen(left);
  for(int i=0; i<k; i++) {
      left_bits |= 1 << (left[i] - 'A');
      right_bits |= 1 << (right[i] - 'A');
  }
  switch (rtilt[0]) {
    case 'u':
	
    case 'd':
    case 'e':
    default:
  }
  printf("DEBUG: deduce returning: %X\n", (heavy << sizeof(int)/2) + light);
  return (heavy << sizeof(int)/2) + light;
}


int main() {
  int ncases = 0;
  int coin_flags = -1; // all bits set
  int counterfeit = 0;
  char left[8];
  char right[8];
  char rtilt[8];

  if (1 != scanf("%d", &ncases))
    return 0; // input wrong

  for (int i=0; i<ncases; i++) {
    for (int j=0; j<3; j++) {
      // assuming nothing unexpected from input
      if (3 != scanf("%s %s %s", left, right, rtilt)) 
	return 0;
      coin_flags &= deduce(rtilt, left, right);
    }
    counterfeit = ffs(coin_flags);
    printf("%c is the counterfeit coin and it is %s.\n",
	   'A' - 1 + ((counterfeit > 12) ? counterfeit - sizeof(int)/2 : counterfeit),
	   (counterfeit > 12) ? "heavy" : "light");
  }
  return 0;
}
