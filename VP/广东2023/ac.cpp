#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int ans;
bool a[10][10];   

void dfs(int k) {
    ans = min(k, ans);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            if(a[i][j]){
                if(i > 1 && i < n){
                    //up
                    if(a[i - 1][j] && !a[i + 1][j]){
                        a[i + 1][j] = 0;a[i][j] = 0;
                        a[i - 1][j] = 1;
                        dfs(k - 1);
                        a[i + 1][j] = 1;a[i][j] = 1;
                        a[i - 1][j] = 0;
                    }
                    //down
                    if(!a[i - 1][j] && a[i + 1][j]){
                        a[i - 1][j] = 0;a[i][j] = 0;
                        a[i + 1][j] = 1;
                        dfs(k - 1);
                        a[i - 1][j] = 1;a[i][j] = 1;
                        a[i + 1][j] = 0;
                    }
                }
                if(j > 1 && j < m){
                    //left
                    if(a[i][j - 1] && !a[i][j + 1]){
                        a[i][j + 1] = 0;a[i][j] = 0;
                        a[i][j - 1] = 1;
                        dfs(k - 1);
                        a[i][j + 1] = 1;a[i][j] = 1;
                        a[i][j - 1] = 0;
                    }
                    //right
                    if(!a[i][j - 1] && a[i][j + 1]){
                        a[i][j - 1] = 0;a[i][j] = 0;
                        a[i][j + 1] = 1;
                        dfs(k - 1);
                        a[i][j - 1] = 1;a[i][j] = 1;
                        a[i][j + 1] = 0;
                    }
                }
            }
        }
    
}

void solve()
{   
    cin >> n >> m >> k;
    memset(a, 0, sizeof a);
    for(int i = 1, x, y; i <= k; i ++){
        cin >> x >> y;
        a[x][y] = 1; 
    }
    ans = k;
    dfs(k);
    cout << ans << endl;   
}
signed main () {
    int t;
    cin>>t;
    while(t--) 
        solve();
}