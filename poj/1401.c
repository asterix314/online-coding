#include <stdio.h>

int main ()
{
  int lines, n, z;
  scanf ("%d", &lines);
  while ((lines--) && (scanf ("%d", &n) > 0))
    {
      z = 0;
      do
	{
	  n /= 5;
	  z += n;
	}
      while (n);
      printf ("%d\n", z);
    }
  return 0;
}
