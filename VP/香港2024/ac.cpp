#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int maxx = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    for(int i = 1; i <= n; i ++)
        if(maxx == a[i])
            cout << i << " ";
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
