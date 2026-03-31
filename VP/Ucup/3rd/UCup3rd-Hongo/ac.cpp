#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define rep(i,a,b) for(int i = (a); i < (b); i ++)
#define rrep(i,a,b) for(int i = (b); i-- > (a); )
#define all(a) a.begin(),a.end()
#define int long long
#define INT(...) int __VA_ARGS__; cin>>__VA_ARGS__

void solve() {
  INT(n);
  vector<int> a(n);
  for(auto &&c : a) cin >> c;
  for(auto &c : a) c/=2;
  sort(all(a));
  int ans = 0;
  rep(i, 0, n - 2) {
    if(a[i] + a[i + 1] > a[i + 2])
      ans = max(ans, ((a[i]+a[i+1]+a[i+2])*(a[i]-a[i+1]+a[i+2])*(a[i]+a[i+1]-a[i+2])*(-a[i]+a[i+1]+a[i+2])));
      // ans=max(ans,(a[i]*a[i]+a[i+1]*a[i+1]))
  }
  if(ans==0) cout<<-1<<"\n";
  else cout<<ans<<"\n";
}

#undef int

int main() {
  int t = 1;
  cin >> t;
  while(t --)
    solve();
}