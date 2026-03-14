#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;


void solve() {
    int k, x, y;
    cin >> k >> x >> y;
    // int l=0,r=floor((x+2*y) / k),s=k/2;
    // if(k%2==0){cout<<(x+2*y)/k<<"\n";return;}
    // while(l<r){
    //     int mid=(l+r)>>1;
    //     int cnt1=y/s,cnt2=y%s,cnt,ans=0;
    //     cnt=min(cnt1,x);
    //     if(x==cnt) ans=cnt+((cnt1-cnt)*s+cnt2)/(s+1);
    //     else 
    // }
    // cout<<r<<"\n";
    if(k %2== 0) {
        cout << (x + 2 * y) / k << endl;;
    } else {
        int ans = 0;
        int t = min(y, x * (k / 2));
        x += t * 2, y -= t;
        ans += x / k;
        ans += y / ((k + 1) / 2);
        cout << ans<< endl; 
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while(t --) solve();
}
