#include <stdio.h>
#include <stdlib.h>

#define max2(a, b) (a) > (b) ? (a) : (b)
#define max4(a, b, c, d) max2(max2(a, b), max2(c, d))

int main() {

  int ncol = 0;
  int nrow = 0;

  
  if (2 != scanf("%d %d", &ncol, &nrow))
    return 0;

  int *terrain = malloc(ncol * nrow * sizeof(int));

  struct measure_t {
    int index;
    int npaths;
  } *measures = malloc(ncol * nrow * sizeof(struct measure_t));

  if (NULL == terrain || NULL == measures)
    return 0;

  for (int i=0; i < ncol*nrow; i++) {
    if (1 != scanf("%d", terrain + i))
      return 0;
    measures[i].index = i;
    measures[i].npaths = 0;
  }



  
  free(terrain);
  free(measures);
  return 0;
}
