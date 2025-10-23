#include<bits/stdc++.h>
#define N 60006
#define ll long long
using namespace std;
const ll inf=2147483647;
struct edge
{
    int v,next,w;
}e[N<<1];
int head[N],cnt,tot[N],dis[N],n,m;
bool vis[N];
queue<int>q;
void add(int u,int v,int w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
bool spfa()
{
    vis[1]=1;
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                tot[v]=tot[u]+1;
                if(tot[v]>=n) return 1;
                if(vis[v]==0) vis[v]=1,q.push(v);
            }
        }
    }
    return 0;
}
void solve()
{
    memset(tot,0,sizeof(tot));
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(e,0,sizeof(e));
    memset(dis,0x3f,sizeof(dis));
    cnt=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        if(z>=0) add(y,x,z);
    }
    if(spfa()==1) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}