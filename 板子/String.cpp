#include "bits/stdc++.h"
using namespace std;
#define sz(x) ssize(x)
template <class T> 
using v = vector<T>;
using I = int;
using ll = long long;
using Int = ll;
#define rep(i, a, b) for(ll i = (a); i < (b); i ++)
#define rrep(i, a, b) for(ll i = (b); i --> a; i ++)
#define all(a) begin(a), end(a)


struct SA {
	int m = 128;
	string s;
	int n;
	v<I> rk, oldrk, sa, id, cnt;
	SA(const string &s) : s(" " + s), n(sz(s)) {
		rk.resize(2 * n + 10);
		sa.resize(n + 10);
		id.resize(n + 10);
		cnt.resize(max(m, n) + 10);
		oldrk.resize(2 * n + 10);
		build();
	}

	void build() {
		int p = 0;
		for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
 	 	for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  	for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

  	for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
	    int cur = 0;
	    for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
	    for (int i = 1; i <= n; i++)
	      if (sa[i] > w) id[++cur] = sa[i] - w;
	    fill(all(cnt), 0);
	    for (int i = 1; i <= n; i++) cnt[rk[i]]++;
	    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	    for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
	    p = 0;
	    oldrk = rk;
	    for (int i = 1; i <= n; i++) {
	      if (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
	        rk[sa[i]] = p;
	      else
	        rk[sa[i]] = ++p;
	    }
	    if (p == n) break;  // p = n 时无需再排序
  	}
	}

	v<I> gethei() { // hei[i] = LCP(sa[i - 1], sa[i])
		v<I> hei(n + 10, 0);
		I p = 0;
		rep(i, 1, n + 1) {
			if(p) p --;
			while(s[i + p] == s[sa[rk[i] - 1] + p]) p ++;
			hei[rk[i]] = p;
		}
		v<I> ans;
		rep(i, 1, sz(s)) ans.push_back(hei[i]);
		// 注意 ans[0] 无意义，hei[i] = LCP(SA[i - 1], SA[i])
		return ans;
	}

	v<I> getsa() {
		v<I> ans;
		rep(i, 1, sz(s)) ans.push_back(sa[i] - 1);
		return ans;	
	}
};

struct SAM { // 0 - based
	v<I> pa, len, siz, isend;
	v<array<int, 26>> ch;
	I idx = 0, pre = 0;
	SAM(string s) {
		ch.resize(2 * sz(s) + 10);
		pa.resize(2 * sz(s)  + 10);
		len.resize(2 * sz(s)  + 10);
		siz.resize(2 * sz(s)  + 10);
		len[0] = 0, pa[0] = -1, idx = 0, pre = 0;
		for(auto c : s) ins(c - 'a');
	}

	void ins(int c) {
		I p = pre, np = ++ idx;
		pre = np; siz[np] = 1;
		len[np] = len[p] + 1;
		while(p != -1 && ch[p][c] == 0) ch[p][c] = np, p = pa[p];

		if(p == -1) pa[np] = 0;
		else {
			I q = ch[p][c];
			if(len[q] == len[p] + 1) pa[np] = q;
			else {
				I nq = ++ idx;
				len[nq] = len[p] + 1;
				ch[nq] = ch[q];
				pa[nq] = pa[q];
				pa[q] = pa[np] = nq;
				while(p != -1 && ch[p][c] == q) ch[p][c] = nq, p = pa[p];
			}
		}
	}

	v<v<I>> getpa() {
		v<v<I>> tree(SAM::idx + 1);
		rep(i, 1, SAM::idx + 1) tree[pa[i]].push_back(i);
		return tree;
	}	
};

#define max(a, b) (a)>(b)?((ll)a):((ll)b)

signed main() {
	int n; cin >> n;
	string s; cin >> s;
	SAM sam(s);
	auto&& siz = sam.siz;
	auto&& len = sam.len;
	auto&& e = sam.getpa();
	ll ans = 0;
	rep(i, 1, sz(len)) ans += len[i] - len[sam.pa[i]];
	// auto dfs = [&](auto&&dfs, int u = 0) -> void {
	// 	for(auto v : e[u]) {
	// 		dfs(dfs, v);
	// 		siz[u] += siz[v];
	// 	}
	// 	if(u && siz[u] != 1) ans = max(ans, 1LL * siz[u] * len[u]);
	// };
	// dfs(dfs);
	cout << ans;
	// // int n; cin >> n;
	// string s; cin >> s;
	// // SA SA1(s);
	// // auto sa = SA1.getsa();
	// // auto hei = SA1.gethei();
	// // ll ans = 0;
	// // rep(i, 0, n) {
	// // 	ans += n - sa[i] - hei[i];
	// // }
	// // cout << ans;
	// ll ans = 0;
	// rep(i, 0, sz(hei)) ans = max(ans, hei[i]);
	exit(0);
}