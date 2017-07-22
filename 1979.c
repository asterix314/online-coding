#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define get_x(p) ((p) % 256)
#define get_y(p) ((p) / 256)
#define pos(x, y) ((x) + (y) * 256)

#define enqueue(x, y) {                         \
    q[count++] = pos(x, y);                     \
    tiles[y][x] = '@';                          \
  }
         
size_t count_black(size_t w, size_t h) {

  char tiles[h][w+1];
  size_t q[w*h];
  size_t head = 0;
  size_t count = 0;
  const char * vp = NULL;

  // lay tiles and enqueue first visited position
  for (size_t i=0; i<h; ++i) {
    scanf("%s", tiles[i]);
    vp  = strchr(tiles[i], '@');
    if (NULL != vp) enqueue(vp - tiles[i], i);
  }

  size_t x = 0;
  size_t y = 0;
  
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
  size_t w = 0;
  size_t h = 0;
  
  while (2 == scanf("%zu %zu", &w, &h) && w)
    printf("%zu\n", count_black(w, h));
  
  return EXIT_SUCCESS;
}
