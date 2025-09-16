#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
   // cin.tie(NULL)->sync_with_stdio(false);
    int t = 1; 
    //cin >> t; 
    while(t --) solve();


    return 0;
}
double dp[2][1000006];
void solve() {
    int a, b;
    double p,q;
    cin>>a>>b>>p>>q;
    p/=100;
    q/=100;
    for(int i=a-b;i>=0;i--){
        dp[0][i]=max(dp[1][i+b],dp[0][i+b])+;
        dp[1][i]=max(max(dp[1][i+b],dp[0][i+b])+1-q,max(dp[0][i+b-1],dp[1][i+b-1])+q);
    }
    double ans=0;
    for(int i=0;i<=(int)(a%b);i++){
        ans=max({ans,dp[0][i],dp[1][i]});
    }    
    cout<<ans<<endl;
    printf("%.15lf",ans);
}