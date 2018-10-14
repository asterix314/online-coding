#include <stdio.h>
#include <math.h>

int main()
{
  float v, t, ar, arrival;
  int i, n;

  while ((scanf("%d", &n) != EOF) && (n > 0)) {
    arrival = 1e+10;    /* infinity */
    for (i = 0; i < n; i++) {
      scanf("%f %f", &v, &t);
      if ((t > -0.1) && ((ar = 4.5 / v * 3600.0 + t) < arrival))
        arrival = ar;
    }
    printf("%d\n", (int) ceilf(arrival));
  }

  return 0;
}
