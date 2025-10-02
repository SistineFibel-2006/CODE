#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(size_t i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back


void solve() {
  string s; cin >> s; const int n = s.length();
  int cnt2 = 0;
  array<array<int, 2>, 2> cnt{};
  for(int i = 0; i < n; i ++) {
    if(s[i] == '2') cnt2 ++;
    else cnt[i & 1][s[i] - '0'] ++;
  }
  int cnt1 = abs(cnt[0][1] - cnt[1][1]);
  int cnt0 = abs(cnt[0][0] - cnt[1][0]);
  int tt = min(cnt1, cnt2);
  cnt1 -= tt, cnt2 -= tt;
  tt = min(cnt0, cnt2);
  cnt0 -= tt, cnt2 -= tt;
  cnt2 %= 2;
  cout << cnt0 + cnt1 + cnt2 << endl;
}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}