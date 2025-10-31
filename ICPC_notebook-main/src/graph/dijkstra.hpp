#include <bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;
const ll inf = 2147483647;
struct edge {
   int v, next, w;
} e[N << 1];
struct node {
   int dis, pos;
   bool operator<(const node& x) const { return x.dis < dis; }
};
int n, m, head[N], cnt, s, dis[N];
bool vis[N];
priority_queue<node> q;
void add(int u, int v, int w) {
   e[++cnt].v = v;
   e[cnt].w = w;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void dijkstra() {
   dis[s] = 0;
   q.push({0, s});
   while(!q.empty()) {
      int x = q.top().pos;
      q.pop();
      if(vis[x] == 1) continue;
      vis[x] = 1;
      for(int i = head[x]; i; i = e[i].next) {
         int v = e[i].v;
         if(dis[v] > dis[x] + e[i].w) {
            dis[v] = dis[x] + e[i].w;
            if(vis[v] == 0) q.push({dis[v], v});
         }
      }
   }
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m >> s;
   for(int i = 1; i <= n; i++) dis[i] = inf;
   for(int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      add(x, y, z);
   }
   dijkstra();
   for(int i = 1; i <= n; i++) cout << dis[i] << " ";
   return 0;
}