#include <stdio.h>
#include <string.h>

#define MAXLEN 128

int main()
{
	char buf[MAXLEN];
	int sum[MAXLEN];
	int len, i, c;

	memset(sum, 0, sizeof(sum));
	while (scanf("%s", buf) != EOF)
	{
		len = strlen(buf);
		for (i=0; i<len; i++)
			sum[i] += buf[len-1-i] - '0';
	}
	for (i=0, c=0; i<MAXLEN; i++)
	{
		sum[i] += c;
		c = sum[i] / 10;
		sum[i] %= 10;
	}
	i = MAXLEN;
	while (i>0 && !sum[--i])
		;
	do
		printf("%d", sum[i]);
	while (i--);
	putchar('\n');

	return 0;
}
