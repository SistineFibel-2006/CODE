#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 0x3f3f3f3f;
const int mod=99824435;
struct node{
    int x,y;
    bool operator<(const node &z)const{return z.y<y;}
};
int qpow(int x,int y){
    int base=x,ans=1;
    while(y){
        if(y&1) ans=(ans*base)%mod;
        base=(base*base)%mod;
        y>>=1;
    }
    return ans%mod;
}
void solve(){
       int n,m;
       cin>>n>>m;
       node a[n+1];
       int ans=0;
       for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
       sort(a+1,a+1+n);
       for(int i=1;i<=n;i++){
            if(a[i].x>=m) ans=(ans+(qpow(2,a[i].y)*(m/n))%mod)%mod;
       }
       cout<<ans<<"\n";
}

signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
