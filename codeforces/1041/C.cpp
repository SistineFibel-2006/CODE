#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> x(n), y(n), d(n);
    for (int i = 0; i < n; i ++) 
        cin >> x[i];
    
    for (int i = 0; i < n; i ++) {
        cin >> y[i];
        d[i] = llabs(x[i] - y[i]);
    }

    int base = accumulate(d.begin(), d.end(), 0LL);

    vector<pair<int,int>> P(n);
    for (int i = 0; i < n; i++) {
        P[i] = { x[i], y[i] };
    }
    sort(P.begin(), P.end(), [](auto &A, auto &B) {
        return A.first < B.first 
            || (A.first == B.first && A.second < B.second);
    });

    int ups = LLONG_MAX;
    for (int i = 0; i < n - 1; i ++) {
        auto [xi, yi] = P[i];
        auto [xj, yj] = P[i+1];
        int di = llabs(xi - yi);
        int dj = llabs(xj - yj);
        int tt = max(llabs(yj - xi) + xj - yi - di - dj, 0LL);
        ups = min(ups, tt);
    }
    if (ups == LLONG_MAX) ups = 0;

    cout << (base + ups) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ ;
    cin >> _ ;
    while (_ --) solve();
    return 0;
}
