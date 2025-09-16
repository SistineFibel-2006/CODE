#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve ();

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
}

void solve () {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > ed(n);
    for(int i = 0; i < n - 1; i ++) {ed[i].push_back(i + 1);ed[i + 1].push_back(i);}
    ed[0].push_back(n - 1);ed[n - 1].push_back(0);
    while(m --){
        int x, y;
        cin >> x >> y;
        ed[x].push_back(y);ed[y].push_back(x);
    }
    
    vector<int> dis(n,0x7f7f7f7f);
    // queue<pair<int,int>> q;
    // pair<int,int> temp;
    // temp.first = 0, temp.second = 1;

    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()){
        int fi = q.front(); q.pop();
        for(auto c : ed[fi])
            if(dis[c] > dis[fi] + 1){
                dis[c] = dis[fi] + 1;
                q.push(c);    
            }
    }
    // for (auto c : dis)
    //     cerr << c << " ";


    for(int i = 0; i < n; i ++)
        if(dis[i] % 2 == 1)
            cout << "B";
        else cout << "R";
    cout << '\n';
}