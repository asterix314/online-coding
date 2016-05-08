#include <stdio.h>
#include <strings.h>

int deduce(char rtilt[], char left[], char right[]) {
  int light = 0;
  int heavy = 0;
  return 0;
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
      coin_flags |= deduce(rtilt, left, right);
    }
    counterfeit = ffs(coin_flags);
    printf("%c is the counterfeit coin and it is %s.\n",
	   'A' - 1 + ((counterfeit > 12) ? counterfeit - sizeof(int)/2 : counterfeit),
	   (counterfeit > 12) ? "heavy" : "light");
  }
  return 0;
}
