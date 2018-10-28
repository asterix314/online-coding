#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1031
#define WORD_SIZE 30


typedef struct {
  size_t val;
  unsigned cost;
} node_t;

unsigned initial_cost(const char str[]) {
  unsigned cost = 2;
  unsigned i = 0;
  while (str[++i])
    cost += ((str[i-1] < 'j') ^ (str[i] < 'j')) ? 2 : 4;
  return cost;
}

unsigned get_cost(const char str[], node_t cache[]) {
  if (!str[0]) return 0;
  size_t val = 0;
  unsigned i = 0;
  while (str[i]) {
    val = (val << 3) + str[i] - 'd';
    ++i;
  }
  // search the cache
  unsigned idx = val % CACHE_SIZE;
  while (cache[idx].cost && cache[idx].val != val) {
    idx = (idx + 1) % CACHE_SIZE;
  }
  if (cache[idx].val == val) {  // found
    return cache[idx].cost / 2;
  } else {                // not found
    unsigned cost = initial_cost(str);
    cache[idx] = (node_t) {val, cost};
    return cost;
  }
}

void solve(unsigned n) {
  unsigned cost = 0;
  node_t cache[CACHE_SIZE] = {0};
  char str[WORD_SIZE+1];
  for (unsigned i=0; i<n; ++i) {
    scanf("%s", str);
    cost += get_cost(str, cache);
  }
  printf("%u\n", cost);
}

int main(void) {
  unsigned t=0, n=0;
  scanf("%u", &t);
  for (unsigned i=0; i<t; ++i) {
    scanf("%u", &n);
    solve(n);
  }
  return EXIT_SUCCESS;
}

