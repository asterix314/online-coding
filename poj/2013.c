#include <stdio.h>

int sym(int i, int L)
{
	return (i < (L + 1) / 2) ? 2 * i : 2 * (L - i) - 1;
}

int main()
{
	int set, L, i;
	char names[16][32];
	set = 0;
	while ((EOF != scanf("%d", &L)) && (L != 0))
	{
		for(i = 0; i < L; i++)
			scanf("%s", names + i);
		printf("SET %d\n", ++set);
		for(i = 0; i < L; i++)
			printf("%s\n", names + sym(i, L));
	}
	return 0;
}