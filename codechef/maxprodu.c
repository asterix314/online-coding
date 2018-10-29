#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MODULO 1000000007

void solve(unsigned n, unsigned k) {
  unsigned j = k - (n - k*(k+1)/2) % k;
  unsigned x = (n + j - k*(k+1)/2) / k;
  
  if (x>0 && j>=1 && k*x + k*(k+1)/2 == n + j) { // solvable
    // printf("x=%u, j=%u\n", x, j);
    size_t x1 = x;
    size_t ans = x1*(x1-1) % MODULO;
    for (unsigned i=1; i<=k; ++i) {
      ans = ans*(i==j ? 1 : (x1+i)*(x1+i-1)) % MODULO; 
    }
    printf("%zu\n", ans);
  } else {
    printf("%d\n", -1);
  }
}

int main(void) {
  unsigned t=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n=0, k=0;
    scanf("%u %u", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}

