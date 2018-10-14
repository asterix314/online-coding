#include <stdio.h>
#include <string.h>

char* get_end(char *p)
{
	if (!p) return p;
	char c = *p;
	if (('p' <= c) && (c <= 'z'))
		return p + 1;
	else switch (c)
	{
	case 'N':	return get_end(p + 1);
	case 'C':
	case 'D':
	case 'E':
	case 'I':	return get_end(get_end(p + 1));
	}
	return NULL;
}

int main()
{
	char sen[256];
	while (EOF != scanf("%s", sen))
		puts(get_end(sen) == sen + strlen(sen) ? "YES" : "NO");
}