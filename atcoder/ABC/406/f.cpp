#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const int MAXN = 3e5 + 5;

struct trees {
    int n;
    vector<int> tree;
    trees(int size) : n(size), tree(size + 2) {}
    void add(int pos, int delta) {
        for(; pos <= n; pos += pos & -pos) 
            tree[pos] += delta;
    }
    int query(int pos) {
        int res = 0;
        for(; pos > 0; pos -= pos & -pos)
            res += tree[pos];
        return res;
    }
    int range(int l, int r) {
        return query(r) - query(l-1);
    }
};

vector<int> adj[MAXN];
int edge_child[MAXN], in[MAXN], out[MAXN], timer;

void dfs(int u, int parent) {
    in[u] = ++timer;
    for(auto [v, idx] : adj[u]) {
        if(v != parent) {
            edge_child[idx] = v;
            dfs(v, u);
        }
    }
    out[u] = timer;
}

void solve() {
    int N;
    cin >> N;

    for(int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    
    dfs(1, 0);
    trees ft(N);
    for(int i = 1; i <= N; ++i) 
        ft.add(in[i], 1);
    
    int total = N;
    
    int Q;
    cin >> Q;
    while(Q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, w;
            cin >> x >> w;
            ft.add(in[x], w);
            total += w;
        } 
		else {
            int y;
            cin >> y;
            int child = edge_child[y];
            int sum = ft.range(in[child], out[child]);
            cout << abs(2 * sum - total) << endl;
        }
    }
}

signed main() { 
    std::cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    while(t--) solve();
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