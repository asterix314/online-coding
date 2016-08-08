#include <vector>
#include <string>
#include <map>
#include <iostream>

const int MAX_DICT_LENGTH = 10000;

/* define a global dictionary so that items are automaticall initialized to 0.
 * the first MAX_WORD_LENGTH items (1-based) are the starting points for the
 *　length-hashed words.
 */


int main()
{
  std::string word;
  std::map<string, int> dict;
  for (int i = 0; (std::cin >> word) && (word != "#"); ++i)
    

  return 0;

    /*
  // build dictionary
  for(int i = 0;
      1==scanf("%s", word) && strcmp(word, "#");
      insert_dict(word, ++i));

  // spell-check words against dictionary just built
  while(1==scanf("%s", word) && strcmp(word, "#"))
    if (find_word(word)) // exact match
      printf("%s is correct\n", word);
    else
      fuzzy_check(word);

    */
}





/*
struct {
  char text[MAX_WORD_LENGTH + 1];
  int order;
  int next;
} DICT[MAX_DICT_LENGTH + 1];

void insert_dict(const char word[], int k)
{
  static int next_index = MAX_WORD_LENGTH + 1;
  int len = strlen(word);

  if (DICT[len].next) {
    strcpy(DICT[next_index].text, word);
    DICT[next_index].order = k;
    DICT[next_index].next = DICT[len].next;
    DICT[len].next = next_index;
    ++next_index;
  }
  else {
    strcpy(DICT[len].text, word);
    DICT[len].order = k;
    DICT[len].next = len;
  }
}

int find_word(const char word[])
{
  int len = strlen(word);
  if (DICT[len].next) {
    int i = len;
    do {
      if (!strcmp(DICT[i].text, word))
	return i;
      else
	i = DICT[i].next;
    } while (i != len);
  }
  return 0;
}

int delete_check(const char word[])
{
  // deleting of one letter from the word
  int len = strlen(word);
  char fuzzy[MAX_WORD_LENGTH + 1];
 
  for(int i = 0; i < len; ++i) {
    strcpy(fuzzy, word);
    memmove(fuzzy + i, fuzzy + i + 1, len - i);
    if ( = find_word(fuzzy)) {
      fuzzy_matches[matches]
    }
  }
  return 0;
}

int replace_check(const char word[])
{
  // replacing of one letter in the word with an arbitrary letter
  char fuzzy[MAX_WORD_LENGTH + 1];
  
  return 0;
}

int insert_check(const char word[])
{
  // inserting of one arbitrary letter into the word
  char fuzzy[MAX_WORD_LENGTH + 1];
    
  return 0;
}

int comp(const void *a, const void *b)
{
  int *i = (int *) a;
  int *j = (int *) b;
  return DICT[*i].order - DICT[*j].order;
}

void fuzzy_check(const char word[])
{
  static int fuzzy_matches[MAX_DICT_LENGTH];
  int matches = 0;

  printf("%s:", word);
  
  if (strlen(word) > 1)
    matches += delete_check(word);
  matches += replace_check(word);
  matches += insert_check(word);

  if(matches) {
    qsort(fuzzy_matches, matches, sizeof(int), comp);
    for(int i = 0; i < matches; ++i)
      printf(" %s", DICT[fuzzy_matches[i]].text);
  }
  putchar('\n');
}


*/
