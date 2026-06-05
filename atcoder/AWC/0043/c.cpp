#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long 
#define rep(i, a, b) for(long long i = (a); i < (b); i ++)


void sol() {
	int N; cin >> N;
	vector<vector<int >> e(N + 1);
	rep(i, 2, N + 1) {
		int x; cin >> x;
		e[x].push_back(i);
	}

	vector<int > w(N + 1);
	rep(i, 1, N + 1) cin >> w[i];

	vector<int > sum(N + 1, 0);
	int ans = 0;

	auto dfs = [&](auto&&dfs, int u) ->void {
		sum[u] = w[u];
		vector<int > childsum;
		for(auto v : e[u]) dfs(dfs, v), sum[u] += sum[v], childsum.push_back(sum[v]);
		if(size(childsum) >= 2) {
			int maxx = childsum[0], minx = childsum[0];
			for(auto c : childsum) {
				maxx = max(maxx, c);
				minx = min(minx, c);
			}
			ans = max(ans, maxx - minx);
		}
	};

	dfs(dfs, 1);

	cout << ans << '\n';

}


signed main() {
	int t = 1;
	// cin >> t;
	while(t --) sol();
	return 0;
}