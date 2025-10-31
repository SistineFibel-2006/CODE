#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
const ll inf = 2147483647;
struct edge {
   int v, next;
} e[N << 1];
int n, m, root, mod, ans[N << 2], tag[N << 2], son[N], id[N], fa[N], cnt, dep[N], siz[N], top[N], head[N], w[N], wt[N];
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
void push_up(int p) {
   ans[p] = ans[ls(p)] + ans[rs(p)];
   ans[p] %= mod;
}
void f(int l, int r, int p, int k) {
   ans[p] += (r - l + 1) * k;
   ans[p] %= mod;
   tag[p] += k;
}
void push_down(int l, int r, int p) {
   int mid = (l + r) >> 1;
   f(l, mid, ls(p), tag[p]);
   f(mid + 1, r, rs(p), tag[p]);
   tag[p] = 0;
}
void update(int l, int r, int p, int L, int R, int k) {
   if(L <= l && r <= R) {
      f(l, r, p, k);
      return;
   }
   int mid = (l + r) >> 1;
   push_down(l, r, p);
   if(L <= mid) update(l, mid, ls(p), L, R, k);
   if(R > mid) update(mid + 1, r, rs(p), L, R, k);
   push_up(p);
}
int query(int l, int r, int p, int L, int R) {
   if(L <= l && r <= R) return ans[p];
   int res = 0, mid = (l + r) >> 1;
   push_down(l, r, p);
   if(L <= mid) res += query(l, mid, ls(p), L, R), res %= mod;
   if(R > mid) res += query(mid + 1, r, rs(p), L, R), res %= mod;
   return res % mod;
}
void build(int l, int r, int p) {
   if(l == r) {
      ans[p] = wt[l] % mod;
      return;
   }
   int mid = (l + r) >> 1;
   build(l, mid, ls(p));
   build(mid + 1, r, rs(p));
   push_up(p);
}
void add(int u, int v) {
   e[++cnt].v = v;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void dfs1(int u, int father) {
   dep[u] = dep[father] + 1;
   fa[u] = father;
   siz[u] = 1;
   int hson = -1;
   for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(v == father) continue;
      dfs1(v, u);
      siz[u] += siz[v];
      if(siz[v] > hson) hson = siz[v], son[u] = v;
   }
}
void dfs2(int u, int topc) {
   id[u] = ++cnt;
   wt[cnt] = w[u];
   top[u] = topc;
   if(son[u] == 0) return;
   dfs2(son[u], topc);
   for(int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if(v == fa[u] || v == son[u]) continue;
      dfs2(v, v);
   }
}
void update1(int x, int y, int k) {
   k %= mod;
   while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) swap(x, y);
      update(1, n, 1, id[top[x]], id[x], k);
      x = fa[top[x]];
   }
   if(dep[x] > dep[y]) swap(x, y);
   update(1, n, 1, id[x], id[y], k);
}
int query1(int x, int y) {
   int res = 0;
   while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) swap(x, y);
      res += query(1, n, 1, id[top[x]], id[x]);
      res %= mod;
      x = fa[top[x]];
   }
   if(dep[x] > dep[y]) swap(x, y);
   res += query(1, n, 1, id[x], id[y]);
   return res % mod;
}
void update2(int x, int k) { update(1, n, 1, id[x], id[x] + siz[x] - 1, k); }
int query2(int x) { return query(1, n, 1, id[x], id[x] + siz[x] - 1); }
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m >> root >> mod;
   for(int i = 1; i <= n; i++) cin >> w[i];
   for(int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      add(x, y);
      add(y, x);
   }
   cnt = 0;
   dfs1(root, 0);
   dfs2(root, root);
   build(1, n, 1);
   while(m--) {
      int op, x, y, z;
      cin >> op;
      if(op == 1) {
         cin >> x >> y >> z;
         update1(x, y, z);
      }
      if(op == 2) {
         cin >> x >> y;
         cout << query1(x, y) << "\n";
      }
      if(op == 3) {
         cin >> x >> y;
         update2(x, y);
      }
      if(op == 4) {
         cin >> x;
         cout << query2(x) << "\n";
      }
   }
   return 0;
}