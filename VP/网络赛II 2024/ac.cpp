#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
	int n = 1500;
	int q; cin >> q;
	for(int i = 1; i <= q; i ++) {
		int x; cin >> x;
		n += x;
		if(n >= 4000 ) {
			cout << i << endl;
			return;
		}
	}
	puts("-1");
}

signed main() {
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}