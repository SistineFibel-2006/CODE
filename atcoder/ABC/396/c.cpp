#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y

signed main() {
    // int n, m;
    // cin >> n >> m;
    // vector<int> a(n + 1), b(m + 1);
    // int az = 0, bz = 0;
    // for(int i = 1; i <= n; i ++){
    //     cin >> a[i];
    // }
    // for(int i = 1; i <= m; i ++){
    //     cin >> b[i];
    // }

    // sort(a.begin(),a.end(),[&](int a, int b){return a < b;});
    // sort(b.begin(),b.end(),[&](int a, int b){return a < b;});
    // int aq[n] = {0}, bq[n] = {0};

    // for(int i = 1; i <= n; i ++){
    //     aq[i] = aq[i - 1] + a[i];
    // }
    // for(int i = 1; i <= m; i ++){
    //     bq[i] = bq[i - 1] + b[i];
    // }

    // i64 ans = 0;
    // i64 ttt = 0;
    // int p = 0;
    // for(int i = 1; i <= m; i ++) {
    //     if(i > n)
    //         break;
    //     ttt += aq[i] + bq[i];
    //     if(ttt > ans){
    //         ans = ttt;
    //         p = i;
    //     }
    // }
    // for(int i = p; i <= n; i ++) {
    //     if(a[i] > 0)
    //         ans += a[i];
    //     else
    //         break;
    // }
    // cout << ans;
    // return 0;

    int N, M;
    cin >> N >> M;
    vector<ll> B(N), W(M);
    for (auto &x : B) cin >> x;
    for (auto &x : W) cin >> x;

    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend());

    vector<ll> B_sum(N + 1, 0);
    for (int i = 0; i < N; ++i)
        B_sum[i + 1] = B_sum[i] + B[i];

    vector<ll> W_sum(M + 1, 0);
    for (int i = 0; i < M; ++i)
        W_sum[i + 1] = W_sum[i] + W[i];

    vector<ll> max_b(N + 1);
    max_b[N] = B_sum[N];
    for (int j = N - 1; j >= 0; --j)
        max_b[j] = max(B_sum[j], max_b[j + 1]);

    int j_max = min(M, N);
    ll ans = -1e18;

    for (int j = 0; j <= j_max; ++j) {
        ll current = W_sum[j] + max_b[j];
        ans = max(ans, current);
    }

    cout << ans << endl;

    return 0;
}

void solve() {

}

