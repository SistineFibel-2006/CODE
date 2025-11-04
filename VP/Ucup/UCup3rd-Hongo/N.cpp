#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define rep(i,a,b) for(int i = (a); i < (b); i ++)
#define rrep(i,a,b) for(int i = (b); i-- > (a); )
#define all(a) a.begin(),a.end()
#define int long long
#define INT(...) int __VA_ARGS__; cin>>__VA_ARGS__
#define STR(...) string __VA_ARGS__; cin>>__VA_ARGS__
#define sz(s) size(s)
#define ll long long

auto KMP(string s) {
  vector<int> p(sz(s));
  int ans = 0;
  rep(i,1,sz(s)){
    ll g = p[i - 1];
    while(g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
    ans = max(ans, p[i]);
  }
  for(auto c : p) cerr << c << ' ';
  cerr << endl;
  return ans;
}

void solve() {
  INT(n); STR(s);
  // int ans = KMP(s);
  // string tt = s;
  // reverse(all(s));
  // if(tt == s) ans = sz(s);
  // cout << n * (n + 1) / 2 - ans * 2;
  int ans = n;
  int c[128]{0};
  rrep(i,1,n) {
    c[s[i]] ++;
    ans += (n - i) - c[s[i - 1]];
  }
  cout << ans << endl;
}

#undef int

int main() {
  int t = 1;
  // cin >> t;
  while(t --)
    solve();
}