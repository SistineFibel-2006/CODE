#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while(t --)
    solve();
}

void solve() {
  int n, s; cin >> n >> s;
  int cnt1 = 0, sum = 0;
  for(int i = 0; i < n; i ++) {
    int r, c; cin >> r >> c;
    if(r == 1)
      cnt1 ++;
    sum += c;
  }
  if(cnt1 * 2 >= n)
    cout << "1 ";
  else
    cout << "0 ";
  if(sum - s >= 50)
    cout << "1\n";
  else
    cout << "0\n";
}
