#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();

const int N = 10100;
int dp[N];

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<int > w(n);
	vector<int > v(n);
	vector<int > g(n);
	int x;
	int b[N] = {0};
	int lj[N][N];
	int lj2[N][N];
	for(int i = 0; i < n; i ++){
		cin >> w[i] >> v[i] >> g[i];
		x = max(x, g[i]); //组数
		b[g[i]] ++;  //每一组的物品数量
		lj[g[i]][b[g[i]]] = w[i]; //链接对应组别里的数据  
		lj2[g[i]][b[g[i]]] = v[i];
	}


	for(int i = 1; i <= x; i ++) //组数
		for(int j = m; j > 0; j --)  //限制容量
			for(int k = 1; k <= b[g[i]]; k ++) //枚举组内所有数据
				if(j >= lj[g[i]][b[g[i]]])
					dp[j] = max(dp[j], dp[j - lj[g[i]][b[g[i]]]] + lj2[g[i]][b[g[i]]]);

	cout << dp[m];

	return 0;
}

void solve(){

}

//97 unaccepted