#include <stdio.h>
#include <math.h>

#define DIV(a, b) !((b) % (a))

typedef long long Long;



int phi(int n)

{

	int d, i, sqn, v;

	int prime[] = {1,1,1,1,1,1,1,1,1,1};


	sqn = floor(sqrt(n)), v = n, i = 0;

	if (DIV(2, v)) {

		prime[i++] = 2;

		while (DIV(2, v)) v >>= 1;

	}

	for (d = 3; d <= sqn; d += 2)

		if (DIV(d, v)) {

			prime[i++] = d;

			while (DIV(d, v)) v /= d;

		}	

	prime[i] = v;

	i = 0;

	while (prime[i] > 1) n = n / prime[i] * (prime[i] - 1), i++;

	return n;

}



int expm(int a, int k, int m)

{

	int v, n, i;
	Long y;


	v = k, n = 0;

	while ((v >>= 1) > 1) n++;

	y = a;

	for (i = n; i >= 0; i--) {

		y = (y * y) % m;

		if (k & (1 << i)) y = (y * a) % m;

	}

	return y;

}





int gcd(int a, int b)

{

	int t;
	while (b > 0) t = a % b, a = b, b = t;
	return a;
}


int main()

{	/* ax = b mod m, gcd(a, m) = 1 => x = b * a^(phi(m)-1) mod m */

	int x, y, m, n, L, a, b, d;


	scanf("%d %d %d %d %d", &x, &y, &m, &n, &L);
	b = (x - y) % L;
	if (b < 0) b += L;
	a = (n - m) % L;
	if (a < 0) a += L;
	d = gcd(a, L);

	if (DIV(d, b)) {
		a /= d, b /= d, L /= d;
		printf("%d\n", (Long)b * (Long)expm(a, phi(L) - 1, L) % L);
	} else puts("Impossible");


}
