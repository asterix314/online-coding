#include <stdio.h>

int valid(int a[], int n) {
  for (int i=0; i<n-2; ++i) {
    if (a[i]>0) {
      a[i+2] -= a[i] * 3;
      a[i+1] -= a[i] * 2;
      a[i] = 0;
    }
    else if (a[i] < 0)
      return 0;
  }
  return !(a[n-1] || a[n-2]);
}

int main() {
  int a[100000] = {};
  int t=0, n=0, b=0;
  scanf("%d", &t);
  for (int i=0; i<t; ++i) {
    scanf("%d", &n);
    for (int j=0; j<n; ++j)
      scanf("%d", a+j);
    for (int j=0; j<n; ++j) {
      scanf("%d", &b);
      a[j] = b - a[j];
    }
    printf("%s\n", valid(a, n) ? "TAK" : "NIE");
  }
  return 0;
}

