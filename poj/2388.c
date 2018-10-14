#include <stdio.h>

int milk[10000];

int partition(int left, int right, int pivot)
{
	int v, i, j, t;
	v = milk[pivot];
	milk[pivot] = milk[right];
	j = left;
	for (i = left; i < right; i++)
		if (milk[i] < v)
		{
			t = milk[i];
			milk[i] = milk[j];
			milk[j] = t;
			j++;
		}
	milk[right] = milk[j];
	milk[j] = v;
	return j;
}

int select(int left, int right, int k)
{
	int middle, pivot;
	while (1)
	{
		middle = (left + right) / 2;
		pivot = milk[left] < milk[middle] ? left : middle;
		if (milk[pivot] < milk[right])
			pivot = right;
		middle = partition(left, right, pivot);
		if (k == middle)
			return milk[k];
		else if (k < middle)
			right = middle - 1;
		else
			left = middle + 1;
	}
}

int main()
{
	int i, cows;
	scanf("%d", &cows);
	for (i = 0; i < cows; i++)
		scanf("%d", milk + i);
	printf("%d\n", select(0, cows - 1, cows / 2));

	return 0;
}
