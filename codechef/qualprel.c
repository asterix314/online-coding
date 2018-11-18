#include <stdio.h>
#include <stdlib.h>

/* solution: sort the array s[] in descending order,
   then count in any peers of s[k]. it's inefficient 
   when k << n because s[k...n] need not be sorted,
   but seems to work anyways.
*/

int cmp(const void *pa, const void *pb) {
  unsigned a = *((const int*) pa);
  unsigned b = *((const int*) pb);
  return a<b ? 1 : (a>b ? -1 : 0);
}

unsigned teams(unsigned n, unsigned k) {
  unsigned s[n];
  for (unsigned i=0; i<n; ++i) {
    scanf("%u", s+i);
  }
  qsort(s, n, sizeof s[0], cmp);
  while (k<=n && s[k] == s[k-1]) {
    ++k;
  }
  return k;
}

int main(void) {
  unsigned t=0, n=0, k=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    scanf("%u %u", &n, &k);
    printf("%u\n", teams(n, k));
  }
  return EXIT_SUCCESS;
}
