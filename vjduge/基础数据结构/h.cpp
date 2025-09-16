#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

struct node {
    i64 w, h;
    node(i64 w = 0, i64 h = 0) : w(w), h(h) {}
    bool operator<(const node& a) const { 
	    if (a.w == w)
	        return h > a.h;
	    else
	        return w > a.w;
    }
};

priority_queue<node> qu;


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
	    solve();
}

void solve(){
	i64 n, k, ans = 0;
    cin >> n >> k;
    i64 h, w;
    for (int i = 0; i < n; i++) {
        i64 w;
        cin >> w;
        qu.push(node(w, 1));
    }

    while ((qu.size() - 1) % (k - 1) != 0) 
    	qu.push(node(0, 1));

    while (qu.size() >= k) {
        h = -1;
        w = 0;
        for (int i = 1; i <= k; ++i) {
            auto t = qu.top();
            qu.pop();
            h = max(h, t.h);
            w += t.w;
        }
        ans += w;
        qu.push(node(w, h + 1));
    }
    cout << ans << '\n' << qu.top().h - 1 << '\n';
}