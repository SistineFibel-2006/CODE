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
    vector<int> a(n), b(n), cnt(n, 0);
    vector<int> f(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i ++)
    	cin >> a[i] >> b[i];

    for (int i = 0; i < n; i ++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            cnt[i] += b[s.top()];
            s.pop();
        }
        if(!s.empty())
        	cnt[s.top()] += b[i];
        s.push(i);
    }
    int ans = -1;
    for (auto c : cnt)
    	ans = max(ans, c);

    cout << ans << endl;


    return 0;



}

void solve(){

}