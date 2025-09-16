#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
struct node
{
    vector<int> p;
    int level,sum,t,num;
    bool operator<(const node x)const{return x.level>level||x.level==level&&x.sum<sum;}
};
bool cmp(node a,node b){return a.num<b.num;}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    node a[n+1];
    for(int i=1;i<=n;i++){
        a[i].sum=a[i].t=0;
        a[i].num=i;
        cin>>a[i].level;
        for(int j=1,temp;j<=m;j++){
            cin>>temp;
            if(temp==-1) a[i].t++;
            else a[i].sum+=temp;
            a[i].p.push_back(temp);
        }
    }
    sort(a+1,a+1+n);
    int pre=a[1].sum;
    for(int i=2;i<=n;i++){
        if(a[i].sum+k*a[i].t<=pre){
            cout<<"No\n";
            return;
        }
        for(int j=0;j<m;j++){
            if(a[i].p[j]==-1){
                if(a[i].sum>pre&&a[i].level>a[i-1].level||a[i].level==a[i-1].level&&a[i].sum>=a[i-1].sum) break;
                if(k>pre-a[i].sum&&a[i+1].level!=a[i].level||a[i+1].level==a[i].level&&k>=pre-a[i].sum){
                    a[i].p[j]=pre-a[i].sum+(a[i+1].level!=a[i].level);
                    a[i].sum+=a[i].p[j];
                    pre=max(pre,a[i].sum);
                }
                else{
                    a[i].p[j]=k;
                    a[i].sum+=k;
                    pre=max(pre,a[i].sum);
                }
            }
        }
    }
        cout<<"Yes\n";
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(a[i].p[j]==-1) a[i].p[j]=0;
                cout<<a[i].p[j]<<" ";
            }cout<<"\n";
        }
}
signed main ()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}