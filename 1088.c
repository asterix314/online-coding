#include <stdio.h>
#include <stdlib.h>

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define max4(a, b, c, d) max2(max2(a, b), max2(c, d))

typedef struct {
  int hight;
  int steps;
} spot_t;


spot_t *TERRAIN = NULL;

int comp(int *i1, int *i2) {
  return TERRAIN[*i1].hight - TERRAIN[*i2].hight;
}

inline int steps(int r, int c, int rows, int cols) {

  return  max4((c-1 < 0)     ? 0 : TERRAIN[r*cols+c-1].steps,
	       (r+1 >= rows) ? 0 : TERRAIN[(r+1)*cols+c].steps,
	       (c+1 >= cols) ? 0 : TERRAIN[r*cols+c+1].steps,
	       (r-1 < 0)     ? 0 : TERRAIN[(r-1)*cols+c].steps);
}

int solve(int rows, int cols) {
  
  spot_t terrain[rows*cols]; // automatic memory allocation
  int index[rows*cols];
  
  for(int i=0; i<rows*cols; i++) {
      scanf("%d", &(terrain[i].hight));
      terrain[i].steps = 0;
      index[i] = i;
  }
  
  TERRAIN = terrain; // so that comp can reference the terrain matrix
  qsort(index, rows*cols, sizeof(int), comp);
      
  // traverse spots in order of increasing hight
  int max_steps = 0;
  for(int i=0; i<rows*cols; i++) {
    int r, c, steps;
    r = index[i] / cols; // recover row
    c = index[i] % cols; // recover column
    
    steps = 1 + max4((c-1 < 0)     ? 0 : TERRAIN[r*cols+c-1].steps,
		     (r+1 >= rows) ? 0 : TERRAIN[(r+1)*cols+c].steps,
		     (c+1 >= cols) ? 0 : TERRAIN[r*cols+c+1].steps,
		     (r-1 < 0)     ? 0 : TERRAIN[(r-1)*cols+c].steps);

    max_steps = (steps > max_steps) ? steps : max_steps;
    terrain[index[i]].steps = steps;   
  }

  return max_steps;
}

void main() {
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  printf("%d\n", solve(rows, cols));
}
