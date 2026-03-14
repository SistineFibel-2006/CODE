#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fi first
#define se second 
#define ll long long
#define pb push_back


#define int long long

int ans[(int)(5e5 + 10)];

void solve() {
    int n; cin >> n;
    ans[0] = 0;
    for(int i = 1; i <= n; i ++) {
      int x, y; cin >> x >> y;
      ans[i] = (x - y);
    }
    ans[++n] = 0;
    sort(ans + 1, ans + n + 1);
    // ans.pb(0);
    int A = 0;
    for(int i = 1; i <= (n) / 2; i ++) A -= ans[i];
    for(int i = (n + 1) / 2 + 1; i <= n; i ++) A += ans[i];
    cout << A << endl;
    for(int i = 1; i <= (n) / 2; i ++) cerr << i << '\n';
    for(int i = (n + 1) / 2 + 1; i <= n; i ++) cerr << i << '\n';
} 

signed main() {
  int t = 1;
//   cin >> t;
  while(t --) solve();
}