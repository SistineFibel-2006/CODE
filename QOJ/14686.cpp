#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i, a, b) for(ll i = a; i < (b); i ++)
#define pb push_back

struct P{
    ll time;
    int t;
    bool operator>(const P&o) const {
        return t > o.t;
    }
};


signed main() {
    int n; cin >> n;
    vector<int > t(n + 1, 0), a(n + 1), ans(n + 1, -1), stop(n, -1);
    vector<vector<int >> e(n + 1);
    rep(i, 0, n) cin >> t[i], t[i] --, e[t[i]].pb(i);
    rep(i, 0, n) cin >> a[i], a[i] *= 2;

    priority_queue<P, vector<P>, greater<P>> pq;

    auto cal = [&](int i) -> ll {
        int j = t[i];
        if(ans[i] != -1) return -1;
        if(ans[j] != -1) {
            return abs(a[i] - a[j]);
        } else {
            if(a[i] < a[j]) {
                if(t[j] != -1 && a[j] > a[t[j]]) return a[j] - a[i];
            } else if(a[i] > a[j]) {
                if(t[j] != -1 && a[j] < a[t[j]]) return a[i] - a[j];
            }
        }
        return -1;
    };

    rep(i, 0, n) {
        ll time = cal(i);
        if(time != -1) pq.push({abs(a[i] - a[t[i]]), i});
    }

    while(!empty(pq)) {
        cerr << "YES" << endl;
        auto &&[time, i] = pq.top(); pq.pop();
        if(ans[i] != -1) continue;
        int j = t[i];
        if(ans[j] != -1) {
            ll ti = cal(i);
            if(cal(i) != -1) {
                pq.push({ti, i});
            }
            continue;
        }

        if(ans[j] != -1 && ans[j] < time) {
            ll ti = cal(i);
            if(ti != -1) {
                pq.push({ti, i});
            }
            continue;
        }

        ans[i] = time; a[i] = a[j];

        for(auto k : e[i]) {
            if(ans[k] != -1) continue;
            ll tk = cal(k);
            if(tk != -1) pq.push({tk, k});
        }
    }
    rep(i, 1, n + 1) cout << ans[i] << ' ';
}
