#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int inf=1e18;
const int N=200005;
struct node{
    int v,next;
}e[N<<1];
int n,head[N],sz[N],tot,c[N],m,cnt[N],hson[N],ans[N],ccnt;
void add(int u,int v){
    e[++tot]={v,head[u]};
    head[u]=tot;
}
void dfs1(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[hson[u]]) hson[u]=v;
    }
}
void upd(int u,int fa,int x){
    cnt[c[u]]+=x;
    if(x==1&&cnt[c[u]]==1) ccnt++;
    if(x==-1&&cnt[c[u]]==0) ccnt--;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa) continue;
        upd(v,u,x);
    }
}
void dfs2(int u,int fa,int pd){
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa||v==hson[u]) continue;
        dfs2(v,u,0);
    }
    if(hson[u]) dfs2(hson[u],u,1);
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==fa||v==hson[u]) continue;
        upd(v,u,1);
    }
    cnt[c[u]]+=1;
    if(cnt[c[u]]==1) ccnt++;
    ans[u]=ccnt;
    if(pd==0) upd(u,fa,-1);
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs1(1,0);
    dfs2(1,0,0);
    cin>>m;
    while(m--){
        int u;
        cin>>u;
        cout<<ans[u]<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}   