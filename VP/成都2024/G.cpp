#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
const ll LINF = LLONG_MAX / 4;
#define rep(i,a,b) for(ll i = a; i < b; i ++)
#define all(a) a.begin(),a.end()
#define sz(a) size(a)
bool chmax(auto&a, auto b) {return a < b ? a = b, 1 : 0;}
bool chmin(auto&a, auto b) {return a > b ? a = b, 1 : 0;}
#define fi first 
#define se second 
#define eb emplace_back
#define pb push_back
#define in insert

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(auto & c : a)
    cin >> c;
  set<int> s;
  for(int i = 0; i < n - 1; i ++) {
    int x = a[i], y = a[i + 1];
    s.in(x); s.in(y);
    s.in(x&y); s.in(x|y); s.in(x^y);
    s.in(x&(x^y)); s.in(y&(x^y));
    s.in(0);
  }
  cout << sz(s);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1; 
  // cin >> t;
  while(t --)  {
    solve();
  }
}