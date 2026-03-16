#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i = (a); i < b; i ++)
#define fi first
#define se second
#define double long double
// #define pi 3.1415926
/*
we can translate circle => square, means that we
can do that with simple DFS.

N = 6, \sum_ ans = 6!
*/
void solve() {
    int n; cin >> n;
    int X,Y,X1,Y1; cin >> X >> Y >> X1 >> Y1;
    int x1 = minmax(X, X1).fi;
    int x  = minmax(X, X1).se;
    int y1 = minmax(Y, Y1).fi;
    int y  = minmax(Y, Y1).se;
    x -= x1, y -= y1; // 0 - based
    vector<pair<int, int>> p(n), vis; // vis: idx, r
    vector<int> permu(n);
    iota(permu.begin(), permu.end(), 0);
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        a -= x1, b -= y1;
        p[i].fi = a, p[i].se = b;
    }

    auto cS = [](double R) -> double { // cal S
        return acos(-1) * R * R;
    };

    auto dis = [p](int i1, int i2) -> double { //distance between 2 po
        return sqrt(pow(p[i1].fi - p[i2].fi, 2)+pow(p[i1].se - p[i2].se, 2));
    };

    auto getR = [&](int id) -> double {
        int a = p[id].fi, b = p[id].se;
        double r = min({x-a,a,y-b,b});
        for (auto [i, R] : vis) {
            r = max((double)0, min(r, dis(id, i) - R));
        }
        vis.push_back({id, r});
        return r;
    };
    double ans = x * y;
    const double SS = x * y;
    cerr << "SS : " << SS << endl;
    do {
        vis.clear();
        double s = SS;
        cerr << "c : "; for(auto c : permu) cerr << c << " "; cerr << '\n';
        for(auto c : permu) {
            double r = getR(c);
            s -= cS(r);
            cerr << "r, cS :" << r << " " << cS(r) << endl;
        }
        cerr << "S : " << s << endl;
        ans = min(ans, s);
        cerr << "ans : " << ans << endl;
    } while(next_permutation(permu.begin(),permu.end()));
    // ans += 1e-9;
    // if (ans - floor(ans) >= 0.5) ans = ceil(ans);
    // else ans = floor(ans);
    cout << (int)(ans+0.5) << endl;
}
//819426
signed main() {
    solve();
}
