#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

<<<<<<< HEAD
// double factorial n!!
size_t fac2(size_t n) {
    size_t f2 = 0;
    for(f2=1; n>1; n-=2) {
        f2 *= n % MOD;
        f2 %= MOD;
    }
  return n;
=======
// double factorial x!!
long long fac2(long long x) {
//  printf("fac2(%lld)\n", x);
  long long ans = 1;
  for(long long k=x; k>1; k-=2)
    ans = (ans * k) % MOD;
  return ans;
}

int comp(const void *a, const void *b) {
  const long long *pa = a;
  const long long *pb = b;
  return *pb - *pa;
}


long long calc(long long s[], size_t k) {
  long long ans = 1;
  for(size_t j=0; j<k; ++j) {
//    printf("s[%zu] = %lld\n", j, s[j]);
    if (s[j]%2) {
      ans = (ans * fac2(s[j]-2)) % MOD;
      ans = (ans * s[j+1]) % MOD;
      --s[j+1];
    } else {
//      printf("s[%zu] = %lld\n", j, s[j]);
      ans = (ans * fac2(s[j]-1)) % MOD;
    }
  }
  return ans;
>>>>>>> 38489d512d9ed311532ae83e0bd425bf04bdee85
}

int main(void) {
  size_t t=0;
  scanf("%zu", &t);
<<<<<<< HEAD
  for (size_t i=0; i<t; ++i) {
    size_t n=0;
    scanf("%zu", &n);
    size_t s[100001] = {}; // sum of A, s[0] = 0.
    for (size_t j=1; j<=n; ++j) {
      size_t a = 0;
      scanf("%zu", &a);
      s[j] = s[j-1] + a;
    }
    printf("%zu\n", days(s, n));
=======

  for (size_t i=0; i<t; ++i) {
    size_t n=0;
    scanf("%zu", &n);
    long long s[100001]; // the S array.
    size_t k=0; // length of s to use as count

    for (size_t j=0; j<n; ++j)
      scanf("%lld", s+j);
    qsort(s, n, sizeof(s[0]), comp);
    k=0;
    for (size_t i=0,j=0; j<=n; ++j)
      if (s[i] != s[j] || j==n) {
        s[k++] = j-i;
        i = j;
      }

    printf("%lld\n", calc(s, k));
>>>>>>> 38489d512d9ed311532ae83e0bd425bf04bdee85
  }
  return EXIT_SUCCESS;
}

