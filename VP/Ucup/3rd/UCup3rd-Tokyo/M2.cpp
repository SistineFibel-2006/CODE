#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int fa[N],vis[N],dis[N],lg[N],dep[N],f[N][32];
struct node{
    int num,u,v,w;
    bool operator<(const node &x)const{return x.w>w;}
};
int find (int x) {
    if(x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

int tot,head[N];
struct edge{
    int v,next,w;
}e[N<<1];
void add(int u,int v,int w){
    e[++tot].v=v;
    e[tot].w=w;
    e[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u,int father){
    dep[u]=dep[father]+1;
    f[u][0]=father;
    for(int i=1;i<=lg[dep[u]];i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==father) continue;
        dis[v]=dis[u]+e[i].w;
        // cout<<u<<" "<<v<<"\n";
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg[dep[x]];i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=lg[dep[x]];i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}

void solve() {
    int n, m; cin >> n >> m;
    // vector<int> e[n + 1];
    node a[m+1];
    int cnt=0;
    for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w,a[i].num=i;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        int fu=find(a[i].u),fv=find(a[i].v);
        if(fu==fv) continue;
        fa[fu]=fv;
        cnt++;
        vis[i]=1;
    }
    for(int i=1;i<=m;i++){
        // if(vis[i]) cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
        if(vis[i]) add(a[i].u,a[i].v,a[i].w),add(a[i].v,a[i].u,a[i].w);
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<"\n";
    for(int i=1;i<=m;i++){
        if(vis[i]==0){
            int z=lca(a[i].u,a[i].v);
            int di = dis[a[i].u] + dis[a[i].v] - 2 * dis[z];
            if(di > a[i].w) {cout << "No\n"; return;}
            // if(z!=a[i].u&&z!=a[i].v){
            //     if(dis[a[i].u]+dis[a[i].v]>a[i].w){
            //         cout<<"No\n";
            //         return;
            //     }
            // }
            // else{
            //     if(abs(dis[a[i].u]-dis[a[i].v])>a[i].w){
            //         cout<<"No\n";
            //         return;
            //     }
            // }
        }
    }
    cout<<"Yes\n";
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) 
      solve();
}