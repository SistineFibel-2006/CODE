#include <bits/stdc++.h>
#define inf 2147483647
#define ll long long
#define N 100005
using namespace std;
const int mod = 998244353;
struct edge {
   int v, next;
} e[N << 1];
int n, m, cnt, head[N], num, s[N], len, dfn[N], tot, low[N], scc[N];
vector<int> ans[N];
bool in[N], f[N];
void add(int u, int v) {
   e[++cnt].v = v;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void dfs(int x) {
   dfn[x] = low[x] = ++tot;
   s[++len] = x;
   in[x] = 1;
   for(int i = head[x]; i; i = e[i].next) {
      int y = e[i].v;
      if(dfn[y] == 0) {
         dfs(y);
         low[x] = min(low[x], low[y]);
      } else if(in[y] == 1) low[x] = min(low[x], low[y]);
   }
   if(dfn[x] == low[x]) {
      ans[++num].push_back(x);
      while(x != s[len]) {
         scc[s[len]] = num;
         in[s[len]] = 0;
         ans[num].push_back(s[len]);
         len--;
      }
      len--;
      in[x] = 0;
      scc[x] = num;
   }
}
void solve() {
   cin >> n >> m;
   for(int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      add(u, v);
   }
   for(int i = 1; i <= n; i++)
      if(dfn[i] == 0) dfs(i);
   for(int i = 1; i <= n; i++) sort(ans[i].begin(), ans[i].end());
   cout << num << "\n";
   for(int i = 1; i <= n; i++) {
      if(f[scc[i]] == 1) continue;
      f[scc[i]] = 1;
      for(int j = 0; j < ans[scc[i]].size(); j++) { cout << ans[scc[i]][j] << " "; }
      cout << "\n";
   }
}
signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int T = 1;
   // cin>>T;
   while(T--) solve();
   return 0;
}