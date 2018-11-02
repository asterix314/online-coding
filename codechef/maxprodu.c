#include <stdio.h>
#include <stdlib.h>

unsigned prod(unsigned x, unsigned k, unsigned j) {
    const size_t modulo = 1000000007;
    size_t x1 = x;
    size_t prod = 1;
    for (unsigned i=0; i<=k; ++i) {
      prod = prod * (i==j ? 1 : (x1+i) * (x1+i-1)) % modulo;
      if (!prod) return 0; 
    }
    return (unsigned) prod;
}

void solve(unsigned n, unsigned k) {
  unsigned j = k - (n - k*(k+1)/2) % k;
  unsigned x = (n + j - k*(k+1)/2) / k;
  
  if (n >= k*(k+1)/2 && k*x + k*(k+1)/2 == n + j) { // solvable
    printf("%u\n", prod(x, k, j));
  } else {
    printf("-1\n");
  }
}

int main(void) {
  unsigned t=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n, k;
    scanf("%u %u", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}
