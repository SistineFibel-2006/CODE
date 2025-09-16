#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    int arr[n+10]={0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i-1]==arr[i]){
            cnt++;
        }
        else{
            if(cnt>=4){
                cout << "YES" << endl;
                return;
            }
            if(arr[i]-1==arr[i-1]){
                cnt=(cnt/2)*2+1;
            }
            else{
                cnt=1;
            }
        }
    }
    if(cnt>=4){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

signed main () {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
