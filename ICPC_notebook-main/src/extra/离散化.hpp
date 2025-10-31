#include <bits/stdc++.h>
#define N 60006
#define ll long long
using namespace std;
const ll inf = 1e9;
int t[N], a[N], n, m, rank[N];
struct Node {
   int v, id;
   bool operator<(const Node a) const { return v < a.v; }
} b[N];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n;
   for(int i = 1; i <= n; i++) cin >> a[i], t[i] = a[i];
   sort(t + 1, t + n + 1);
   m = unique(t + 1, t + n + 1) - t - 1;
   for(int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + m + 1, a[i]) - t;

   for(int i = 1; i <= n; i++) {
      cin >> b[i].v;
      b[i].id = i;
   }
   sort(b + 1, b + n + 1);
   for(int i = 1; i <= n; i++) rank[b[i].id] = i;
   return 0;
}