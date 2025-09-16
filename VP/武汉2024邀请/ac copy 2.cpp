#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin >> n;
    bool f = 0;
    if(n % 4 < 2)
        f = 1;
    if(f)
        cout << "Fluttershy\n";
    else
        cout << "Pinkie Pie\n";
}

signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}