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
  for(int i=0; i<nrow; i++)
    for(int j=0; j<ncol; j++) {
      
scanf("%hd",terrain+i*ncol+j);
      measures[i][j].row = i;
      measures[i][j].col = j;
      measures[i][j].npaths = 0;
printf("terrain[%c][%c] = %d\n", i, j, terrain[i][j]);
    }
return 0;
}

int main() {

  char nrow = 0;
  char ncol = 0;
  if (2 != scanf("%c %c", &nrow, &ncol))
    return 0;
  
  short terrain[nrow][ncol];
  
  return 0;
}
