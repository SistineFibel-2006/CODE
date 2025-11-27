#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int inf=1e18;
const int N=250005;
struct Tree{
    int cnt,head[N];
    struct edge{
        int v,w,next;
    }e[N<<1];
    void add(int u,int v,int w){
        e[++cnt]={v,w,head[u]};
        head[u]=cnt;
    }
}e1,e2;
int n,m,idx,top,st[N],a[N],dfn[N],fa[N][18],lg[N],mn[N],dp[N],dep[N];
void dfs1(int u,int father){
    dfn[u]=++idx;
    fa[u][0]=father;
    dep[u]=dep[father]+1;
    for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=e1.head[u];i;i=e1.e[i].next){
        int v=e1.e[i].v;
        if(v==father) continue;
        mn[v]=min(mn[u],e1.e[i].w);
        dfs1(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]];
    if(x==y) return x;
    for(int i=lg[dep[x]];i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void insert(int u){
    if(top==1){
        if(u!=1) st[++top]=u;
        return;
    }
    int x=lca(u,st[top]);
    if(x==st[top]) return;
    for(;top>1&&dfn[st[top-1]]>=dfn[x];top--) e2.add(st[top-1],st[top],0);
    if(st[top]!=x) e2.add(x,st[top],0),st[top]=x;
    st[++top]=u;
}
void dfs2(int u){
    if(!e2.head[u]){
        dp[u]=mn[u];
        return;
    }
    dp[u]=0;
    for(int i=e2.head[u];i;i=e2.e[i].next){
        int v=e2.e[i].v;
        dfs2(v);
        dp[u]+=dp[v];
    }
    dp[u]=min(dp[u],mn[u]);
    e2.head[u]=0;
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e1.add(u,v,w),e1.add(v,u,w);
    }
    mn[1]=inf;
    dfs1(1,0);
    cin>>m;
    while(m--){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++) cin>>a[i];
        sort(a+1,a+1+k,cmp);
        e2.cnt=0;
        st[top=1]=1;
        for(int i=1;i<=k;i++) insert(a[i]);
        for(;top>1;top--) e2.add(st[top-1],st[top],0);
        dfs2(1);
        cout<<dp[1]<<"\n";
    }
}
signed main(){
    for(int i=2;i<=N;i++) lg[i]=lg[i>>1]+1;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}   