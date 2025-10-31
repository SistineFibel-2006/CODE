#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
const ll inf = 2147483647;
struct edge {
   int v, next, w;
   bool operator<(const edge& x) const { return x.w < w; }
} e[N << 1];
int head[N], cnt, n, m, tot, now = 1, ans, dis[N];
bool vis[N];
void add(int u, int v, int w) {
   e[++cnt].v = v;
   e[cnt].w = w;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void prim() {
   for(int i = 2; i <= n; i++) dis[i] = inf;
   for(int i = head[1]; i; i = e[i].next) dis[e[i].v] = min(dis[e[i].v], e[i].w);
   while(++tot < n) {
      int minn = inf;
      vis[now] = 1;
      for(int i = 1; i <= n; i++) {
         if(vis[i] == 0 && minn > dis[i]) {
            minn = dis[i];
            now = i;
         }
      }
      if(minn == inf) break;
      ans += minn;
      for(int i = head[now]; i; i = e[i].next) {
         int v = e[i].v;
         if(dis[v] > e[i].w) dis[v] = e[i].w;
      }
   }
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m;
   for(int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      add(x, y, z);
      add(y, x, z);
   }
   prim();
   if(tot == n - 1) cout << ans;
   else cout << "orz";
   return 0;
}