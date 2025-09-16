#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int> > g(n, vector<int> (n, 0));
	vector<vector<int> > h(n, vector<int> (n, 0));
	vector<vector<int> > a(n, vector<int> (n, 0));
	int t;
	cin >> t;
	for(int i = 0, x, y; i < t; i ++){
		cin >> x >> y;
		g[x][y] = 1;
	}
	cin >> t;
	for(int i = 0, x, y; i < t; i ++){
		cin >> x >> y;
		h[x][y] = 1;
	}
	for(int i = 0; i < )


}

void solve(){

}