#include <bits/stdc++.h>
using namespace std;
#define int long long

struct team{
	int x, id;
	string name;
	bool operator<(const team &b) const {
		return x > b.x;
	}
};


void solve() {
	int n, q; cin >> n >> q;
	vector<int> p(q);
	int minn = 1e18;
	for(int i = 0; i < q; i ++) {
		cin >> p[i];
		minn = min(minn, p[i]);
	}
	vector<team> a(n);
	for(int i = 0; i < n; i ++) {
		int x; string s;
		cin >> x >> s;
		a[i] = {x, i, s};
	} 
	sort(a.begin(), a.end());
	int cnt = 0;
	map<string, int> mp;
	vector<int> ans(n);
	for(auto [x, id, name] : a) {
		ans[id] = cnt + 1;
		if(mp[name] == minn)
			ans[id] --;
		if(mp[name] < minn)
			cnt += 1, mp[name] += 1;

	}
	for(int i = 0; i < n; i ++)
		cout << ans[i] << "\n";
}

signed main() {
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}