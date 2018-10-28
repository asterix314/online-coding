#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int comp(const void *x, const void *y) {
  const int *px = x;
  const int *py = y;
  return *px - *py;
}

void solve(int n, int m, int k, int l) {
  // sort a[] and append time k to the end.
  int a[n+1];
  for (unsigned i=0; i<n; ++i) {
    scanf("%d", a+i);
  }
  qsort(a, n, sizeof(a[0]), comp);
  a[n]=k;

  int min = INT_MAX;
  for (unsigned i=0; i<=n; ++i) {       // n+1 iterations
    int wait = l * (m + i + 1) - a[i];  // gist
    if (wait <= 0) {
      min = 0;
      break;
    }
    else if (wait < min) {
      min = wait;
    }
  }
  printf("%d\n", min);
}

int main(void) {
  int t=0;
  scanf("%d", &t);
  for (unsigned i=0; i<t; ++i) {
    int n=0, m=0, k=0, l=0;
    scanf("%d %d %d %d", &n, &m, &k, &l);
    solve(n, m, k, l);
  }
  return EXIT_SUCCESS;
}

