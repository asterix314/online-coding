#include <stdio.h>
#include <stdlib.h>

#define MAX_INTERVALS 50000

typedef struct {
  unsigned left;
  unsigned right;
} interval;

int comp(const void * ia, const void * ib) {
  interval const * a = ia;
  interval const * b = ib;
  
  return (a->left) - (b->left);
}

int main()
{
  interval itvs[MAX_INTERVALS] = {0};
  
  size_t n = 0;
  scanf("%u", &n);  
  
  for(size_t i=0; i<n; i++) {
    scanf("%u %u", &(itvs[i].left), &(itvs[i].right));
  }
  
  /* sorting is the key */
  qsort(itvs, n, sizeof(interval), comp);

  size_t last = 0;
  for(size_t i=1; i<n; i++) {
    if (itvs[i].left > itvs[last].right)
      itvs[++last] = itvs[i];
    else if (itvs[i].right > itvs[last].right)
      itvs[last].right = itvs[i].right;
  }

  for(size_t i=0; i<=last; i++) {
    printf("%u %u\n", itvs[i].left, itvs[i].right);
  }
  
  return 0;
}


