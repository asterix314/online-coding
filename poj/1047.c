#include <stdio.h>
#include <math.h>


int main() {

  int n = 0;
  double Vs = 0.0, R = 0.0, C = 0.0, w = 0.0;
  
  if (4 != scanf("%lf %lf %lf %d", &Vs, &R, &C, &n))
    return 0;

  double R2C2 = R * R * C * C;
  
  for (int i=0; i<n; i++) {
    if (1 != scanf("%lf", &w))
      return 0;
    printf("%.3f\n", Vs / sqrt(1.0 + 1.0 / (R2C2 * w * w)));  
  }
  return 0;
}
