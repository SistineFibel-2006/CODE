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
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

void solve(){
	int n, m;
	cin >> n >>m;
	vector<vector<i64>> a(n, vector<i64> (m));
	string s;
	cin >> s;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> a[i][j];



	int x = 0, y = 0;
	i64 sum = 0;
	for(auto c : s){
		if(c == 'D') {
			sum = 0;
			for(int i = 0; i < m; i ++)
				sum += a[x][i];
			a[x][y] = (-sum);
			x ++;
		}
		else {
			sum = 0;
			for(int i = 0; i < n; i ++)
				sum += a[i][y];
			a[x][y] = (-sum);
			y ++;			
		}
	}


	sum = 0;
	for(int i = 0; i < m; i ++)
		sum += a[n - 1][i];

	a[n - 1][m - 1] = (-sum);

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cout << a[i][j] << " \n"[j == m - 1];
}