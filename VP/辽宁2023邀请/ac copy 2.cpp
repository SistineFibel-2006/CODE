#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
long long qpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int m(int a){return a % mod;}

void solve();

signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    // cout << qpow(2, 4) << endl;
    if(n < 5){cout << 0 << endl; return;}
    int g1 = a % mod * qpow(b, mod - 2) % mod;
    int g0 = (1 - g1 + mod) % mod;
    g1 = qpow(g1, 3) % mod;
    g0 = qpow(g0, 2) % mod;
    cout << g1 * g0 % mod * (n - 4) % mod << endl;
}