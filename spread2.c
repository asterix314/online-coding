#include <stdio.h>

int days(const long long s[], int n) {
  long long k = 1; // people in the know
  int d = 0;
  for(d=0; k<n; ++d)
    k += s[k];
  return d;
}

int main() {
  long long s[100001]; // sum of A
  int t=0, n=0, a=0;
  scanf("%d", &t);
  for (int i=0; i<t; ++i) {
    scanf("%d", &n);
    s[0] = 0;
    for (int j=1; j<=n; ++j) {
      scanf("%d", &a);
      s[j] = s[j-1] + a;
    }
    printf("%d\n", days(s, n));
  }
  return 0;
}

