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


void solve() {
  int n,m;
  cin>>n>>m;
  int ans[n+1][m+1];
  if(m==1){
    if(n!=1) cout<<"No\n";
    else cout<<"Yes\n1\n";
    return;
  }
  if(n%2==0&&m%2){
    cout<<"No\n";
    return;
  }
  int cnt=0;
  for(int j=1;j<=m;j++){
    if(j%2) for(int i=1;i<=n;i++) ans[i][j]=++cnt;
    else for(int i=n;i>=1;i--) ans[i][j]=++cnt;
  }
  if(m%2){
    int cnt=1;
    for(int i=1;i<=n;i++) ans[i][1]=cnt++;
    for(int i=n;i>=1;i-=2) ans[i][2]=cnt++;
    for(int i=n-1;i>=1;i-=2) ans[i][2]=cnt++;
    for(int i=n-1;i>=1;i-=2) ans[i][3]=cnt++;
    for(int i=n;i>=1;i-=2) ans[i][3]=cnt++;
  }
  cout<<"Yes\n";
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
  }
}

#undef int

int main() {
  int t = 1;
  cin >> t;
  while(t --)
    solve();
}