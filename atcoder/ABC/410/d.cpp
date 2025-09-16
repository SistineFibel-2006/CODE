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
const int MAXN = 1005;


signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

// vector<pair<int, int>> adj[MAXN];
// int dis[MAXN];
// bool vis[MAXN];
// vector<int> cnt;
// void work(int v) {
//     for (int b : cnt) {
//         v = min(v, v ^ b);
//     }
//     if (v > 0) {
//         cnt.push_back(v);
//     }
// }
// void dfs(int u) {
//     vis[u] = true;
//     for (auto& edge : adj[u]) {
//         int v = edge.first;
//         int w = edge.second;
//         if (vis[v]) {
//             int ans1 = dis[u] ^ w ^ dis[v];
//             work(ans1);
//         } 
//         else {
//             dis[v] = dis[u] ^ w;
//             dfs(v);
//         }
//     }
// }


void solve(){
int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    
    for (int i = 0; i < M; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }

    vector<vector<bool>> vis(N + 1, vector<bool>(1024, false));
    queue<pair<int, int>> q; //BFs
    
    vis[1][0] = true;
    q.push(make_pair(1, 0));

    while (!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (const auto& ad : adj[u]) {
            int v = ad.first;
            int w = ad.second;
            int ans1 = x ^ w;  
 
            if (!vis[v][ans1]) {
                vis[v][ans1] = true;
                q.push(make_pair(v, ans1));
            }
        }
    }

    int ans = INF;
    for (int x = 0; x < 1024; x ++) {
        if (vis[N][x]) {
            ans = min(ans, x);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;  
    } 
    else {
        cout << ans << endl; 
    }
}
//test
/*
?
// ? (?????) ?
*/

/*
What's wrong with my code?
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/
