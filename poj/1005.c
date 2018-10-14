#include <stdio.h>
#include <math.h>


int main()
{
  int i, N, year;
  float x, y;

  scanf("%d\n", &N);
  for(i = 1; i <= N; i++) {
    scanf("%f %f\n", &x, &y);
    year = M_PI_2 * (x * x + y * y) / 50.0 + 1.0;
    printf("Property %d: This property will begin eroding in year %d.\n", i, year);
  }
  puts("END OF OUTPUT.");

  return 0;
}


