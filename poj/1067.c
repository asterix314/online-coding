#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/*
 just google Wythoff's game
 */

int main() {
  unsigned a = 0;
  unsigned b = 0;

  double const phi = (1.0 + sqrt(5.0)) / 2.0;
  
  while (EOF != scanf("%d %d", &a, &b)){
    if (a > b) { // makes sure a <= b
      a ^= b;
      b ^= a;
      a ^= b;
    }
    
    printf("%d\n", (unsigned)floor((b - a) * phi) == a ? 0 : 1);
  }  
  return EXIT_SUCCESS;
}

