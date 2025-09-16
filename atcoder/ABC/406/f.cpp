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
1. С���ݣ��������ݣ��� n = 1?
2. ��Сֵ�����ֵȡ���٣��Ƿ�������
3. ��ʼֵ��û�и�ֵ����û�н�����
4. �����С���Ƿ�Խ�磿
5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
6. ������ϸ�ķ�������?
7. ѡ��������Ƿ����Ϊ�գ�

Trick:
1. 
2. 
3. 

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������
*/