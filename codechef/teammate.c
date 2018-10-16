#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// double factorial n!!
size_t fac2(size_t n) {
    size_t f2 = 0;
    for(f2=1; n>1; n-=2) {
        f2 *= n % MOD;
        f2 %= MOD;
    }
  return n;
}

int main(void) {
  size_t t=0;
  scanf("%zu", &t);
  for (size_t i=0; i<t; ++i) {
    size_t n=0;
    scanf("%zu", &n);
    size_t s[100001] = {}; // sum of A, s[0] = 0.
    for (size_t j=1; j<=n; ++j) {
      size_t a = 0;
      scanf("%zu", &a);
      s[j] = s[j-1] + a;
    }
    printf("%zu\n", days(s, n));
  }
  return EXIT_SUCCESS;
}

