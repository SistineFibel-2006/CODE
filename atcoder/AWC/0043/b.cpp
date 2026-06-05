#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i, a, b) for(long long i = (a); i < (b); i ++)


void sol() {
	int N, M; cin >> N >> M;
	vector<int > R(N + 1), o(N);
	rep(i, 1, N + 1) {
		cin >> R[i];
		o[i - 1] = i;
	}
	ranges::sort(o, [&](int a, int b) {
		return R[a] > R[b];
	});

	vector<vector<int >> e(N + 1);
	rep(i, 0, M) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}

	rep(i, 1, N + 1) ranges::sort(e[i]);

	vector<bool > vis(N + 1, 0);
	vector<int > part(N + 1, 0);
	int ans = 0;

	for(auto u : o) {
		if(vis[u]) continue;
		int v = -1;
		for(auto c : e[u]) if(!part[c]) {v = c; break; }
		vis[u] = vis[v] = 1;
		part[u] = v, part[v] = u;
		if(u == 1) ans = v;
		if(v == 1) ans = u;
	}

	cout << ans << '\n';
}


signed main() {
	int t = 1;
	// cin >> t;
	while(t --) sol();
	return 0;
}