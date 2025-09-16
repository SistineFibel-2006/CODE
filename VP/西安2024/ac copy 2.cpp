#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;


signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int n;
    cin>>n;
    int a[n+1],b[n+1],s=0,x=1;
    map<int,int>mp;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=2;i<=n;i++) mp[(a[i]-a[1])/(i-1)]+=b[i],s+=b[i];
    int ans=0;
    for(auto i=mp.begin();i!=mp.end();i++) ans=max(ans,i->second);
    int ans2=0;
    for(int i=2;i<=n;i++) if(a[i]-a[1])
    cout<<s-ans<<"\n";
    return 0;
}