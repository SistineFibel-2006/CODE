#include<bits/stdc++.h>
#define N 60006
#define ll long long
using namespace std;
const ll inf=1e9;
struct edge
{
    int v,next,w;
}e[N<<1];
struct node
{
    ll pos,d;
    bool operator<(const node&x)const{return x.d<d;}
};
int head[N],cnt,n,m,tot[N];
ll h[N],dis[N];
bool vis[N];
void add(int u,int v,int w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
bool spfa()
{
    queue<int>q;
    memset(h,0x7f,sizeof(h));
    q.push(0);
    h[0]=0;
    vis[0]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(h[v]>h[u]+w){
                h[v]=h[u]+w;
                tot[v]=tot[u]+1;
                if(tot[v]>n) return 1;
                if(vis[v]==0) q.push(v),vis[v]=1;
            }
        }
    }
    return 0;
}
void dijkstra(int s)
{
    priority_queue<node> q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().pos;q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(vis[v]==0) q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    for(int i=1;i<=n;i++) add(0,i,0);
    if(spfa()==1){
        cout<<-1;
        return 0;
    }
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=e[i].next)
            e[i].w+=h[u]-h[e[i].v];
    for(int i=1;i<=n;i++){
        dijkstra(i);
        ll ans=0;
        for(int j=1;j<=n;j++){
            if(dis[j]==inf) ans+=j*inf;
            else ans+=j*(dis[j]+h[j]-h[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}