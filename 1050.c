#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

/* Kadane:
  s(k) = max(s(k-1), s(k-1) + a(k))
  maximum = max(maximum, s(k))
 */

int submatrix_max(int m[][MAX_SIZE+1], int n) {
  /* column partial sums */
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
      m[i][j] += m[i-1][j];

  int max = INT_MIN;
  for (int i1=0; i1<n; ++i1)
    for (int i2=i1+1; i2<=n; ++i2) {
      /* 1 dimensional Kadane */
      int s = 0;
      for (int j=1; j<=n; ++j) {
        if (s > 0)
          s += m[i2][j] - m[i1][j];
        else
          s = m[i2][j] - m[i1][j];
        if (s > max)
          max = s;
      }
    }
  return max;
}

int main() {
  int n = 0;
  int m[MAX_SIZE+1][MAX_SIZE+1] = {0};
  
  while(EOF != scanf("%d", &n)) {
    /* read in matrix */
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j)
        scanf("%d", &m[i][j]);

    printf("%d\n", submatrix_max(m,n));
  }

  return EXIT_SUCCESS;
}
