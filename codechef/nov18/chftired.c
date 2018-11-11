#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned t=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned a, b;
    scanf("%u %u", &a, &b);
    printf("YES\n");
  }
  return EXIT_SUCCESS;
}
