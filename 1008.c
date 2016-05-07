#include<stdio.h>

char* HAAB[] = {
	"pop","no","zip","zotz","tzec","xul","yoxkin",
	"mol","chen","yax","zac","ceh","mac","kankin",
	"muan","pax","koyab","cumhu","uayet"
};

char* TZOLKIN[] = {
	"imix","ik","akbal","kan","chicchan","cimi","manik",
	"lamat","muluk","ok","chuen","eb","ben","ix","mem",
	"cib","caban","eznab","canac","ahau"
};

int HASH_TABLE[64];

#define HASH(str) (((5381 * 33 + str[0]) * 33 + str[1]) % 53)
#define NUMBER(str) HASH_TABLE[HASH(str)]

int main()
{
	int i, n, m, d, y, days;
	char str[8];

	for (i = 0; i < 19; i++)	/* init table */
		HASH_TABLE[HASH(HAAB[i])] = i;
	scanf("%d", &n);
	printf("%d\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d. %s %d", &d, str, &y);
		m = NUMBER(str);
		days = y * 365 + m * 20 + d;
		y = days / 260;
		days %= 260;
		m = days % 20;
		d = days % 13;
		printf("%d %s %d\n", d+1, TZOLKIN[m], y);
	}
	return 0;
}


















