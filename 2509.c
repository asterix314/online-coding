#include <stdio.h>
#include <math.h>

int main()
{
	double n, k;
	while (EOF != scanf("%lf %lf", &n, &k))
		printf("%d\n", (int) floor((n * k - 1.0) / (k - 1.0)));
}