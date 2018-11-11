#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned t;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n;
    scanf("%u", &n);
    unsigned y = 1 << n;
    unsigned x = (n%2 ? y+1 : y-1) / 3;
    printf("%u %u ", x, y);
  }
  return EXIT_SUCCESS;
}
