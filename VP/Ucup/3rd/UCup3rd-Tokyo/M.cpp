#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
const int inf=1e30;
struct edge{
    int v,next,w;
}e[N<<1];
int n,m,cnt,head[N],dis[N],vis[N],pd[N];
void add(int u,int v,int w){
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) dis[i]=inf;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    priority_queue<pair<int,int>>q;
    dis[1]=0;
    q.push({dis[1],1});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                q.push({dis[v],v});
            }
        }
    }
    queue<int>p;
    p.push(1);
    pd[1]=1;
    while(!p.empty()){
        int u=p.front();p.pop();
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]==dis[u]+e[i].w) p.push(v),pd[v]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=pd[i];
    if(cnt==n-1) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) 
      solve();
}