#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for one suffle to suffice, 
// the ring can have at most 1 downturn
bool possible(unsigned n) {
  unsigned a[n];
  unsigned down=0;
  for (unsigned i=0; i<n; ++i) {
    scanf("%u", a+i);
    if (i > 1 && a[i-1] > a[i]) ++down;
    if (down > 1) return false;
  }
  if (a[n-1] > a[0]) ++down;
  return (down <= 1);
}

int main(void) {
  unsigned t;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n;
    scanf("%u", &n);
    printf("%s\n", possible(n) ? "YES" : "NO");
  }
  return EXIT_SUCCESS;
}
