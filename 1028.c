#include <stdio.h>

#define URL_LEN  128
#define URL_SIZE 128

int main()
{
  int current = 0;
  int last = 0;
  char c, cmd[16];
  char url_table[URL_LEN][URL_SIZE] = {"http://www.acm.org/"};

  while ((c = getchar()) != EOF)
    switch (c) {
    case 'V':   /* VISIT */
      if ((last = ++current) == URL_SIZE)
        return 1;
      scanf("%s %s", cmd, url_table[current]);
      puts(url_table[current]);
      break;
    case 'B':   /* BACK */
      gets(cmd);
      if (current > 0)
        puts(url_table[--current]);
      else 
        puts("Ignored");
      break;
    case 'F':   /* FORWARD */
      gets(cmd);
      if (current < last)
        puts(url_table[++current]);
      else
        puts("Ignored");
      break;
    case 'Q':   /* QUIT */
      return 0;
    }
  
  return 0;
}
