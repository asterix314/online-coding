#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* BFS search with manual queue management
 */

#define MAX_SIZE 20

unsigned count_black(unsigned w,  unsigned h) {
  char tiles[MAX_SIZE][MAX_SIZE+1] = {0};
  unsigned q[MAX_SIZE * MAX_SIZE] = {0};
  unsigned head = 0;
  unsigned count = 0;
  unsigned x = 0;
  unsigned y = 0;
  const char * vp = NULL;

#define get_x(p) ((p) % (1<<16))
#define get_y(p) ((p) >> 16)
#define pos(x, y) ((x) + ((y) << 16))

#define enqueue(x, y) {                         \
    q[count++] = pos(x, y);                     \
    tiles[y][x] = '@';                          \
  }
  
  // lay tiles and enqueue first visited position
  for (unsigned i=0; i<h; ++i) {
    scanf("%s", tiles[i]);
    vp  = strchr(tiles[i], '@');
    if (NULL != vp) enqueue(vp - tiles[i], i);
  }
  
  while (head != count) { // queue is not empty

    // dequeue
    x = get_x(q[head]);
    y = get_y(q[head]);
    head++;
    
    if (x+1 < w && '.' == tiles[y][x+1])
      enqueue(x+1, y);
    if (y > 0 && '.' == tiles[y-1][x])
      enqueue(x, y-1);
    if (x > 0 && '.' == tiles[y][x-1])
      enqueue(x-1, y);
    if (y+1 < h && '.' == tiles[y+1][x])
      enqueue(x, y+1);
  }
  return count;
}

int main() {
  unsigned w = 0;
  unsigned h = 0;
  
  while (2 == scanf("%u %u", &w, &h) && w && h)
    printf("%u\n", count_black(w, h));
  
  return EXIT_SUCCESS;
}
