#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,c;
};
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    node sit[n*m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sit[a[i][j]].x=i;
            sit[a[i][j]].y=j;
            sit[a[i][j]].c=0;
        }
    }
    for(int i=0;i<n*m;i++){
        if(sit[i].c!=i){
            cout<<i<<"\n";
            return;
        }
        for(int j=1;j<=sit[a[i][j]].x;j++){
            for(int k=1;k<=sit[a[i][j]].y;k++){
                sit[a[i][j]].c++;
            }
        }
        for(int j=sit[a[i][j]].x;j<=n;j++){
            for(int k=sit[a[i][j]].y;k<=m;k++){
                sit[a[i][j]].c++;
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cout<<sit[a[]]
            }
        }
    }
}
signed main () {
    int t;
    cin>>t;
    while(t--) solve();
}