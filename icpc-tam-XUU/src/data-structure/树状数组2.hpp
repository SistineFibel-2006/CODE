#include<bits/stdc++.h>
#define N 500050
#define ll long long
using namespace std;
const ll inf=2147483647;
int n,m,t[N];
int lowbit(int x){return x&-x;}
void add(int x,int k)
{
    while(x<=n){
        t[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(i,x);
        add(i+1,-x);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a;
        if(a==1){
            int x,y,z;
            cin>>x>>y>>z;
            add(x,z);
            add(y+1,-z);
        }
        if(a==2){
            int x;
            cin>>x;
            cout<<sum(x)<<"\n";
        }
    }
    return 0;
}