#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* define a global dictionary so that items are automaticall
   initialized to 0. the first MAX_WORD_LENGTH items (1-based)
   are the starting points for the length-hashed words. */

#define MAX_DICT_LENGTH 10020
#define MAX_WORD_LENGTH 20

typedef struct {
  char text[MAX_WORD_LENGTH + 1];
  int order; // input order
  int next;  // forward list
} dict_t[MAX_DICT_LENGTH + 1];

void dict_insert(dict_t dict, const char word[], int order)
{
  // inserts word into dictionary
  
  static int next_index = MAX_WORD_LENGTH + 1;
  int len = strlen(word);

  if (dict[len].next) {
    strcpy(dict[next_index].text, word);
    dict[next_index].order = order;
    dict[next_index].next = dict[len].next;
    dict[len].next = next_index;
    ++next_index;
  }
  else {
    strcpy(dict[len].text, word);
    dict[len].order = order;
    dict[len].next = len;
  }
}

int dict_check_exact(const dict_t dict, const char word[])
{
  // returns 1 if exact match, else 0

  int len = strlen(word);
  int found = 0;
  
  if (!strcmp(dict[len].text, word))
    found = 1;
  else
    for(int i = dict[len].next; i > 0 && i != len; i = dict[i].next)
      if (!strcmp(dict[i].text, word)) {
	found = 1;
	break;
      }

  if (found)
    printf("%s is correct\n", word);
  
  return found;
}

int fuzzy_match(const char word[], const char dictword[])
{
  // returns 1 if fuzzy-matched, 0 otherwise
  
  int wlen = strlen(word);
  int dlen = strlen(dictword);

  int i;
  for(i = 0; word[i] == dictword[i]; ++i);
  
  if (wlen < dlen)       // insert match
    return i == strlen(word) || !strcmp(word + i, dictword + i + 1);
  else if (wlen > dlen)  // delete match
    return i == strlen(dictword) || !strcmp(word + i + 1, dictword + i);
  else                   // replace match
    return i == strlen(word) || !strcmp(word + i + 1, dictword + i + 1);
}


void dict_check_fuzzy(const dict_t dict, const char word[])
{ 
  int fuzzy_matches[MAX_DICT_LENGTH];
  int matches = 0;
  int wlen = strlen(word);

  // inspect delete, replace, and insert matches saperately
  for(int dlen = wlen - 1; dlen <= wlen + 1; ++dlen) {
    if (dict[dlen].next && fuzzy_match(word, dict[dlen].text))
	fuzzy_matches[matches++] = dlen;
    for(int i = dict[dlen].next; i > 0 && i != dlen; i = dict[i].next)
      if (fuzzy_match(word, dict[i].text))
	fuzzy_matches[matches++] = i;
  }

  //the fuzzy matched items need to be sorted.
  int fuzzy_comp(const void *a, const void *b) {
    int *i = (int *) a;
    int *j = (int *) b;
    return dict[*i].order - dict[*j].order;
  }
  qsort(fuzzy_matches, matches, sizeof(int), fuzzy_comp);
  
  printf("%s:", word);
  for(int i = 0; i < matches; ++i)
    printf(" %s", dict[fuzzy_matches[i]].text);
  putchar('\n');
}

int main()
{
  dict_t dict;
  char word[MAX_WORD_LENGTH + 1];
  
  // build dictionary
  for(int i = 0;
      1 == scanf("%s", word) && strcmp(word, "#");
      dict_insert(dict, word, ++i));
  
  // spell-check words against dictionary just built
  while(1 == scanf("%s", word) && strcmp(word, "#"))
    if (!dict_check_exact(dict, word))
      dict_check_fuzzy(dict, word);
}
