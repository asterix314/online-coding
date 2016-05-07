/* hangover.c
 * use hangover length as index to LOOKUP table
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE  530
#define MAX_CARDS 280

int LOOKUP[MAX_SIZE];
double eps = 1e-8; /* arbitrary small number */

void init_lookup()
{
  int i, j;
  double sum = 0.0;
  for (i = 1; i <= MAX_CARDS; i++)
  {
    sum += 1.0 / (i + 1.0);
    j = sum * 100.0 + eps; /* truncate */
    while ((j >=0) && (LOOKUP[j] == 0))
      LOOKUP[j--] = i;
  }
  LOOKUP[0] = 0; /* tweaking */
  /* LOOKUP[145] = 6; */
}

void print_table()
/* for debugging */
{
  int i;
  printf("lookup table is:\n");
  printf("-----");
  for (i=0; i < MAX_SIZE; i++)
  {
    if (i % 8 == 0)
      printf("\n");
    printf("%03d:%3d     ", i, LOOKUP[i]);
  }
  printf("\n-----\n");
}

int main()
{
  double h;
  int i;

  init_lookup();
  while ((scanf("%lf", &h) != EOF) && (h > 0.001))
  {
    i = h * 100.0 + eps;
    printf("%d card(s)\n", LOOKUP[i]);
  }
  return 0;
}
