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

	int t;
	cin >> t;
	while(t --)
		solve();



}

void solve(){
	int n, m;
	cin >> n >> m;
	i64 arr[n + 1][m + 1] = {0};
	map<int, i64> dx, dy;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			cin >> arr[i][j];
			dx[i - j + 1] += arr[i][j];
			dy[i + j - 1] += arr[i][j];
		}

	i64 cnt = 0;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			cnt = max(cnt, dx[i - j + 1] + dy[i + j - 1] - arr[i][j]);
		}

	cout << cnt << endl;
}