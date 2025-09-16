#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n+1],b[n+1],ans=0;
    priority_queue<int>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ans+=a[i];
        if(a[i]<b[i]) q.push(b[i]-a[i]);
    }
    cout<<m-n+q.size()<<"\n";
    for(int i=2;i<=m-(n-q.size());i+=2){
        if(!q.empty()) ans+=q.top(),q.pop();
        else break;
    }
    if(n==2&&m>n) ans=max(a[1]+a[2],b[1]+b[2]);
    cout<<ans<<"\n";
}
signed main () {
    int t;
    cin>>t;
    while(t--) solve();
}