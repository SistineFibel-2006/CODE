#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i, a, b) for(long long i = (a); i < (b); i ++)


void sol() {
	int N; cin >> N;
	vector<int > A(N);
	rep(i, 0, N) cin >> A[i];
	ranges::sort(A);
	int ans = 0, pre = 0;
	rep(i, 0, N) ans += i * A[i] - pre, pre += A[i];
	cout << ans << '\n';
}


signed main() {
	int t = 1;
	// cin >> t;
	while(t --) sol();
	return 0;
}