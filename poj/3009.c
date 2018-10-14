#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* BFS search with manual queue management
 */

#define MAX_SIZE 20

typedef struct {
  int brk_x, brk_y;
  int x, y;
  int prev;
} node;

int solve_curl(int w,  int h) {
  char board[MAX_SIZE][MAX_SIZE] = {0};
  node q[2 * MAX_SIZE * MAX_SIZE] = {0};
  int head = 0;
  int count = 0;

#define get_x(p) ((p) % (1<<16))
#define get_y(p) ((p) >> 16)
#define pos(x, y) ((x) + ((y) << 16))

#define enqueue(x, y) {                         \
    q[count++] = pos(x, y);                     \
    tiles[y][x] = '@';                          \
  }
  
  /*
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
  */
  return count;
}

int main() {
  int w = 0;
  int h = 0;
  
  while (2 == scanf("%d %d", &w, &h) && w>0 && h>0)
    printf("%u\n", solve_curl(w, h));
  
  return EXIT_SUCCESS;
}
