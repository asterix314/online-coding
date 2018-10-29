#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long prod(long long x, long long k, long long j) {
    const long long modulo = 1000000007;
    long long x1 = x;
    long long prod = 1;
    for (long long i=0; i<=k; ++i) {
      prod = prod * (i==j ? 1 : (x1+i) * (x1+i-1)) % modulo;
      if (!prod) return 0; 
    }
    return (long long) prod;
}

void solve(long long n, long long k) {
  long long j = k - (n - k*(k+1)/2) % k;
  long long x = (n + j - k*(k+1)/2) / k;
  
  if (x>0 && j>=1 && j <=k && k*x + k*(k+1)/2 == n + j) { // solvable
    // printf("x=%d, j=%d\n", x, j);
    printf("%lld\n", prod(x, k, j));
  } else {
    printf("-1\n");
  }
}

long long main(void) {
  long long t=0;
  scanf("%lld", &t);
  for (long long i=0; i<t; ++i) {
    long long n=0, k=0;
    scanf("%lld %lld", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}

