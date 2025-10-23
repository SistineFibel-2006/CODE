#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void f(ll l,ll r,ll p,ll k){ans[p]+=(r-l+1)*k;tag[p]+=k;}
void push_up(ll p){ans[p]=ans[ls(p)]+ans[rs(p)];}
void push_down(ll l,ll r,ll p)
{
    ll mid=(l+r)>>1;
    f(l,mid,ls(p),tag[p]);
    f(mid+1,r,rs(p),tag[p]);
    tag[p]=0;
}
void build(ll l,ll r,ll p)
{
    if(l==r){ans[p]=a[l];return;}
    ll mid=(l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    push_up(p);
}
void update(ll l,ll r,ll p,ll L,ll R,ll k)
{
    if(L<=l&&r<=R){f(l,r,p,k);return;}
    push_down(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) update(l,mid,ls(p),L,R,k);
    if(R>mid) update(mid+1,r,rs(p),L,R,k);
    push_up(p);
}
ll query(ll l,ll r,ll p,ll L,ll R)
{
    ll res=0;
    if(L<=l&&r<=R) return ans[p];
    ll mid=(l+r)>>1;
    push_down(l,r,p);
    if(L<=mid) res+=query(l,mid,ls(p),L,R);
    if(R>mid) res+=query(mid+1,r,rs(p),L,R);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while(m--){
        int pd,x,y,k;
        cin>>pd;
        if(pd==1){
            cin>>x>>y>>k;
            update(1,n,1,x,y,k);
        }
        if(pd==2){
            cin>>x>>y;
            cout<<query(1,n,1,x,y)<<endl;
        }
    }
    return 0;
}