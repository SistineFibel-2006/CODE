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
  int a,b,c;
  cin>>a>>b>>c;
  int n=100;
  cout<<n<<"\n";
  for(int i=1;i<=50;i++) cout<<a<<" ";
  for(int i=51;i<=95;i++) cout<<b<<" ";
  for(int i=96;i<=99;i++) cout<<c<<" ";
  cout<< c + 1 <<"\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1; 
  // cin >> t;
  while(t --)  {
    solve();
  }
}