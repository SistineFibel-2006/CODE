#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve ();

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int tt;
    cin >> tt;
    while(tt --)
        solve();

}

void solve() {
    int n;
    cin >> n;
    n *= 2;
    int a[n + 1],c[n+1];
    map<int,int> mp;
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i = 1; i <= n;i ++){
        cin >> a[i];
        c[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(c[i] != 0)
            cnt += c[i] - 1;
    }

    // cerr << cnt << endl;
    if(cnt >= n / 2)
        cout << "Qingyu\n";
    else cout << "Kevin\n";
}