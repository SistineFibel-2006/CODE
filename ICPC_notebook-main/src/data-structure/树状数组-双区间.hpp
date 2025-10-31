#include <bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
const ll inf = 2147483647;
ll n, m, t1[N], t2[N];
ll lowbit(int x) { return x & -x; }
void add(ll x, ll k) {
   ll s = x;
   while(x <= n) {
      t1[x] += k;
      t2[x] += s * k;
      x += lowbit(x);
   }
}
ll sum(ll x) {
   ll ans = 0, s = x;
   while(x) {
      ans += (s + 1) * t1[x] - t2[x];
      x -= lowbit(x);
   }
   return ans;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m;
   for(int i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      add(i, x);
      add(i + 1, -x);
   }
   for(int i = 1; i <= m; i++) {
      ll pd, k, l, r;
      cin >> pd;
      if(pd == 1) {
         cin >> l >> r >> k;
         add(l, k);
         add(r + 1, -k);
      }
      if(pd == 2) {
         cin >> k;
         add(1, k);
         add(2, -k);
      }
      if(pd == 3) {
         cin >> k;
         add(1, -k);
         add(2, k);
      }
      if(pd == 4) {
         cin >> l >> r;
         cout << sum(r) - sum(l - 1) << "\n";
      }
      if(pd == 5) { cout << sum(1) << "\n"; }
   }
   return 0;
}