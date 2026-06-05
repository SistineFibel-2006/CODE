#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define int long long
using vi = vector<int>;
#define rep(i, a, b) for(int i = (a); i < (b); i ++)

void solve() {
    int x;
    for(int i=500;i<=1000;i++) {
      x = i;
    

    int ans = INT64_MAX/4;
    int a,b,c;
    for(int i=0;i<=x;i++) {
      for(int j=0;j<=x;j++) {
        for(int k=0;k<=x;k++) {
          if(i*j+k == x){
            int copy_ans = ans;
            ans = min(max(i,max(j,k)) - min(i,min(j,k)), ans);
            if(ans != copy_ans){
              a=i;
              b=j;
              c=k;
            }
            
          }
        }
      }
    }

    cout << "x: " << x << " ans: " << ans << " abc: " << a << ' ' << b << ' ' << c << '\n';
    }


}

signed main() {
  int t = 1;
  cin >> t;
  while(t --) solve();
}