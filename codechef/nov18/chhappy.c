#include <stdio.h>
#include <stdlib.h>

void solve(unsigned n) {
  unsigned a[n+1], b[n+1];
  for (unsigned i=1; i<=n; ++i) { 
    scanf("%u", a+i);
    b[i] = 0;
  }
  for (unsigned i=1; i<=n; ++i) {
    if (a[i]<=n && a[a[i]]<=n) {
      if (0 == b[a[a[i]]])
        b[a[a[i]]] = a[i];
      else if (b[a[a[i]]] != a[i]) {
        printf("Truly Happy\n", i);
        return;
      }
    }
  }
  printf("Poor Chef\n");
}

int main(void) {
  unsigned t=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    unsigned n;
    scanf("%u", &n);
    solve(n);
  }
  return EXIT_SUCCESS;
}
