#include <bits/stdc++.h>
#include <compare>
#include <functional>
using namespace std;
#define int long long

struct Node {
	int w, v, c;
	bool operator<(const Node &b) const {
		return w * b.c > b.w * c;
	}
};

void solve() {
	int n; cin >> n;
	vector<Node> a(n);
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		int w, v, c; cin >> w >> v >> c;
		a[i] = {w, v, c};
	}
	sort(a.begin(), a.end());
	for(auto [w, v, c] : a){
		ans += v - c * sum;
		sum += w;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}