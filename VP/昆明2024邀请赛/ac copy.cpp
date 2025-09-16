#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
map<int,int>mp;
int a[1000006];
void solve()
{
    int n;
    cin>>n;
    if(mp.find(n)==mp.end()&&n!=1||n==2){
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    else cout<<"impossible\n";
}
signed main () {
    int pre=0;
    for(int i=1;i<=1000005;i++) a[i]=i-1;
    for(int i=1;i<=1000005;i++){
        if(i==1){
            pre=1;
            swap(a[i],a[i+1]);
            continue;
        }
        if(pre^a[i]==a[i+1]&&pre^a[i+1]==a[i]) mp[i]++,swap(a[i+2],a[i+3]),i++;
        else if(pre^a[i]==a[i+1]) swap(a[i],a[i+1]);
        pre^=a[i];
    }
    for(int i=1;i<=10;i++) cout<<a[i]<<" ";cout<<"\n";
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}