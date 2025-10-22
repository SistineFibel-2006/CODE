#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
const ll LINF = LLONG_MAX / 4;
#define rep(i,a,b) for(ll i = a; i < b; i ++)
#define all(a) a.begin(),a.end()
#define sz(a) ssize(a)
bool chmax(auto&a, auto b) {return a < b ? a = b, 1 : 0;}
bool chmin(auto&a, auto b) {return a > b ? a = b, 1 : 0;}
#define fi first 
#define se second 
#define eb emplace_back
#define pb push_back

void solve() {
  string a;
  cin>>a;
  string s;
  int n=a.size();
  int cnt[n+1]={0};
  s=s+a[0];
  cnt[0]=1;
  for(int i=1;i<n;i++){
    if(a[i]==s[s.size()-1]) cnt[s.size()-1]++;
    else s=s+a[i],cnt[s.size()-1]++;
  }
  if(s.size()>=3&&s[0]=='>'&&s[s.size()-1]=='>'&&cnt[s.size()-1]>=3){
    cout<<"Yes ";
    vector<pair<int,int>>ans;
    for(int i=a.size()-1;i>a.size()-1-cnt[s.size()-1]+3;i--) ans.push_back({i-3,5});
    int r=a.size()-1-cnt[s.size()-1]+3;
    for(int i=0;i<=r-4;i++){
      if(a[i]=='>') ans.push_back({i+1,r-i+1});
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
  }
  else cout<<"No\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1; 
  cin >> t;
  while(t --)  {
    solve();
  }
}