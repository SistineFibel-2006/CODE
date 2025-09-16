#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y
const int maxv = 11;
const int maxk = 1 << 10;

vector<vector<pair<int, i64>>> adj(maxv);
i64 dp[maxv][maxk];
i64 ans = LLONG_MAX;
int N;

void dfs(int u, int mask, i64 cc) {
    if (cc >= dp[u][mask]) {
        return;
    }
    dp[u][mask] = cc;

    if (u == N) {
        if (cc < ans) {
            ans = cc;
        }
        return;
    }

    for (auto& edge : adj[u]) {
        int v = edge.first;
        i64 w = edge.second;
        if (!(mask & (1 << (v - 1)))) {
            int new_mask = mask | (1 << (v - 1));
            dfs(v, new_mask, cc ^ w);
        }
    }
}


signed main() {
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 0; i < maxv; ++i) {
        for (int j = 0; j < maxk; ++j) {
            dp[i][j] = LLONG_MAX;
        }
    }

    ans = LLONG_MAX;

    dfs(1, 1 << 0, 0);

    cout << ans << endl;

    return 0;
}

void solve() {

}


