#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define int long long
using vi = vector<int>;
#define rep(i, a, b) for(int i = (a); i < (b); i ++)
int cnt = 0;
void solve(int x) {
    // int x;
    // cin >> x;
    int l=0, r=1e6;
    int tmp = 0;
    while(l<r){
        int mid=l+r>>1;
        int res = mid*(mid+1);
        if(res > x) {
            // cerr << "yes\n";
            tmp = mid;
            r = mid;
        } else l = mid + 1;
    }
    l = tmp;
    // cerr << l-1 << '\n';

    int a = (l-1), c = (x-a*a);
    int ans = max(a,c) - min(a,c);
    // cout << a << ' ' << c << endl;
    a = (l-1), c = (x-a*(a+1));
    int b = a+1;
    if(c >= 0 && a*b+c == x)
    ans = min(max(a,max(b,c)) - min(a,min(b,c)), ans);

    a = (l-1), c = (x-a*(a+2));
    b = a+2;
    if(c >= 0 && a*b+c == x)
    ans = min(max(a,max(b,c)) - min(a,min(b,c)), ans);

    a = l, c = (x-a*a);
    b = a;
    if(c >= 0 && a*b+c == x)
    ans = min(max(a,max(b,c)) - min(a,min(b,c)), ans);

    // cout << ans << '\n';
    int ans2 = INT64_MAX/4;
    for(int i=0;i<=x;i++) {
      for(int j=0;j<=x;j++) {
        for(int k=0;k<=x;k++) {
          if(i*j+k == x){
            ans2 = min(max(i,max(j,k)) - min(i,min(j,k)), ans2);
          }
        }
      }
    }

    if(ans2 != ans) {
        cerr << "err x: " << x << "expected: " << ans2 << " but get " << ans << '\n';
        return;
    }
    cnt ++;

}

signed main() {
    int t = 1;
    cin >> t;
    while(t --){
        solve(t);
    }
    // cout << cnt;
}