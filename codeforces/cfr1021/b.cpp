#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    int t;
    cin >> t;
    for(;t --;) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        int m = n - k;
        vector<pair<int, int>> arr;
        
        for (int i = 0; i <= n - m; ++i) {
            if (m % 2 == 0) {
                int half = m / 2;
                int l = a[i + half - 1];
                int r = a[i + half];
                arr.emplace_back(l, r);
            } else {
                int mid = i + (m - 1) / 2;
                arr.emplace_back(a[mid], a[mid]);
            }
        }
        
        vector<pair<int, int>> sb;
        for (auto& a : arr) {
            if (sb.empty()) {
                sb.push_back(a);
            } else {
                auto& last = sb.back();
                if (a.first > last.second + 1) {
                    sb.push_back(a);
                } else {
                    int nl = last.first;
                    int n = max(last.second, a.second);
                    sb.pop_back();
                    sb.emplace_back(nl, n);
                }
            }
        }
        
        int ans = 0;
        for (auto& p : sb)
            ans += p.second - p.first + 1;
        
        cout << ans << endl;
    }
    
    return 0;
}