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

vector<int> zuhe(int u, int v, int w) {
    vector<int> nums = {u, v, w};
    sort(nums.begin(), nums.end());
    vector<int> abc;
    do {
        abc.push_back(nums[0]);
        abc.push_back(nums[1]);
        abc.push_back(nums[2]);
    } while (next_permutation(nums.begin(), nums.end()));
    return abc;
}

set<int> solve(int u, int v, int w) {
    vector<int> abc = zuhe(u, v, w);
    set<int> x_set;

    for (int i = 0; i < abc.size(); i += 3) {
        int a = abc[i];
        int b = abc[i + 1];
        int c = abc[i + 2];
        if (a == 0) continue; 
        if(c <= b) continue;
        int x = (c - b) / a;
        if ((c - b) % a == 0 && x >= 0) {
            x_set.insert(x);
        }
    }

    return x_set;
}

int find_x(int n, vector<tuple<int, int, int>>& eqs) {
    set<int> a;

    for (int i = 0; i < n; ++i) {
        int u, v, w;
        tie(u, v, w) = eqs[i];
        set<int> current = solve(u, v, w);

        if (i == 0) {
            a = current;
        } else {
            set<int> intersect;
            set_intersection(a.begin(), a.end(), current.begin(), current.end(), inserter(intersect, intersect.end()));
            a = intersect;
        }

        if (a.empty()) {
            return -1;
        }
    }

    if (a.size() != 1) {
        return -1;
    }

    return *a.begin();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<tuple<int, int, int>> eqs;
        for (int i = 0; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            eqs.push_back(make_tuple(u, v, w));
        }

        int x = find_x(n, eqs);
        cout << x << endl;
    }

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;

// void solve();
// #define endl '\n'

// const int MOD = 1e9 + 7;
// const int MOD2 = 500000004;

// signed main() { 
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--)
//         solve();
// }

// void solve(){
//     int n;
//     cin >> n;
//     int m = (n + 1) / 2;

//     int a = n % MOD;
//     int b = (n + 1) % MOD;
//     int term1 = (a * b) % MOD;
//     term1 = (term1 * MOD2) % MOD;

//     int c = m % MOD;
//     int d = (m + 1) % MOD;
//     int term2 = (c * d) % MOD;
//     term2 = (term2 * MOD2) % MOD;

//     long long total = (term1 - term2 + MOD) % MOD;
//     cout << total << endl;
// }
