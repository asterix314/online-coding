#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MODULO 1000000007

void solve(int n, int k) {
  long long x = 0;
  int j = 0;
  bool found = false;
  for (j=1; j<=k; ++j) {
    x = (n+j-k*(k+1)/2)/k;
    if (x>0 && k*x == n+j-k*(k+1)/2) {
      found = true;
      break;
    }
  }
  if (found) {
    long long ans = x*(x-1) % MODULO;
    for (int i=1; i<=k; ++i) {
      ans = ans*(i==j ? 1 : (x+i)*(x+i-1)) % MODULO; 
    }
    printf("%lld\n", ans);
  } else {
    printf("%d\n", -1);
  }
}

int main(void) {
  int t=0;
  scanf("%d", &t);
  for (unsigned i=0; i<t; ++i) {
    int n=0, k=0;
    scanf("%d %d", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}

