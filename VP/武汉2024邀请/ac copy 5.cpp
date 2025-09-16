#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;


signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n+1],s=0;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    if(s%n==0) cout<<s/n;
    else{
        int ans=INF;
        int y=s%n,z=s/n,c=0;
        while(z>0&&y>0){
            if(z&1) break;
            c<<=1;
            c+=(y&1);
            y>>=1;
            z>>=1;
        }
        if(z==0) c=y;
        cout<<s/n+c;
    }
    return 0;
}