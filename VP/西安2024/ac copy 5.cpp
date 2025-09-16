#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;




signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int n;
    cin >> n;
    int arr[n+10]={0};
    int cost[n+10]={0};
    int k=0,ctotal=0,cost_now=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> cost[i];
        ctotal+=cost[i];
    }
    cost_now+=cost[0];
    int ans=INF;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==k&&k>=0){
            cost_now+=cost[i];
        }
        else{
            ans=min(ans,ctotal-cost_now);
            k=arr[i]-arr[i-1];
            cost_now=cost[i]+cost[i-1];
        }
    }
    ans=min(ans,ctotal-cost_now);
    cout << ans << endl;


    return 0;
}