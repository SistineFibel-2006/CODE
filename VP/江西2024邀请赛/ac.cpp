#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int n,s;
    cin>>n>>s;
    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(s==sum) cout<<n;
    else cout<<n-1;
    return 0;
}

