#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define eb emplace_back
#define in insert
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
// #define rep(i, n) for(size_t i = 0; i < n; i ++)
#define rep(i, a, b) for(size_t i = a; i < b; i ++)
#define F_(i, a, b) for(size_t i = b; i > a; i --)
#define I(x) int x;cin>>x
using i64 = long long;
#define i64(x) i64 x;cin>>x
const int N=100005;
struct edge{
    int v,next;
}e[N<<1];
int n,m,a[N],head[N],cnt,vis[N],mn=2147483647;
void add(int u,int v){
    e[++cnt]={v,head[u]};
    head[u]=cnt;
}
void solve() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0) add(i,(i+1)%n);
        add(i,(i+a[i])%n);
    }
    // for(int i = 0; i <= n; i ++) {
    //     int v = (i + a[i % n]) % n;
    //     if(v == 0) v = n;
    //     add(i, v);
    //     if(i) {
    //         v = i + 1;
    //         if(v >n) v = 1;
    //         add(i,v);
    //     }
    // }
    queue<pair<int,int>>q;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first,ans=q.front().second;q.pop();
        vis[x]=1;
        if(x==m){
            // for(int i=0;i<n;i++) cout<<vis[i]<<" ";cout<<"\n";
            // if(a[0]==0) ans++;   
            // mn=min(mn,ans);
            cout<<ans;
            return;
            continue;
        }
        for(int i=head[x];i;i=e[i].next){
            int v=e[i].v;
            if(vis[v]) continue;
            q.push({v,ans+1});
        }
    }
    cout<<mn<<"\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t --) 
        solve();
}