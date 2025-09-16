#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
    string s;
    cin >> s;
    vector<int> a(26);
    i64 ans = 0;
    for (int i = 0; i < 26; ++i)
        a[s[i] - 'A'] = i;
    for (int i = 0; i < 25; ++i)
        ans += abs(a[i] - a[i + 1]);
    cout << ans << endl;
}

void solve(){

}