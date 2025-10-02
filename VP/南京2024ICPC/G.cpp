#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(size_t i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back
#define all(x) x.begin(),x.end()
const int N=100005;
struct edge{
    int v,next;
}e[N<<2];
int n,cnt,head[N],st,mx,term,dp[N],pre[N];
vector<int>p;
void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int father,int dep){
    dp[u]=dep;
    if(dep>mx) mx=dep,st=u;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==father) continue;
        dfs(v,u,dep+1);
    }
}
void dfs2(int u,int father,int dep){
    pre[u]=father;
    if(dep>mx) mx=dep,term=u;
    for(int i=head[u];i;i=e[i].next){
        int v=e[i].v;
        if(v==father) continue;
        dfs2(v,u,dep+1);
    }
}
void solve() {
    cin>>n;
    p.clear();
    for(int i=1;i<=n;i++) head[i]=cnt=mx=dp[i]=st=term=pre[i]=0;
    int x[n+1],y[n+1];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        if(x[i]!=0) add(i,x[i]),add(x[i],i);
        if(y[i]!=0) add(i,y[i]),add(y[i],i);
    }
    term=1;
    dfs(1,0,1);
    dfs2(st,0,1);
    int u=term;
    while(u!=0){
        p.push_back(u);
        u=pre[u];
    }
    int h = p[n / 2];
    //cerr << h << ' ' << x[h] << ' ' << y[h] << endl;
    if(n==2){
        int rst;
        cout << '?' << ' ' <<  1 << ' ' << 2 << endl;
        cin >> rst ;
        if(rst==0){
            cout << '!' << ' ' << 1 << endl;
        }
        else{
            cout << '!' << ' ' << 2 << endl;
        }
        return;
    }
    while(!(x[h]==0&&y[h]==0)){
        //cout << "pass" << endl;
        int rst;
        if(!(x[h]!=0&&y[h]!=0)){
            if(x[h]!=0){;
                cout << '?' << ' ' << x[h] << ' ' << h << endl;
				cin >> rst;
                if(rst==0){
                    h=x[h];
                }
                else{
                    cout << '!' << ' ' << h << endl;
                    return;
                }
            }
            else{
                cout << '?' << ' ' << y[h] << ' ' << h << endl;
				cin >> rst;
                if(rst==0){
                    h=y[h];
                }
                else{
                    cout << '!' << ' ' << h << endl;
                    return;
                }
            }
            
            continue;


        }
        cout << '?' << ' ' << x[h] << ' ' << y[h] << endl;
        cin >> rst;
        if(rst==0){
            h=x[h];
        }
        else if(rst==2){
            h=y[h];
        }
        else{
            cout << '!' << ' ' << h << endl;
            return;
        }
    }
    cout << '!' << ' ' << h << endl;
    return;
}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}
