#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //MOD

const int N = 1e5 + 10;

struct Edge {
	int to, next;
}t[N << 1];
int head[N << 1], cnt = 0;
int vis[N] = {0};
void init(int n) {
	for(int i = 0; i <= n; i ++)
		head[i] = -1;
	cnt = 0;
}

void add(int u, int v){
	t[++ cnt].to = v;
	t[cnt].next = head[u];
	head[u] = cnt;
} 

void dfs(int u) {
	for(int i = head[u]; i; i = t[i].next) {
		int v = t[i].to;
		if(vis[v])
			continue;
		vis[v] = vis[u] + 1;
		dfs(v);
	}
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  
	while(t --)
		solve();
}

void solve(){
	int n, d;
	cin >> n >> d;
	for(int i = 0; i < n; i ++){
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	int ans = 0;
	dfs(vis[1] = 1);
	for(int i = 2; i <= n; i ++){
		if(vis[i] - 1 <= d)
			ans ++;
	}
	cout << ans;
}
