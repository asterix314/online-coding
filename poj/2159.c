#include <stdio.h>
#include <string.h>

#define BUFSIZE 128
#define CNTSIZE 32

void get_metrics(char buf[], int *m0, int *m1, int *m2)
{
	char c;
	int cnt[CNTSIZE];
	int i, t0, t1, t2;

	memset(cnt, 0, sizeof(cnt));
	i = t0 = t1 = t2 = 0;
	while ((c = buf[i++]) != '\0')
		++cnt[c - 'A'];
	for (i=0; i<CNTSIZE; i++)
		if (cnt[i] > 0)
		{
			++t0;
			t1 += cnt[i];
			t2 += cnt[i] * cnt[i];
		}
	*m0 = t0;
	*m1 = t1;
	*m2 = t2;
}

int main()
{
	char buf[BUFSIZE], c;
	int i;
	int t0, t1, t2; /* plain text metrics */
	int s0, s1, s2; /* cypher text metrics */

	scanf("%s", buf);
	get_metrics(buf, &s0, &s1, &s2);
	scanf("%s", buf);
	get_metrics(buf, &t0, &t1, &t2);
	if (s0 == t0 && s1 == t1 && s2 == t2)
		puts("YES");
	else
		puts("NO");
	return 0;
}
