#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define rep(i, a, b) for(ll i = a; i < b; i ++)

const ll mod = 998244353;
struct mm {
   ll x;
   mm(ll x_ = 0) : x(x_ % mod) {
      if(x < 0) x += mod;
   }
   friend mm operator+(mm a, mm b) { return a.x + b.x; }
   friend mm operator-(mm a, mm b) { return a.x - b.x; }
   friend mm operator*(mm a, mm b) { return a.x * b.x; }
   friend mm operator/(mm a, mm b) { return a * b.inv(); }

   friend mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }
   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x; }
   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }
   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }
   mm inv() const { return pow(mod - 2); }
   mm pow(ll b) const {
      mm a = *this, c = 1;
      while(b) {
         if(b & 1) c *= a;
         a *= a;
         b >>= 1;
      }
      return c;
   }
};
struct Comb {
private:
    vector<mm> fact;
    vector<mm> invf;
public:
    Comb(int _n) {
        fact.resize(_n + 1);
        invf.resize(_n + 1);
        fact[0] = 1;
        rep(i, 1, _n + 1) fact[i] = fact[i - 1] * i;
        invf[_n] = fact[_n].inv();
        for(int i = _n; i > 0; i --) invf[i - 1] = invf[i] * i;
    }
    mm C(int n, int k) {
        if(k < 0 || k > n) return 0;
        return fact[n] * invf[k] * invf[n - k];
    }
};
