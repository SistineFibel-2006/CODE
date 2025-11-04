#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[105][10005],n,m,v[105],ans;
LL dfs(LL c,LL k){
    if(f[c][k])return f[c][k];
    if(v[c]>k)return 0;
    if(v[c]==k)return 1;
    for(LL i=c+1;i<=n;i++)f[c][k]+=dfs(i,k-v[c]);
    return f[c][k];
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++)scanf("%lld",&v[i]);
    for(LL i=1;i<=n;i++)ans+=dfs(i,m);
    printf("%lld\n",ans);
    return 0;
}