#include <stdio.h>
#include <stdlib.h>

#define max2(a, b) (a) > (b) ? (a) : (b)
#define max4(a, b, c, d) max2(max2(a, b), max2(c, d))

typedef struct {
  char row;
  char col;
  short npaths;
} measure_t;

int f(char nrow, char ncol) {
  
  short terrain[nrow][ncol];
  measure_t measures[nrow][ncol];
}

int main() {

  char nrow = 0;
  char ncol = 0;
  
  if (2 != scanf("%c %c", &nrow, &ncol))
    return 0;

  
  return 0;
}
