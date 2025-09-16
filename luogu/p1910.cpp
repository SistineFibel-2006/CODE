#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();

i64 dp[1010][1010];

signed main (){
	//std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	int x, y, z;
	for(int i = 1; i <= n; i ++){
		cin >> x >> y >> z;
		for(int j = m; j >= y; j--)
			for(int p = k; p >= z; p--)
				dp[j][p] = max(dp[j][p], dp[j - y][p - z] + x);
	}

	cout << dp[m][k];

	return 0; 
}

void solve(){

}