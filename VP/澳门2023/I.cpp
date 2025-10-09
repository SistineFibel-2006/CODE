#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define eb emplace_back
#define in insert
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
// #define rep(i, n) for(size_t i = 0; i < n; i ++)
#define rep(i, a, b) for(size_t i = a; i < b; i ++)
#define F_(i, a, b) for(size_t i = b; i > a; i --)
#define I(x) int x;cin>>x
using i64 = long long;
#define i64(x) i64 x;cin>>x

// const int N = 1e6 + 10;
// int f[N];

void solve() {
    I(a); I(b); I(m);
    // fill(f,f + m + 1, 0);
    int t1 = b, v1 = b / a + 1;
    int t2 = (b + a - 1) / a * a, v2 = (b + a - 1) / a + 1;
    int ans = 2;
    for(int c1 = 0; c1 <= m / t1; c1 ++) {
        int c2 = (m - c1 * t1) / t2;
        int c3 = (m - c1 * t1 - c2 * t2) / a;
        ans = max(ans, c1 * v1 + c2 * v2 + c3 + 2);
    }
    cout << ans * 160 << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t --) 
        solve();
}