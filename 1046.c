#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i, j;
	int r, rr, g, gg, b, bb, dist;
	struct {
		int red;
		int green;
		int blue;
	} target[16];
	
	for (i = 0; i < 16; i++)
		scanf("%d %d %d", &target[i].red, &target[i].green, &target[i].blue);
	while ((EOF != scanf("%d %d %d", &r, &g, &b)) && (r >= 0)) {
		dist = INT_MAX;
		for (i = 0; i < 16; i++) {
			rr = r - target[i].red;
			gg = g - target[i].green;
			bb = b - target[i].blue;
			rr = rr * rr + gg * gg + bb * bb;
			if (rr < dist) {
				dist = rr;
				j = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, target[j].red, target[j].green, target[j].blue);
	}
}

