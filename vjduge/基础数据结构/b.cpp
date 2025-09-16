
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
    

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        while (!s.empty() && a[i] > a[s.top()]) {
            f[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i ++)
        cout << f[i] << " ";

    return 0;

}

void solve(){

}