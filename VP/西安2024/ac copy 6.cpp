#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;




signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n+1],c=0,s=0,ans[n+1],pd=1,c1=0,c2=0;
    for(int i=1;i<=n;i++){
        ans[i]=0;
        cin>>a[i];
        if(a[i]%2==1) a[i]=1,c1++;
        if(a[i]%2==0&&a[i]>=2) a[i]=2,c2++;
    }
    pd=pd^(k%2==1);
    for(int i=n;i>=1;i--){
        if(a[i]==1) ans[i]=pd,pd^=1;
    }
    for(int i=n;i>=1;i--){
        if(a[i]==2) ans[i]=pd^1;
    }
    for(int i=n;i>=1;i--) cout<<ans[i];
    return 0;
}