#include <stdio.h>
#include <stdlib.h>

/* extract from a[] the 2 longest segments of contiguous 1's.
   the result depend only on these 2 segments and their positions.
   shifting and query will be O(1).
*/

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

typedef struct {
  unsigned x1, x2; // start of 1
  unsigned d1, d2; // length of 1's
} measure;

measure* measure_init(measure* ms, unsigned n, const unsigned a[n]) {  
  unsigned s=0;    // start of 1's in a[]
  while (a[s] <= a[(n+s-1)%n] && s<n) ++s;
  if (s == n) {    // all the same
    *ms = (measure) {0};
    ms->d1 = a[0] ? n : 0;
  } else {         // search for 2 longest segments
    for (unsigned i=0; i<n; ++i) {
      unsigned x=s, d=0;
      if (a[(s+i)%n] < a[(s+i+1)%n]) {         // 01
        x = (s+i+1)%n;
      } else if (a[(s+i)%n] > a[(s+i+1)%n]) {  // 10
        d = (n+s+i+1-x)%n;
        if (d > ms->d1) {
          *ms = (measure) {.x1=x, .d1=d, .x2=ms->x1, .d2=ms->d1};
        } else if (d > ms->d2) {
          ms->x2 = x;
          ms->d2 = d;
        }
      }
    }
  }

  return ms;
}

measure* measure_rshift(measure* ms, unsigned n) {
  if (ms->d1 < n) { // else a[] is all 1's: do nothing.
    ms->x1 = (ms->x1 + 1) % n;
    ms->x2 = (ms->x2 + 1) % n;
  }
  return ms;
}

unsigned measure_length(const measure* ms, unsigned n, unsigned k) {
  if (ms->x1 + ms->d1 > n ) { // d1 wraps round
    return MIN(k,
               MAX(ms->d2,
                   MAX(n - ms->x1, ms->x1 + ms->d1 - n)));
  }
  return MIN(k, ms->d1);
}


int main(void) {
  unsigned n=0, q=0, k=0;
  scanf("%u %u %u", &n, &q, &k);
  unsigned a[n];
  for (unsigned i=0; i<n; ++i) {
    scanf("%u", a+i);
  }
  char query[q+1];
  scanf("%s", query);

  measure ms;
  measure_init(&ms, n, a);
  for (unsigned i=0; i<q; ++i) {
    if (query[i] == '!') {
      measure_rshift(&ms, n);
    } else {
      printf("%u\n", measure_length(&ms, n, k));
    }
  }

  return EXIT_SUCCESS;
}
