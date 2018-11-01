#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    bool hosted[10] = {1,0,0,0,0,1,1,1,0,1};
    unsigned t=0, year=0;

    scanf("%u", &t);
    for (unsigned i=0; i<t; ++i) {
        scanf("%u", &year);
        printf("%s\n", hosted[year-2010] ? "HOSTED" : "NOT HOSTED");
    }
    return EXIT_SUCCESS;
}
