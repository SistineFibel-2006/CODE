#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y


signed main() {
    int n;
    cin >> n;
    vector<i64 > a(n + 1, 0);
    i64 dp[n + 1][2] = {0};

    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    dp[0][0] = - LLONG_MAX;
    for(int i = 1; i <= n; i ++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = dp[i - 1][0] - a[i - 1];
    }

    cout << max(dp[n][0], dp[n][1]);

}

void solve() {

}
