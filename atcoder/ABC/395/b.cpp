#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, x;
	cin >> n >> x;

	int vis[n + 1] = {0};

	cout  << n - x << endl;

	int temp;

	for(int i = 0; i < x; i ++) {
		cin >> temp;
		vis[temp] = 1;
	}

	for(int i = 1; i <= n; i ++)
		if(vis[i] == 0)
			cout << i << " ";



}

void solve(){

}