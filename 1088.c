#include <stdio.h>
#include <stdlib.h>

#define max2(a, b) (a) > (b) ? (a) : (b)
#define max4(a, b, c, d) max2(max2(a, b), max2(c, d))

typedef struct {
  short hight;
  short npaths;
} spot_t;


spot_t *TERRAIN = NULL;

int comp(int *i1, int *i2) {
  return TERRAIN[*i1].hight - TERRAIN[*i2].hight;
}

void solve(int rows, int cols) {
  
  spot_t terrain[rows*cols];
  int index[rows*cols];

  TERRAIN = terrain;
  
  for(int i=0; i<rows*cols; i++) {
      scanf("%hd", &(terrain[i].hight));
      terrain[i].npaths = 0;
      index[i] = i;
  }

  qsort(index, rows*cols, sizeof(int), comp);

  for(int i=0; i<rows*cols; i++) {
    printf("index[%d] = %d\n", i, index[i]);
  }
  
}

void main() {
  int rows = 0;
  int cols = 0;
  scanf("%d %d", &rows, &cols);
  solve(rows, cols);
}
