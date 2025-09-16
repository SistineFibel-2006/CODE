#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, m, k;
int ans;
int g[N][N];
void dfs(int k){
	ans = min(ans, k);
	for (int i = 1; i <= n; i ++ ){
		for (int j = 1; j <= m; j ++ ){
			if (g[i][j]){
				if (i > 1 && i < n){
					//up
					if (!g[i - 1][j] && g[i + 1][j]){
						g[i + 1][j] = g[i][j] = 0;
						g[i - 1][j] = 1;
						dfs(k - 1);
						g[i + 1][j] = g[i][j] = 1;
						g[i - 1][j] = 0;
					}
					//down
					if (g[i - 1][j] && !g[i + 1][j]){
						g[i - 1][j] = g[i][j] = 0;
						g[i + 1][j] = 1;
						dfs(k - 1);
						g[i - 1][j] = g[i][j] = 1;
						g[i + 1][j] = 0;
					}
				}
				if (j > 1 && j< m){
					// right
					if (g[i][j - 1] && !g[i][j + 1]){
						g[i][j - 1] = g[i][j] = 0;
						g[i][j + 1] = 1;
						dfs(k - 1);
						g[i][j - 1] = g[i][j] = 1;
						g[i][j + 1] = 0;
					}
					//left
					if (!g[i][j - 1] && g[i][j + 1]){
						g[i][j + 1] = g[i][j] = 0;
						g[i][j - 1] = 1;
						dfs(k - 1);
						g[i][j + 1] = g[i][j] = 1;
						g[i][j - 1] = 0;
					}
				}
			}
		}
	}
}
void solve(){
	cin >> n >> m >> k;
	memset(g, 0, sizeof g);
	for (int i = 1; i <= k; i ++ ){
		int x, y;
		cin >> x >> y;
		g[x][y] = 1;
	}
	ans = k;
	dfs(k);
	cout << ans << '\n';
}


signed main () {
    int t;
    cin>>t;
    while(t--) 
        solve();
}