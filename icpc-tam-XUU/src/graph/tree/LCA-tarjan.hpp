#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,m,s,cnt,vcnt,head[MAXN],vhead[MAXN],f[MAXN],lca[MAXN<<2];
bool vis[MAXN];
struct edge
{
    int to,next,vto,vnext;
}e[MAXN<<1];
void add(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void vadd(int u,int v)
{
    e[++vcnt].vto=v;
    e[vcnt].vnext=vhead[u];
    vhead[u]=vcnt;
}
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void tarjan(int u)
{
    vis[u]=1;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].to;
        if(vis[v]==1) continue;
        tarjan(v);
        f[v]=u;
    }
    for(int i=vhead[u];i;i=e[i].vnext){
        int v=e[i].vto;
        if(vis[v]==0) continue;
        lca[i]=find(v);
        if(i%2==1) lca[i+1]=lca[i];
        else lca[i-1]=lca[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        vadd(x,y);
        vadd(y,x);
    }
    tarjan(s);
    for(int i=1;i<=m;i++) cout<<lca[i*2]<<"\n";
    return 0;
}