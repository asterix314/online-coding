#include <stdio.h>
#include <limits.h>


int JOSE[16];

int jose(int k)
{
	int m, j, i, found;
	
	if (0 == JOSE[k]) {	/* memoization */
		m = k + 1;
		do {
			j = 1;
			for (i = 0; i < k; i++)
				if ((j = 1 + ((j + m - 2) % (2 * k - i))) <= k) break;
			found = (i == k);
		} while ((!found) && (m++ < INT_MAX));
		JOSE[k] = m;
	}
	return JOSE[k];
}

int main()
{
	int k;
	while ((scanf("%d", &k) != EOF) && (k > 0))
		printf("%d\n", jose(k));
	return 0;
}



