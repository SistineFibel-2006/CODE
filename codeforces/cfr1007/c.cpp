#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int N = 1e5 + 10;



// void dfs(int v, int s){
// 	d[v] = d[s] + 1;
// 	vis[d[v]].push_back(v);
// 	for(auto c : e[v]) {
// 		if(c == s)
// 			continue;
// 		dfs(c, v);
// 	}
// }


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n, a, b;
	cin >> n >> a >> b;

	vector <vector<int>> e (n + 1, vector<int> ()), vis (n + 1, vector<int> ());
	std::vector<int> d(n + 1);

	int u, v;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	auto dfs = [&](auto &&self, int v, int par) -> void {
        d[v] = d[par] + 1;
        vis[d[v]].push_back(v);
        for (int u: e[v]) {
            if (u == par) continue;
            self(self, u, v);
        }
    };

	dfs(dfs, b, 0);

	for(int i = n; i >= 1; i --)
		for(auto c : vis[i])
			cout << c << ' ';

	cout << endl;
}