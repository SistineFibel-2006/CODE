#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数

signed main (){
    std::cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;  //atc默认关闭，cf按需开启
    while(t --)
        solve();
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int ans = 0;
    vector<int> p(n);
    for(int i = 0; i < n; i ++)
        p[i] = i;
    do{
        bool ok = true;
        for(int i = 0; i < n; i ++)
            if (i == p[i] || i == p[p[i]]) ok = false;
        if (ok){
            int tmp = 0;
            for(int i = 0; i < n; i ++)
                tmp += adj[p[i]][i];
            ans = max(ans, tmp);
        }
    }while (next_permutation(all(p)));
    cout << m - ans * 2 + n << "\n";
}