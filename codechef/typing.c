#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CACHE_SIZE 1031
#define WORD_SIZE 30

static char cache[CACHE_SIZE][WORD_SIZE+1];
static unsigned cache_length = 0;

unsigned init_cost(const char str[]) {
  unsigned cost = 2;
  unsigned i = 0;
  while (str[++i])
    cost += ((str[i-1] < 'j') ^ (str[i] < 'j')) ? 2 : 4;
  return cost;
}

bool cache_lookup(const char word[]) {
    for (unsigned i=0; i<cache_length; ++i) {
        if (0 == strcmp(word, cache[i]))
            return true;
    }
    strcpy(cache[cache_length++], word);
    return false;
}

void cache_clean(void) {
    cache_length = 0;
}   

void solve(unsigned n) {
    unsigned cost = 0;
    cache_clean();
    for (unsigned i=0; i<n; ++i) {
        char word[WORD_SIZE+1];
        scanf("%s", word);
        cost += cache_lookup(word) ? init_cost(word)/2 : init_cost(word);
    }  
    printf("%u\n", cost);
}

int main(void) {
    unsigned t;
    scanf("%u", &t);
    for (unsigned i=0; i<t; ++i) {
        unsigned n;
        scanf("%u", &n);
        solve(n);
    }
    return EXIT_SUCCESS;
}
