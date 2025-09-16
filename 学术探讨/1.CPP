#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    if (N < 2) { // 没有正的 x,y 使 x+y=N 且 x,y>=1
        cout << 0 << '\n';
        return 0;
    }

    int M = N - 1;               // 我们需要 tau[1..N-1]
    vector<int> tau(M + 1, 0);

    // 约数筛：对于每个 i，把 i 加到其倍数上
    for (int i = 1; i <= M; ++i)
        for (int j = i; j <= M; j += i)
            ++tau[j];

    ll ans = 0;
    for (int x = 1; x <= M; ++x) {
        ans += 1LL * tau[x] * tau[N - x];
    }

    cout << ans << '\n';
    return 0;
}
