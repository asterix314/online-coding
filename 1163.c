#include<stdio.h>
#define MAX(a, b) (a > b ? a : b)

int main()
{
	int i, j, row, R, A[6000];

	scanf("%d", &R);
	for (i = 0; i < R * (R + 1) / 2; scanf("%d", A + (++i)));
	for (row = R - 1; row > 0; row--) {
		j = row * (row - 1) / 2 + 1;
		for (i = j; i < j + row; i++) 
			A[i] += MAX(A[i + row], A[i + row+1]);
	}
	return printf("%d\n", A[1]);
}