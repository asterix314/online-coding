#include <stdio.h>

int main()
{
	int i, h;
	const int wheeler = 168;
	for (i=0; i<3; i++)
		if (1 == scanf("%d", &h) && h <= wheeler)
		{
			printf("CRASH %d\n", h);
			return 0;
		}
	puts("NO CRASH");
	return 0;
}
