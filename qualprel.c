#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  const int *x = a;
  const int *y = b;
  return *y - *x;
}

int teams(int s[], int n, int k) {
  qsort(s, n, sizeof(int), comp);
  int i = 0;
  for (i=k; i<n && s[i] == s[i-1]; ++i);
  return i;
}

int main() {
  int s[100000];
  int t=0, n=0, k=0;
  scanf("%d", &t);
  for (int i=0; i<t; ++i) {
    scanf("%d %d", &n, &k);
    for (int j=0; j<n; ++j)
      scanf("%d", s+j);
    printf("%d\n", teams(s, n, k));
  }
  return 0;
}

