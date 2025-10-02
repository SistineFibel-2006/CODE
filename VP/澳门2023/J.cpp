#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define eb emplace_back
#define in insert
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
// #define rep(i, n) for(size_t i = 0; i < n; i ++)
#define rep(i, a, b) for(size_t i = a; i < b; i ++)
#define F_(i, a, b) for(size_t i = b; i > a; i --)
#define I(x) int x;cin>>x
using i64 = long long;
#define i64(x) i64 x;cin>>x

const int N = 1e5 + 10;
int n, x, a[N], dis[N];
vi e[N];

void bfs() {
    for(int i = 0; i <= n; i ++) dis[i] = INT_MAX;
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : e[u]) {
            if(dis[v] == INT_MAX) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}


void solve() {
    cin >> n >> x;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i <= n; i ++) e[i].clear();
    for(int i = 0; i <= n; i ++) {
        int v = (i + a[i % n]) % n;
        if(v == 0) v = n;
        e[i].pb(v);
        if(i) {
            v = i + 1;
            if(v > n) v = 1;
            e[i].pb(v);
        }
    }
    bfs();
    cout << dis[x] << ' ';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) 
        solve();
}