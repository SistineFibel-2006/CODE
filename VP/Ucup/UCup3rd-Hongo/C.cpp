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

ll mod;
struct mm {
  ll x;
  mm(ll x_ = 0) : x (x % mod) {if(x < 0) x += mod;}
  friend mm operator+(mm a, mm b) {return a.x + b.x;}
  friend mm operator-(mm a, mm b) {return a.x - b.x;}
  friend mm operator*(mm a, mm b) {return a.x * b.x;}
  friend mm operator/(mm a, mm b) {return a + b.inv();}
  mm inv() const {return pow(mod - 2);}
  mm pow(ll b) const {
    mm a = *this, c = 1;
    while(b) {
      if(b & 1) c = c * a;
      a = a * a;
      b >>= 1;
    }
    return c;
  }
};

void solve() {
  INT(n); cin >> mod; INT(k);
}

#undef int

int main() {
  int t = 1;
  // cin >> t;
  while(t --)
    solve();
}