// #include <bits/stdc++.h>
// using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;
// void solve();
// //超级板子
// #define endl '\n'

// // const i64 N = 2e40 + 10;


// void dfs(vector<i64>& x, int l, int r, i64 sum, vector<i64>& xs, i64 m) {
//     if (sum > m) return;
//     if (l > r) {
//         xs.push_back(sum);
//         return;
//     }
//     dfs(x, l + 1, r, sum + x[l], xs, m);
//     dfs(x, l + 1, r, sum, xs, m);
// }


// signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

//     int n, m;
//     cin >> n >> m;
//     vector<i64> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     vector<i64> l(a.begin(), a.begin() + (n / 2));
//     vector<i64> r(a.begin() + (n / 2), a.end());

//     // 预处理可能的票价类型
//     vector<i64> ls, rs;
//     // auto yuchuli = [&](vector<i64>& x, vector<i64>& xs, int a) -> void {
//     //     for (int i = 0; i < (1 << a); i++) {
//     //         i64 sum = 0;
//     //         for (int j = 0; j < a; j++) {
//     //             if (i & (1 << j)) {
//     //                 sum += x[j];
//     //             }
//     //         }
//     //         if (sum <= m) {
//     //             xs.push_back(sum);
//     //         }
//     //     }
//     // };

//     // yuchuli(l, ls, n / 2);
//     // yuchuli(r, rs, n - n / 2);

//     // sort(rs.begin(), rs.end());

//     // auto dfs = [&](vector<i64>& x, int l, int r, i64 sum, vector<i64>& xs, auto& dfs_) -> void {
//     //     if (sum > m) 
//     //     	return;
//     //     if (l > r) {
//     //         xs.push_back(sum);
//     //         return;
//     //     }
//     //     dfs_(x, l + 1, r, sum + x[l], xs, dfs_);
//     //     dfs_(x, l + 1, r, sum, xs, dfs_);
//     // };

//     dfs(l, 0, (n / 2) - 1, 0, ls, m);
//     dfs(r, 0, n - (n / 2) - 1, 0, rs, m);

//     sort(rs.begin(), rs.end());


//     i64 ans = 0;
//     for (int i = 0; i < ls.size; i ++)
//         ans += upper_bound(rs.begin(), rs.end(), m - ls[i]) - rs.begin();

//     cout << ans << endl;

//     return 0;

// }

// void solve(){

// }	
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

int N, mid;
i64 M, ans;
vector<i64> d(55), ls, rs;

void DFS(vector<i64>& x, int l, int r, i64 sum, vector<i64>& xs) {
    if (sum > M) return;
    if (l > r) {
        xs.push_back(sum);
        return;
    }
    DFS(x, l + 1, r, sum + x[l], xs);
    DFS(x, l + 1, r, sum, xs);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    mid = N / 2;

    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
    vector<i64> l(d.begin() + 1, d.begin() + mid + 1);
    DFS(l, 0, mid - 1, 0, ls);

    vector<i64> r(d.begin() + mid + 1, d.end());
    DFS(r, 0, N - mid - 1, 0, rs);

    sort(ls.begin(), ls.end());

    for (i64 sum : rs) {
        ans += upper_bound(ls.begin(), ls.end(), M - sum) - ls.begin();
    }

    cout << ans << endl;

    return 0;
}