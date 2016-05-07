#include <stdio.h>

int main()
{
	int n, i, i2, i3, j;
	int a[128];
	for (i = 1; i<=10; i++){
		i2 = i*i;
		i3 = i2 + 2 * i + 1;
		for (j=i2; j < i3; a[j++] = i);
	}
	scanf("%d", &n);
  	while (n--) {
    	if ((scanf("%d", &i) != EOF) && (i > 0))
    		printf("%d\n", a[i]);
  }
  return 0;
}