#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second 
#define ll long long

#define int long long

const ll mod = 998244353;
struct mm {
  ll x;
  mm(ll _x = 0) : x (_x % mod) {
    if(x < 0) x += mod;
  }
  friend mm operator+(mm a, mm b) {return a.x + b.x;}
  friend mm operator-(mm a, mm b) {return a.x - b.x;}
  friend mm operator*(mm a, mm b) {return a.x * b.x;}
  friend mm operator/(mm a, mm b) {return a * b.inv();}
  mm inv() const {return pow(mod - 2);}
  mm pow(ll b) const {
    mm a = * this, c= 1;
    while(b) {if(b & 1) c = c * a;a = a * a;b >>= 1;}
    return c;
  }
};

void solve() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<mm> d(n + 1);
    d[0] = 1;
    vector<int> pre(n + 1, - 1);
    for(int i = 0; i < n; i ++) {
      int x = a[i];
      d[i + 1] = d[i] * 2;
      if(pre[x] != -1) {
        int j = pre[x];
        d[i + 1] = d[i + 1] - d[j];
      }
      d[1] = 1;
      pre[x] = i;
      cerr << "d[" << i <<  "].x: " <<d[i].x << '\n';
    }
    cout << d[n].x ;
}

signed main() {
  int t = 1;
//   cin >> t;
  while(t --) solve();
}