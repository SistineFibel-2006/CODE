#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

vector<int> adj[MAXN];
int color[MAXN];
int degree[MAXN];
long long fact[MAXN];

void dfs_color(int u, int c, int p) {
    color[u] = c;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_color(v, 3 - c, u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        degree[i] = 0;
        color[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    dfs_color(1, 1, 0);

    vector<int> s1, s2;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 1) {
            s1.push_back(i);
        } else {
            s2.push_back(i);
        }
    }

    if (n > 2 && (s1.size() == 1 || s2.size() == 1)) {
        cout << 0 << endl;
        return;
    }
    
    long long ways1 = 1, ways2 = 1;
    for (int u : s1) {
        ways1 = (ways1 * fact[degree[u]]) % MOD;
    }
    for (int v : s2) {
        ways2 = (ways2 * fact[degree[v]]) % MOD;
    }

    long long total_ways = (ways1 * ways2) % MOD;
    total_ways = (total_ways * 2) % MOD;

    cout << total_ways << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}