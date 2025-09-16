#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 0x3f3f3f3f;
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+1],al[n+1],ar[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>a[i],al[i]=0,ar[i]=INF;
    while(m--){
        int x,l,r;
        cin>>x>>l>>r;
        al[x]=max(al[x],l);
        ar[x]=min(ar[x],r);
    }
    for(int i=1;i<=n;i++){
        if(al[i]>ar[i]){
            cout<< -1<<"\n";
            return;
        }
        if(a[i]<al[i]||a[i]>ar[i]) ans+=min(abs(a[i]-al[i]),abs(a[i]-ar[i]));
    }
    cout<<ans<<"\n";
}
signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
//A