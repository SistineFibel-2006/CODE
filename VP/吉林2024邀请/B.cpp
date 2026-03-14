#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;


void solve() {
    int n;
    cin>>n;
    int a[n+1];
    vector<vector<int>>e(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    auto dfs=[&](auto dfs,int u,int fa){
        if(u==0) return;
        dp
        for(auto v:g[u]){
            if(v==fa) continue;
            dfs(dfs,v,u);
        }
    };
    dfs(dfs,1,0);
}

signed main() {
    int t = 1;
    cin >> t;
    while(t --) solve();
}
