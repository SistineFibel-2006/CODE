#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

vector<int> parent;

int root (int u) {
  if (parent[u] == u) return u;
  else return parent[u] = root(parent[u]);
}

void dsu (int u, int v) {
  parent[root(u)] = root(v);
}

bool connected(int u, int v) {
	return root(u) == root(v);
}


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n, m;
	cin >> n >> m;
	parent.assign(n + 1, 0);
	for(int i = 1; i <= n; i ++)
		parent[i] = i;
	int ans = 0;
	for(int i = 0; i < m; i ++){
		int x, y;
		cin >> x >> y;
		if(!connected(x, y))
			dsu(x, y);
		else
			ans ++;	
	}
	cout << ans;
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/