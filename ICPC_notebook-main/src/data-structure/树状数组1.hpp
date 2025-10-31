#include <bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
const ll inf = 2147483647;
int n, m, t[N];
int lowbit(int x) { return x & -x; }
void add(int x, int k) {
   while(x <= n) {
      t[x] += k;
      x += lowbit(x);
   }
}
int sum(int x) {
   int ans = 0;
   while(x) {
      ans += t[x];
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
      int x;
      cin >> x;
      add(i, x);
   }
   for(int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if(a == 1) add(b, c);
      if(a == 2) cout << sum(c) - sum(b - 1) << "\n";
   }
   return 0;
}