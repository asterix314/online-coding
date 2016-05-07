/*********
biorythms.c
a simple application of the Chinese Remainder Thereom
*********/

#include <stdio.h>

int main()
{
	int periods[] = {23, 28,33};
	int prod = 23 * 28 * 33;
	int basis[] = {5544, 14421, 1288};	
	int rems[3];	
	int d = 0;
	int cnt = 0;
	int ans = 0;
	while ((EOF != scanf("%d %d %d %d", rems, rems+1, rems+2, &d)) && (d >= 0))
	{
		ans = rems[0] * basis[0] + rems[1] * basis[1] + rems[2] * basis[2];
		ans = (prod + ans - d - 1) % prod + 1;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cnt, ans);
	}
	return 0;
}

