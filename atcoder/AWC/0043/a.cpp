#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i, a, b) for(long long i = (a); i < (b); i ++)


void sol() {
	int n, m; cin >> n >> m;
	rep(i, 0, n) {
		int x; cin >> x;
		m = (x * m) / 100;
	}
	cout << m << '\n';
}


signed main() {
	int t = 1;
	// cin >> t;
	while(t --) sol();
	return 0;
}