#include<bits/stdc++.h>
#define N 2000005
#define ll long long
using namespace std;
const ll inf=2147483647;
int n,m,f[N];
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    while(m--){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1) f[find(y)]=find(x);
        if(z==2){
            if(find(x)==find(y)) cout<<"Y\n";
            else cout<<"N\n";
        }
    }
    return 0;
}