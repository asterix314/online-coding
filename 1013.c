#include <stdio.h>

int main() {
  int ncases = 0;
 
  char left[8];
  char right[8];
  char rtilt[8];

  if (1 != scanf("%d", &ncases))
    return 0; // input wrong

  for (int i=0; i<ncases; i++) {
    // assuming nothing unexpected from input
    
    scanf("%s %s %s", left, right, rtilt);
    printf("%s, %s, %s\n", left, right, rtilt);
    scanf("%s %s %s", left, right, rtilt);
    printf("%s, %s, %s\n", left, right, rtilt);
    scanf("%s %s %s", left, right, rtilt);
    printf("%s, %s, %s\n", left, right, rtilt);

  }
  return 0;
}
