#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  const int *pa = a;
  const int *pb = b;
  return *pb - *pa;
}

size_t teams(int s[], size_t n, size_t k) {
  qsort(s, n, sizeof(s[0]), comp);
  while (k<n && s[k] == s[k-1])
    ++k;
  return k;
}

int main(void) {
  int s[100000];
  size_t t=0, n=0, k=0;
  scanf("%zu", &t);
  for (size_t i=0; i<t; ++i) {
    scanf("%zu %zu", &n, &k);
    for (size_t j=0; j<n; ++j)
      scanf("%d", s+j);
    printf("%zu\n", teams(s, n, k));
  }
  return EXIT_SUCCESS;
}

