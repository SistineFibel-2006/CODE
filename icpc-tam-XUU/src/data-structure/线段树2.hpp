#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
ll a[MAXN],ans[MAXN<<2],tag_add[MAXN<<2],tag_mul[MAXN<<2],n,q,m;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void f(ll l,ll r,ll p,ll k_mul,ll k_add)
{
    ans[p]=(ans[p]*k_mul+k_add*(r-l+1))%m;
    tag_mul[p]=(tag_mul[p]*k_mul)%m;
    tag_add[p]=(tag_add[p]*k_mul+k_add)%m;
}
void push_up(ll p){ans[p]=(ans[ls(p)]+ans[rs(p)])%m;}
void push_down(ll l,ll r,ll p)
{
    ll mid=(l+r)>>1;
    f(l,mid,ls(p),tag_mul[p],tag_add[p]);
    f(mid+1,r,rs(p),tag_mul[p],tag_add[p]);
    tag_mul[p]=1;
    tag_add[p]=0;
}
void build(ll l,ll r,ll p)
{
    tag_mul[p]=1;
    if(l==r){ans[p]=a[l];return;}
    ll mid=(l+r)>>1;
    build(l,mid,ls(p));
    build(mid+1,r,rs(p));
    push_up(p);
}
void update_mul(ll l,ll r,ll p,ll L,ll R,ll k)
{
    if(L<=l&&r<=R){
        tag_add[p]=(tag_add[p]*k)%m;
        tag_mul[p]=(tag_mul[p]*k)%m;
        ans[p]=(ans[p]*k)%m;
        return;
    }
    push_down(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) update_mul(l,mid,ls(p),L,R,k);
    if(R>mid) update_mul(mid+1,r,rs(p),L,R,k);
    push_up(p);
}
void update_add(ll l,ll r,ll p,ll L,ll R,ll k)
{
    if(L<=l&&r<=R){
        ans[p]=(ans[p]+(r-l+1)*k)%m;
        tag_add[p]=(tag_add[p]+k)%m;
        return;
    }
    push_down(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) update_add(l,mid,ls(p),L,R,k);
    if(R>mid) update_add(mid+1,r,rs(p),L,R,k);
    push_up(p);
}
ll query(ll l,ll r,ll p,ll L,ll R)
{
    ll res=0;
    if(L<=l&&r<=R) return ans[p]%m;
    push_down(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) res+=query(l,mid,ls(p),L,R)%m;
    if(R>mid) res+=query(mid+1,r,rs(p),L,R)%m;
    return res%m;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);
    while(q--){
        int x,y,k,pd;
        cin>>pd;
        if(pd==1){cin>>x>>y>>k;update_mul(1,n,1,x,y,k);}
        if(pd==2){cin>>x>>y>>k;update_add(1,n,1,x,y,k);}
        if(pd==3){cin>>x>>y;cout<<query(1,n,1,x,y)<<"\n";}
    }
    return 0;
}