#include <stdio.h>
#include <stdlib.h>

void solve(unsigned n, unsigned k) {
  unsigned m=0; // count of a > 1
  for (unsigned i=0; i<n; ++i) {
    unsigned a;
    scanf("%u", &a);
    m += (a > 1);
  }
  printf("%s\n", k >= m ? "YES" : "NO");
}

int main(void) {
  unsigned t=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n, k;
    scanf("%u %u", &n, &k);
    solve(n, k);
  }
  return EXIT_SUCCESS;
}
