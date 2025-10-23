#include<bits/stdc++.h>
#define inf 2147483647
#define ll long long
#define N 100005
using namespace std;
const int mod=998244353;
struct edge{
    int v,next;
}e[N<<1],newe[N<<1];
int n,m,head[N],newhead[N],cnt,newcnt,num,scc[N],dfn[N],low[N],tot,val[N],s[N],len,dp[N],a[N];
bool in[N];
void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void newadd(int u,int v){
    newe[++newcnt].v=v;
    newe[newcnt].next=newhead[u];
    newhead[u]=newcnt;
}
void dfs(int x){
    dfn[x]=low[x]=++tot;
    s[++len]=x;
    in[x]=1;
    for(int i=head[x];i;i=e[i].next){
        int y=e[i].v;
        if(dfn[y]==0){
            dfs(y);
            low[x]=min(low[x],low[y]);
        }
        else if(in[y]==1) low[x]=min(low[x],low[y]);
    }
    if(dfn[x]==low[x]){
        num++;
        while(s[len]!=x){
            in[s[len]]=0;
            scc[s[len]]=num;
            val[num]+=a[s[len]];
            len--;
        }
        scc[x]=num;
        val[num]+=a[x];
        in[x]=0;
        len--;
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;i++) if(dfn[i]==0) dfs(i);
    set<pair<int,int>>st;   
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=e[j].next){
            if(scc[i]!=scc[e[j].v]){
                if(st.count({scc[i],scc[e[j].v]})==1) continue;
                st.insert({scc[i],scc[e[j].v]});
                newadd(scc[i],scc[e[j].v]);
            }
        }
    }
    for(int i=1;i<=num;i++) dp[i]=val[i];
    for(int i=num;i>=1;i--){
        for(int j=newhead[i];j;j=newe[j].next){
            dp[newe[j].v]=max(dp[newe[j].v],dp[i]+val[newe[j].v]);
        }
    }
    int ans=0;
    for(int i=1;i<=num;i++) ans=max(ans,dp[i]);
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}