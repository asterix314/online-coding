#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int prod(int x, int k, int j) {
    const int modulo = 1000000007;
    long long x1 = x;
    long long prod = 1;
    for (int i=0; i<=k; ++i) {
      prod = prod * (i==j ? 1 : (x1+i) * (x1+i-1)) % modulo;
      if (!prod) return 0; 
    }
    return (int) prod;
}

void solve(int n, int k) {
  int j = k - (n - k*(k+1)/2) % k;
  int x = (n + j - k*(k+1)/2) / k;
  
  if (x>0 && j>=1 && j <=k && k*x + k*(k+1)/2 == n + j) { // solvable
    // printf("x=%d, j=%d\n", x, j);
    printf("%d\n", prod(x, k, j));
  } else {
    printf("-1\n");
  }
}

int main(void) {
  int t=0;
  scanf("%d", &t);
  for (int i=0; i<t; ++i) {
    int n=0, k=0;
    scanf("%d %d", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}

