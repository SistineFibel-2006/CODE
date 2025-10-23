#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
const ll inf=2147483647;
ll n,m,f[105][105];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) f[i][j]=inf;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        f[x][y]=min(f[x][y],z);
        f[y][x]=min(f[y][x],z);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k||f[i][k]==inf) continue;
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<f[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}