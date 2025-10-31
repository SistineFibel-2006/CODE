#include <bits/stdc++.h>
#define N 500005
using namespace std;
int lg[N], mi[22][N], n, m, s, dfn[N], dn, head[N], cnt;
struct edge {
   int v, next;
} e[N << 1];
int get(int x, int y) { return dfn[x] < dfn[y] ? x : y; }
void add(int u, int v) {
   e[++cnt].v = v;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void dfs(int now, int father) {
   dfn[now] = ++dn;
   mi[0][dfn[now]] = father;
   for(int i = head[now]; i; i = e[i].next)
      if(e[i].v != father) dfs(e[i].v, now);
}
int lca(int x, int y) {
   if(x == y) return x;
   if(dfn[x] > dfn[y]) swap(x, y);
   int deep = lg[dfn[y] - dfn[x] - 1];
   return get(mi[deep][dfn[x] + 1], mi[deep][dfn[y] - (1 << deep) + 1]);
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m >> s;
   for(int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      add(x, y);
      add(y, x);
   }
   for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
   dfs(s, 0);
   for(int i = 1; i <= lg[n]; i++) {
      for(int j = 1; j <= n - (1 << i) + 1; j++) { mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]); }
   }
   for(int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      cout << lca(x, y) << "\n";
   }
   return 0;
}