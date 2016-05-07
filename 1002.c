/* POJ 1002 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 230507

typedef struct
{
  int num;		/* phone number converted to int */
  int dup; 		/* # of duplicates, 1 by default */
  int next;
} node;

int Hash[TABLE_SIZE];
int Ndups;		/* total # of duplicates */
int Dup[100000];	/* array of all duplicates. at most 100,000 numbers */
node *NodeTable;	/* static linked list */

int convert(char tel[])
/* convert telephone number string to int */
{
  static int letter[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
  int num = 0;
  char c;

  while ((c = *(tel++)) != '\0')
    if ('A' <= c && c < 'Z' && c != 'Q')
      num = num * 10 + letter[c - 'A'];
    else if ('0' <= c && c <= '9')
      num = num * 10 + c - '0';

  return num;
}

void insert_node(int number)
/* insert number to hash table
   record duplicates */
{
  static int p = 0;			/* place to insert new node in NodeTable */
  int index = number % TABLE_SIZE;	/* hash to index */
  int q = Hash[index];			/* first node */

  while (q)				/* search chain */
    if (NodeTable[q].num != number) 	
      q = NodeTable[q].next;
    else {
      if (2 == ++(NodeTable[q].dup))	/* duplicate */
        Dup[Ndups++] = q;
      break;
    }
  if (0 == q) {				/* number is new */
    p++;				/* add to NodeTable */
    NodeTable[p].num = number;
    NodeTable[p].dup = 1;
    NodeTable[p].next = Hash[index];	/* add to hash table chain */
    Hash[index] = p;
  }
}

int compare_node(const void* p1, const void* p2)	/* for qsort */
{
  int n1 = *(int*) p1;
  int n2 = *(int*) p2;

  return NodeTable[n1].num - NodeTable[n2].num;
}

int main()
{
  char tel[128];	/* telephone number string */
  int i, N, number;

  scanf("%d\n", &N);
  NodeTable = calloc(N + 1, sizeof(node));	/* NodeTable[0] is NULL */

  while(N--)
    insert_node(convert(gets(tel)));	/* gets is a little faster than fgets */

  if (0 == Ndups)
    puts("No duplicates.");
  else {
    qsort(Dup, Ndups, sizeof(int), compare_node);
    for(i = 0; i < Ndups; i++)
      printf("%03d-%04d %d\n",
             NodeTable[Dup[i]].num / 10000,
             NodeTable[Dup[i]].num % 10000,
             NodeTable[Dup[i]].dup);
  }

  return 0;
}

