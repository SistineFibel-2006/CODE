#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; i ++)
#define rrep(i,a,b) for(int i = (b); i --> a; )
#define fi first
#define se second
using ll = long long;
using I = int;
using Int = long long;
#define sz(x) (int)size(x)

#define int long long

auto solve = []() -> void {
  int n,m,k;
  cin>>n>>m>>k;
  

  // vector<int>s(n+1),ans(n+1);
  // vector<vector<int>>a(k+1,vector<int>(n+1));
  // for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) cin>>a[i][j],s[j]+=a[i][j];

  // int sum=0;
  // for(int i=1;i<=n;i++) ans[i]=s[i]/k*k,sum+=ans[i];
  // while(sum<m){

  // }


  ll a[500][500], c[500];
  rep(i, 0, k) rep(j, 0, n) cin >> a[j][i];
  ll ans = 0;
  
  rep(i, 0, n) {
    sort(a[i], a[i] + k);
    rep(j, 0, k) {
      ans += a[i][j];
      c[j] += a[i][j] - a[i][j - 1];
    }
  }
  rep(i, 0, k) {
    ll t = min(m, c[i]);
    m -= t;
    ans += (i - (k - i)) * t;
  }
  cout << ans / 2;
};
signed main() {
  int t = 1;
  // cin >> t;
  while(t --> 0) solve();
}