#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    
    vector<array<int,3>>arr(n);
    for(auto &[l, r, y] : arr){
      cin >> l >> r >> y;
    }
    int sx, sy;
    cin >> sx >> sy;

    sort(arr.begin(), arr.end(), [&](auto a, auto b){
      return a[2]>b[2];
    });
    for(auto &[l, r, y] : arr){
      if(sy < y)continue;
      if(l < sx&&sx <= r){
        sx = r;
      }       
    }
    cout << sx << '\n';
}

signed main() {
    int t = 1;
    cin >> t;
    while(t --) solve();
}
