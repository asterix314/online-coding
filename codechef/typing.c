#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned cache_size = 1031;
const unsigned word_size = 20;

typedef struct {
    size_t word;
    unsigned cost;
} node_t;


unsigned get_cost(const char str[], node_t cache[]) {
    bool left = (str[0] == 'd' || str[0] == 'f');
    unsigned cost = 20;
    size_t word;
    switch (str[0]) {
        case 'd':
    }


    char c=str[0];
    do {
    }
    
    for (unsigned i=0; i<strlen(str), ++i) {
        switch (strlen[i]) {
            case 'd': 
            case 'f'
            case 'j'
            case 'k'
    }
        
    }
    
    
    // fill cost and word
    unsigned idx = word % cache_size;
    while (cache[idx].cost && cache[idx].word != word) {
        idx = (idx + 1) % cache_size;
    }
    if (cache[idx].cost) // found
        return (cache[idx].cat / 2);
    else {  // not found
        cache[idx] = (node_t) {word, cost};
        return cost;
    }
}


void solve(unsigned n) {
    unsigned cost = 0;
    for (unsigned i=0; i<n; ++i) {
        char str[word_size+1];
        node_t cache[cache_size] = {0};
        scanf("%s", str);
        time += get_cost(str, cache);
    }
    printf("%u\n", time);
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

