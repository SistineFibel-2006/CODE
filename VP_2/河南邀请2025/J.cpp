#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    if((n - 1 - 2) % 2 == 0){
        for(int i = 0; i < (n - 1 - 2) / 2 + 2; i++){
            cout << 1 << " " << i + 2 << endl;
        }
        for(int i = (n - 1 - 2)/2+2; i <(n - 1 - 2) / 2 + (n - 1 - 2)/ 2 + 2; i++){
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    else cout << -1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
