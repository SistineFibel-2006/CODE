#include <stdio.h>
#include <cmath>
#include <iostream>
using ld = long double;
using ll = long long;
int main() {
  int n; scanf("%d", &n);
  ld ans = 0, res = 0;
  for(;n --;) {
    ll x; scanf("%lld", &x);
    ld a = sqrt((ld)x);
    ld t = ans + a + res;
    res = a + res - (t - ans);
    ans = t;
    printf("%.16Lg\n", ans);
  }
}
