#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(long long i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back


void solve() {
    int n, k; cin >> n >> k; k = min(n, k);
    string s; cin >> s; s += s; s = ' ' + s;
    vector<int> cnt(2 * n);
    for(int i = 0; i + 6 < n * 2; i ++) {
        if(s.substr(i, 7) == "nanjing")
            cnt[i] ++;
        cnt[i + 1] += cnt[i];
    }
    int ans = 0;
    F(i, 0, k + 1) {
        ans = max(ans, cnt[max(0LL, n + i - 6)] - cnt[i]);
    }
    cout << ans << endl;

}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}