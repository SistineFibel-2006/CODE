#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <random>
using namespace std;
using I = int;
using Int = long long;
using ll = long long;
using u64 = uint64_t;
#define sz(x) ssize(x)

#define rep(i,a,b) for(Int i = a; i < (b); i ++)

const u64 mod = LLONG_MAX / 4;
u64 add(u64 a, u64 b) {
	a += b;
	if(a >= mod) a -= mod;
	return a;
}
u64 mul(u64 a, u64 b) {
	auto c = (u64)a * b;
	return add(c >> 61, c & mod);
}
random_device rnd;
const u64 r = ((u64)rnd() << 32 | rnd()) % mod;
struct RH {
	ll n;
	vector<u64> hs, pw;
	RH(string s) : n(sz(s)), hs(n + 1), pw(n + 1, 1) {
		rep(i,0,n) {
			pw[i + 1] = mul(pw[i], r);
			hs[i + 1] = add(mul(hs[i], r), s[i]);
		}
	}
	u64 get(ll l ,ll r) const { return add(hs[r], mod - mul(hs[l], pw[r - l]));}
};

signed main() {
	string a, b; cin >> a >> b;
	RH A(a), B(b);
	int N = min(sz(a), sz(b));
	for(Int i = N; i >= 1; i --) {
		int x = A.get(0, i);
		int y = B.get(sz(b)-i, sz(b));
		cerr << A.get(0, i) << ' ' << B.get(sz(b)-i, sz(b)) << endl;
		if(x == y) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}