#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool valid(int a[], size_t n) {
  for (size_t i=0; i<n-2; ++i) {
    if (a[i]>0) {
      a[i+2] -= a[i] * 3;
      a[i+1] -= a[i] * 2;
      a[i] = 0;
    }
    else if (a[i] < 0)
      return 0;
  }
  return !(a[n-1] || a[n-2]);
}

int main(void) {
  int a[100000];
  int b = 0;
  size_t t=0, n=0;
  scanf("%zu", &t);
  for (size_t i=0; i<t; ++i) {
    scanf("%zu", &n);
    for (size_t j=0; j<n; ++j)
      scanf("%d", a+j);
    for (size_t j=0; j<n; ++j) {
      scanf("%d", &b);
      a[j] = b - a[j];
    }
    printf("%s\n", valid(a, n) ? "TAK" : "NIE");
  }
  return EXIT_SUCCESS;
}
