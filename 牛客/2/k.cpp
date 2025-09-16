// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'

// int dx[] = {1, -1, 1, -1};
// int dy[] = {1, 1, -1, -1};
// int cnt = 0;

// void dfs(int x, int y, 	vector<string> mp, vector<string> vis, int n, int m) {

// 	if(vis[x][y] == '1')
// 		return;
// 	vis[x][y] = '1';
// 	for(int i = 0, nx, ny; i < 4; i ++){
// 		nx = x + dx[i];
// 		ny = y + dy[i];
// 		if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m){
// 			if(mp[nx][ny] == '0' && vis[nx][ny] != '1'){
// 				cnt ++;
// 				vis[nx][ny] = '1';
// 			}
// 			else
// 				dfs(nx, ny, mp, vis, n, m);
// 		}
// 		else
// 			continue;
// 	}

// }

// signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
// 	int n, m;
// 	vector<string> mp(n);

// 	for(int i = 0; i < n; i ++)
// 		cin >> mp[i];

// 	i64 ans = 0;
// 	for(int i = 0; i < n; i ++)
// 		for(int j = 0; j < m; j ++){
// 			vector<string> vis(n,0);
// 			dfs(i,j,mp,vis,n,m);
// 			ans = max(ans, (i64)cnt);
// 		}

// 	cout << ans << endl;


// }



#include<bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, -1};

int ans=9999999999;
int cnt=0;
queue<pair<int ,int > > Q;
bool vis[510][510]={0};
int mp[510][510];
pair<int,int>p;
void dfs(int x,int y);
signed main(){

    for(int i=0;i<510;i++){
        for(int k=0;k<510;k++){
            mp[i][k]=-1;
        }
    }
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            char c;
            cin >> c;
            mp[i][k]=c-'0';
           
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(mp[i][k]==1&&vis[i][k]==0){
                cnt=0;
                dfs(i,k);
                ans=min(cnt,ans);
                 while(!Q.empty()){
                    vis[Q.front().first][Q.front().second]=0;
                    Q.pop();
                }
            }
        }
    }
    cout << ans << endl;
}


void dfs(int x,int y){
    if(mp[x][y]==-1||vis[x][y]==1)return;
    if(mp[x][y]==0){
        if(vis[x][y]==0){
            cnt++;
            vis[x][y]=1;
            p.first=x;
            p.second=y;
            Q.push(p);
        }
        return;
    }
    if(mp[x][y]==1){
        vis[x][y]=1;
        // for(int i = 0, nx, ny; i < 4; i ++) {
        // 	nx = x + dx[i];
        // 	ny = y + dy[i];
        // 	if(mp[nx][ny] != -1)
        // 		dfs(nx,ny);
        // }
        if(mp[x+1][y]!= -1)dfs(x+1,y);
        if(mp[x-1][y]!= -1)dfs(x-1,y);
        if(mp[x][y+1]!= -1)dfs(x,y+1);
        if(mp[x][y-1]!= -1)dfs(x,y-1);
    }
    return;
}