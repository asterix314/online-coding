#include <stdio.h>

int main()
{
  double sal, avg;
  double sum = 0.0;
  int m = 0;
  while (scanf("%lf", &sal) != EOF)
  {
    sum += sal;
    m++;
  }
  avg = sum / m;
  printf("$%.2f\n", avg);
}

