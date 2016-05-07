#include <stdio.h>
#include <string.h>

#define MAXCHAR 128
char BUFFER[MAXCHAR * 4];
char PLAIN_TEXT[MAXCHAR];
char CYPHER_TEXT[MAXCHAR];
char LENGTHS[MAXCHAR];

struct code_t {
	int len;
	char code[4];
};

struct code_t ENCODE[] = {
	{4,{1,1,0,0}},	{4,{0,0,0,1}},	{4,{1,0,1,0}},	{4,{0,0,0,0}},	{2,{1,0}},
	{4,{0,1,1,1}},	{4,{0,1,0,1}},	{3,{0,1,1}},	{1,{1}},		{4,{1,1,0,1}},
	{3,{0,0,1}},	{4,{1,1,1,1}},	{2,{1,1}},		{4,{1,0,0,0}},	{3,{0,1,0}},
	{4,{1,0,1,1}},	{2,{0,0}},		{2,{0,1}},		{3,{0,0,0}},	{4,{1,0,0,1}},
	{4,{0,0,1,0}},	{3,{1,0,1}},	{3,{1,1,1}},	{1,{0}},		{3,{1,1,0}},
	{4,{1,1,1,0}},	{3,{1,0,0}},	{4,{0,1,1,0}},	{4,{0,1,0,0}},	{4,{0,0,1,1}}
};

char DECODE[] = {
	'T', 'E', '*', '*', '*', '*', '*', '*', 
	'*', '*', '*', '*', '*', '*', '*', '*', 
	'M', 'N', 'A', 'I', '*', '*', '*', '*', 
	'*', '*', '*', '*', '*', '*', '*', '*', 
	'O', 'G', 'K', 'D', 'W', 'R', 'U', 'S', 
	'*', '*', '*', '*', '*', '*', '*', '*', 
	'?', '.', 'Q', 'Z', 'Y', 'C', 'X', 'B', 
	'J', 'P', ',', 'L', '_', 'F', 'V', 'H'
};

void encode(void)
{
	int tlen;	/* plain text length */
	int clen;	/* code length */
	int i, j, b, index;
	char c;
	
	tlen = strlen(PLAIN_TEXT);
	b = 0;	/* index to BUFFER */
	for (i = 0; i < tlen; i++) {
		switch (c = PLAIN_TEXT[i]) {
		case '_': index = 0; break;	/* to ENCODE */
		case '.': index = 1; break;
		case ',': index = 2; break;
		case '?': index = 3; break;
		default:  index = 4 + c - 'A'; break;			
		}
		clen = LENGTHS[i] = ENCODE[index].len;
		for (j = 0; j < clen; j++)
			BUFFER[b++] = ENCODE[index].code[j];
	}
	BUFFER[b] = '\0';	
	b = 0;
	for (i = 0; i < tlen; i++) {
		clen = LENGTHS[tlen - i - 1];
		index = 0;	/* to DECODE */
		for (j = 0; j < clen; j++)
			index = (index << 1) + BUFFER[b++];
		index += ((clen-1) << 4);
		CYPHER_TEXT[i] = DECODE[index];
	}
	CYPHER_TEXT[i] = '\0';
}

int main(void)
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", PLAIN_TEXT);
		encode();
		printf("%d: %s\n", i, CYPHER_TEXT);
	}
	return 0;
}


