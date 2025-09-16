#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<i64> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<i64> l(a.begin(), a.begin() + (n / 2));
    vector<i64> r(a.begin() + (n / 2), a.end());

    // 预处理可能的票价类型
    vector<i64> ls, rs;
    auto yuchuli = [&](vector<i64>& x, vector<i64>& xs, int a) -> void {
        for (int i = 0; i < (1 << a); i++) {
            i64 sum = 0;
            for (int j = 0; j < a; j++) {
                if (i & (1 << j)) {
                    sum += x[j];
                }
            }
            if (sum <= m) {
                xs.push_back(sum);
            }
        }
    };

    yuchuli(l, ls, n / 2);
    yuchuli(r, rs, n - n / 2);

    sort(rs.begin(), rs.end());

    i64 ans = 0;
    for (i64 c : ls)
        ans += upper_bound(rs.begin(), rs.end(), m - c) - rs.begin();

    cout << ans << endl;

    return 0;
}
