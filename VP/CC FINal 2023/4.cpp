#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int a[n+1],ans1=0,ans2=0,max1=0,max2=0,l=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        l++;
        if(a[i]>max1){
            ans1+=l*
            max1=a[i];
            l=0;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();

}