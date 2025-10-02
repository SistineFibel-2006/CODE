#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(size_t i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back
#define all(x) x.begin(),x.end()

void solve() {
    int n, m, k,mx1=0,mx2=0,mx3=0,ans=0; cin >> n >> m >> k;
    vector<int> vis(k+1, 0);
    vector<int> val(k+1,0);
    F(i, 0, n) {
        int x; cin >> x;
        vis[x] = 1;
    }
    map<pair<int, int>, int> mp;
    vector<int> g(k + 1, 0);
    F(i, 0, m) {
        int x, y; cin >> x >> y;
        // auto c = minmax(x, y); x = c.fi, y = c.se;
        if(vis[x]&&vis[y]) ans ++;
        else if(vis[x]) g[y] ++;
        else if(vis[y]) g[x] ++;
        else {
            if(x == y)
                g[x] ++;
            if(x > y) swap(x, y);
            mp[{x, y}] ++;  
        }
    }
    // for(auto i=mp.begin();i!=mp.end();i++){
    //     int x=i->first.first,y=i->first.first,w=i->second;
    //     // if(vis[x]+vis[y]==1){
    //     //     if(w>mx1) mx2=mx1,mx1=w;
    //     //     else if(w>mx2) mx2=w;
    //     // }
    //     if(vis[x]+vis[y]==2) mx3=max(mx3,w);
    // }
    for(auto [c, o] : mp) {
        auto [x, y] = c;
        mx3 = max(mx3, o + (x!=y) * (g[x] + g[y]));
    }
    sort(all(g),greater<int>());
    mx1 = g[0], mx2 = g[1];
    cerr << mx1 << ' ' << mx2 << ' ' << mx3 << '\n';
    cout<<ans+max(mx1+mx2,mx3)<<"\n";
}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}