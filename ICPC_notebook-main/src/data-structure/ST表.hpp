#include <bits/stdc++.h>
using namespace std;
int lg[100010], f[100010][20], n, m;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n >> m;
   for(int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
   for(int i = 1; i <= n; i++) cin >> f[i][0];
   for(int j = 1; j <= lg[n]; j++) {
      for(int i = 1; i <= n - (1 << j) + 1; i++) { f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); }
   }
   for(int i = 1; i <= m; i++) {
      int l, r;
      cin >> l >> r;
      int len = lg[r - l + 1];
      cout << max(f[l][len], f[r - (1 << len) + 1][len]) << "\n";
   }
   return 0;
}