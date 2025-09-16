#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    // int t; cin >> t; while(t --) solve();
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i ++){
        if((a[i] - b[i] + 26) % 26 != cnt)
            ans ++;
        cnt = (a[i] - b[i] + 26) % 26;
    }
    cout << ans << endl;
    return 0;
}

void solve() {

}