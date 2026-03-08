#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <memory>
#include <random>
using namespace std;
using I = int;
using Int = long long;
using ll = long long;
using u64 = uint64_t;
#define sz(x) ssize(x)

#define rep(i,a,b) for(Int i = a; i < (b); i ++)

auto KMP(string s) {
	vector<ll> p(sz(s));
	rep(i, 1, sz(s)) {
		ll g = p[i - 1];
		while(g && s[i] != s[g]) g = p[g - 1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

auto manacher(string s) {
   ll n = sz(s), i = 0, j = 0;
   vector<ll> r(n);
   while(i < n) {
      while(i >= j && i + j < n && s[i - j] == s[i + j]) j++;
      r[i] = j;
      ll k = 1;
      while(i >= k && i + k < n && k + r[i - k] < j) {
         r[i + k] = r[i - k];
         k++;
      }
      i += k, j -= k;
   }
   return r;
}


signed main () {

}

// abcba