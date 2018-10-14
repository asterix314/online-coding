#include <stdio.h>
#include <stdlib.h>

int inv(char dna[], int n)
{
	int i, v, A, C, G, T;
	v = A = C = G  = T = 0;
	for(i = 0; i < n; i++)
		switch (dna[i]) {
		case 'A': ++A; v += C + G + T; break;
		case 'C': ++C; v += G + T; break;
		case 'G': ++G; v +=	T; break;
		case 'T': ++T;
		}
	return v;
}

int compare(const void *a, const void *b)
{
	int *aa = (int *) a;
	int *bb = (int *) b;
	return (*aa - *bb);
}

#define MASK (1 << (sizeof(int) * 4)) - 1

int main()
{
	int i, n, m;
	char dnafile[128][64];
	int order[128];
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%s", dnafile[i]);
		order[i] = (inv(dnafile[i], n) << (sizeof(int) * 4)) | i;
	}
	qsort(order, m, sizeof(int), compare);
	for(i = 0; i < m; i++) {
		n = order[i] & MASK;
		printf("%s\n", dnafile[n]);
	}
	return 0;
}
