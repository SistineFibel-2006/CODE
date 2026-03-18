#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i = (a); i < b; i ++)
using I = int;
using Int = long long;
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using ld = long double;

template<typename T>
void chmax(T &x, const T y) {
    if(y > x) x = y;
}

struct Vec{
    ld x, y;
    inline bool operator<(const Vec &r) const {
        return atan2l(y,x) < atan2l(r.y, r.x);
    }
};

const ld pi = acosl(-1);
int n;
ld wk(Vec &x, Vec &y, I l, I r) {
    ld ans = atan2(y.y, y.x) - atan2(x.y, x.x);
    if(l < n && r >= n) ans += pi * 2;
    return ans;
}

void solve() {
    cin >> n;
    vector<Vec> p;
    rep(i, 0, n) {
        ld x, y;
        cin >> x >> y;
        if(x || y) p.push_back({x, y});
    }

    sort(all(p));

    n = p.size();
    rep(i, 0, n) p.push_back(p[i]);
    ld x = 0, y = 0;
    ld ans = 0;
    int r = 0;
    int total = p.size();

    for (int l = 0; l < n; l ++) {
        while (r < total && wk(p[l], p[r], l, r) < pi + 1e-10) {
            x += p[r].x;
            y += p[r].y;
            chmax(ans, x * x + y * y);
            r ++;
        }
        x -= p[l].x;
        y -= p[l].y;
        chmax(ans, x * x + y * y);

        if (r < l + 1) {
            r = l + 1;
            x = 0, y = 0;
        }
    }

    cout << fixed << setprecision(3) << ans << endl;
}

int main() {
    solve();
}
