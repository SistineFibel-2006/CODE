#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 0x3f3f3f3f;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
    int ans=1;
    for(int l=n;l>=1;l--){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
                if((find(a.begin()+i,a.begin()+j,(a[i]+a[j])/2))!=a.end()){
                    int sit=(find(a.begin()+i,a.begin()+j,(a[i]+a[j])/2)-a.begin());
                    //cout<<sit<<" "<<i<<' '<<j<<' ';
                    ans=max(ans,min(sit-i+1,j-sit+1));
                   // return;
                }
        }
    }
    cout<<ans<<"\n";
}
signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
