#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
const ll inf=2147483647;
struct edge
{
    int u,v,w;
}e[N<<1];
int n,m,f[N],ans,cnt;
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool cmp(edge a,edge b){return a.w<b.w;}
void kruscal()
{
    for(int i=1;i<=m;i++){
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv) continue;
        f[fu]=fv;
        ans+=e[i].w;
        if(++cnt==n-1) break;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+1+m,cmp);
    kruscal();
    if(cnt<n-1) cout<<"orz";
    else cout<<ans;
    return 0;
}