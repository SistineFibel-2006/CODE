#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
struct edge
{
    int v,next;
}e[MAXN<<1];
int dep[MAXN],head[MAXN],f[MAXN][22],lg[MAXN],n,m,s,cnt;
void add(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int now,int father)
{
    f[now][0]=father;
    dep[now]=dep[father]+1;
    for(int i=1;i<=lg[dep[now]];i++) f[now][i]=f[f[now][i-1]][i-1];
    for(int i=head[now];i;i=e[i].next){
        if(e[i].v!=father) dfs(e[i].v,now);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=f[x][lg[dep[x]-dep[y]]];
    if(x==y) return x;
    for(int i=lg[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    dfs(s,0);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<"\n";
    }
    return 0;
}