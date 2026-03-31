#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define rep(i,a,b) for(int i = (a); i < (b); i ++)
#define all(a) begin(a),end(a)
#define sz(a) ssize(a)
bool chmin(auto &a, auto b) {return a > b ? a = b, 1 : 0;}
bool chmax(auto &a, auto b) {return a < b ? a = b, 1 : 0;}

#define fi first
#define se second
#define eb emplace_back
#define pb push_back

void solve() {
  int n;
  cin >> n;
  ll last = 0, ans = 1;
  for(int i = 0; i < n; i++){
    int tp;
    cin >> tp;
    if(tp > last){
      ans += tp+1-last;
    }
    last = tp;
  }
  // if(ans == 1){
  //   ans = 0;
  // }
  cout << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t --) solve();
}