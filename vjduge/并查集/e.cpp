#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
// void solve();
//超级板子
#define endl '\n'
int p[50010];
int r[50010];

i64 ans = 0;

int find(int x) {
    if (p[x] != x) {
        int o = p[x];
        p[x] = find(p[x]);
        r[x] = (r[x] + r[o]) % 3;
    }
    return p[x];
}


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
    int N, t;
    cin >> N >> t;
    for (int i = 1; i <= N; ++i) {
        p[i] = i;
        r[i] = 0;
    }

    while (t--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (x > N || y > N) {
            ans++;
            continue;
        }
        if (w == 2 && x == y) {
            ans++;
            continue;
        }

        int rx = find(x);
        int ry = find(y);

        if (rx != ry) {
            p[ry] = rx; 
            int dx = r[x];
            int dy = r[y];
            int v;
            if (w == 1)
                v = (dx - dy + 3) % 3;
            else 
                v = (dx - dy - 2 + 3) % 3;
            r[ry] = v;
        } 
        else {
            int dx = r[x];
            int dy = r[y];
            if (w == 1) {
                if ((dx - dy + 3) % 3 != 0) {
                    ans++;
                }
            } 
            else {
                if ((dx - dy + 3) % 3 != 2) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}


