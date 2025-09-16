#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
void solve () {
    int n,m;
    cin >> n >> m;
    int a[n];
    int b[n];
    int last=0;
    for(int i=0;i<n;i++){
       
        cin >> a[i];
        
    }
    for(int i=0;i<n;i++){
       
        cin >> b[i];
        
    }
    sort(b,b+n);
    for(int i=1;i<n;i++){
        b[i]=b[i]+b[i-1];
    }
    pair<int,int>arr[n];
    for(int i=0;i<n-1;i++){
        arr[i].first=a[i];
        arr[i].second=a[i+1]-a[i];
    }
    arr[n-1].second=m-a[n-1]+1;
    arr[n-1].first=a[n-1];
    bool mark[n]={0};
    sort(arr,arr+n,cmp);
    int ans=0;
    bool stat=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
        
            if(b[n-1-j]<=arr[i].first&&!mark[n-1-j]){
                mark[n-1-j]==1;
                ans+=arr[i].second;
        
            }

        
        }





    }






    cout << ans << endl;

}
signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
}