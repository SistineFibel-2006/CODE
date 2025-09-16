#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1001][1001];
int vis[1001][1001] = {0};//ÊÇ·ñ´æ»î 
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	int tttt = t;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];
	while(tttt --)	{
		pair<int, int> now_max;
		int max = -1;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++){
				if(a[i][j] > max && vis[i][j] == 0){
					max = a[i][j];
					now_max.first = i;
					now_max.second = j;
				}
			}
		
		for(int j = 1; j <= m; j ++)
			vis[now_max.first][j] = 1;
		for(int i = 1; i <= n; i ++)
			vis[i][now_max.second] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		int time = 1;
		for(int j = 1; j <= m; j ++){
			if(vis[i][j])
				continue;
			if(time == m - t)
				cout << a[i][j] << endl;
			else
				cout << a[i][j] << ' ';
			time ++;
		}
	}
    return 0;
}
