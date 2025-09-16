#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    string s;
    cin >> s;
    int arr[11]={0};
    for(int i=0;i<10;i++){
        arr[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(arr[9-i]>0){
            arr[9-i]--;
            cout << 9-i;
          
        }
        else{
            for(int j=9-i;j<10;j++){
                if(arr[j]>0){
                    arr[j]--;
                    cout << j;
                    break;
                }
            }
        }
    }
    cout << endl;
}

signed main () {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
