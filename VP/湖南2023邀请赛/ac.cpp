#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1; 
    // cin >> t; 
    while(t --) solve();


    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s, ss, ans;
    cin >> s;
    int x = s.back();
    while(n / 2 < m){
        n = s.length();
        ss = s.substr(n / 2, n - 1);
        s = s.substr(0, n / 2) + s;
        for(auto &c : ss)
            c = (c - 'a' + 1) % 26 + 'a';
        s = s + ss;
    }
    ans = s.substr(s.size() - m, m);
    int cnt = (x - s.back() + 16) % 26;
    for(auto &c : ans)
        c = (c - 'a' + cnt) % 26 + 'a';
    cout << ans;
}