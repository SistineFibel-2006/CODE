#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

void solve() {
    int n;
    cin>>n;
    int a[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<n;i++){
        int ans1=0,ans2=0;
        for(int j=1;j<i;j++) ans1=max(min(a[i],a[j])*(i-j),ans1);
        for(int j=i+1;j<=n;j++) ans2=max(min(a[i],a[j])*(j-i),ans2);
        ans=max(ans,ans1+ans2);
    }
    cout<<ans;
}