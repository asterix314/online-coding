#include <stdio.h>
#include <stdlib.h>

const unsigned cache_size = 1031;
const unsigned word_size = 20;

typedef struct {
    size_t word;
    unsigned cost;
} node_t;

unsigned get_cost(const char str[], node_t cache[]) {
    unsigned cost = 2;
    size_t word =
        (str[0] == 'd' ? 0 :
        (str[0] == 'f' ? 1 :
        (str[0] == 'j' ? 2 : 3)));
    unsigned i = 1;
    while (str[i]) {
        word = word * 4 + 
            (str[i] == 'd' ? 0 :
            (str[i] == 'f' ? 1 :
            (str[i] == 'j' ? 2 : 3)));
        cost += ((str[i-1] < 'j') ^ (str[i] < 'j')) ? 2 : 4;
        ++i;
    }
    // search the cache
    unsigned idx = word % cache_size;
    while (cache[idx].cost && cache[idx].word != word) {
        idx = (idx + 1) % cache_size;
    }
    if (cache[idx].cost) {  // found
        return (cache[idx].cost / 2);
    } else {                // not found
        cache[idx] = (node_t) {word, cost};
        return cost;
    }
}

void solve(unsigned n) {
    unsigned cost = 0;
    node_t cache[cache_size] = {0};
    char str[word_size+1];
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

