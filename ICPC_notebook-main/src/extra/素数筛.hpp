#include <bits/stdc++.h>
using namespace std;
int prime[6000010], tot;
bool vis[100000010];
int main() {
   int q, n;
   cin >> n >> q;
   for(int i = 2; i <= n; i++) {
      if(vis[i] == 0) prime[++tot] = i;
      for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
         vis[i * prime[j]] = 1;
         if(i % prime[j] == 0) break;
      }
   }
   while(q--) {
      int k;
      cin >> k;
      cout << prime[k] << endl;
   }
   return 0;
}