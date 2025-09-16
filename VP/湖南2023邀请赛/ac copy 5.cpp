#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    // int t; cin >> t; while(t --) solve();
    solve();

    return 0;
}

void solve() {

    int n,m;
    cin>>n>>m;
    char a[n+1],ans[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int t=n/2+1;
    for(int i=1;i<=m;i++){
        ans[i]=a[t]+12;
        if(ans[i]>'z') ans[i]-=26;
        t++;
        if(t==n+1) t=n/2+1;
    }
    int len=1;
    for(int i=1;i<=n/2;i++) swap(ans[i],ans[n-i+1]);
    //for(int i=1;i<=m;i++) cout<<ans[i];cout<<"\n";
    while(len<=m){
        for(int i=1;i<=len*3;i++){
            if(len>m) continue; 
            ans[i]++;
            if(ans[i]>'z') ans[i]-=26;
        }
        len*=2;
    }
    for(int i=m;i>=1;i--) cout<<ans[i];
}