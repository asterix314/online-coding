#include <stdio.h>
#include <stdlib.h>

size_t days(const size_t s[], size_t n) {
  size_t k = 1; // people in the know
  size_t d = 0;
  while(k<n) {
    k += s[k];
    ++d;
  }
  return d;
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

