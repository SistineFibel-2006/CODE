#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int deg[1001], cnt, head[1001], n;
struct edge {
   int v, next, u;
} e[2002];
void add(int u, int v) {
   e[++cnt].v = v;
   e[cnt].next = head[u];
   head[u] = cnt;
}
void topo() {
   for(int i = 1; i <= n; i++) {
      if(deg[i] == 0) {
         q.push(i);
         cout << i << " ";
      }
   }
   while(!q.empty()) {
      int x = q.front();
      q.pop();
      for(int i = head[x]; i; i = e[i].next) {
         deg[e[i].v]--;
         if(deg[e[i].v] == 0) {
            q.push(e[i].v);
            cout << e[i].v << " ";
         }
      }
   }
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n;
   for(int i = 1; i <= n; i++) {
      int x;
      while(cin >> x) {
         if(x == 0) break;
         deg[x]++;
         add(i, x);
      }
   }
   topo();
   return 0;
}