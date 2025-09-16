#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<long long>;
using vpi = vector<pii>;

const int MOD = 1e9 + 7;

namespace stds {
    int qpow(int a, int b) {
        int r = 1;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    int inv(int a) {
        return qpow(a, MOD - 2);
    }
}

namespace Fenwick {
    struct Fenwick {
        vi bit;
        int n;
        Fenwick(int _n = 0) {
            n = _n + 2;
            bit.assign(n + 2, 0);
        }
        void add(int i, int v) {
            for (; i < n; i += i & -i)
                bit[i] = (bit[i] + v) % MOD;
        }
        int query(int i) {
            int r = 0;
            for (; i > 0; i -= i & -i)
                r = (r + bit[i]) % MOD;
            return r;
        }
    };
}

using namespace stds;
// using namespace Fenwick;

struct pt {
    int x, y, a, u, v;
};

void solve() {
    int n;
    cin >> n;
    vector<pt> a(n);
    vi vs;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].a;
        a[i].u = a[i].x + a[i].y;
        a[i].v = a[i].x - a[i].y;
        vs.pb(a[i].v);
    }

    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());
    auto get = [&](int x) {
        return lower_bound(all(vs), x) - vs.begin() + 1;
    };

    sort(all(a), [](pt &p1, pt &p2) {
        if (p1.u != p2.u) return p1.u < p2.u;
        return p1.v < p2.v;
    });

    int m = vs.size();
    Fenwick::Fenwick bit_cnt(m), sa(m), suv(m), sauv(m), sud(m), saud(m);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int u = a[i].u, v = a[i].v, val = a[i].a;
        int id = get(v);

        int valm = val % MOD;
        int upv = ((u % MOD) + (v % MOD) + 2 * MOD) % MOD;
        int umv = ((u % MOD) - (v % MOD) + 2 * MOD) % MOD;

        int cnt1 = bit_cnt.query(id);
        if (cnt1 > 0) {
            int sa1 = sa.query(id);
            int suv1 = suv.query(id);
            int sauv1 = sauv.query(id);

            int t1 = valm * upv % MOD * cnt1 % MOD;
            int t2 = valm * suv1 % MOD;
            int t3 = upv * sa1 % MOD;
            int t4 = sauv1;
            int c1 = (t1 - t2 + t3 - t4 + 2 * MOD) % MOD;
            ans = (ans + c1) % MOD;
        }

        int cnt2 = i - cnt1;
        if (cnt2 > 0) {
            int sa2 = (sa.query(m) - sa.query(id) + MOD) % MOD;
            int sud2 = (sud.query(m) - sud.query(id) + MOD) % MOD;
            int saud2 = (saud.query(m) - saud.query(id) + MOD) % MOD;

            int t1 = valm * umv % MOD * cnt2 % MOD;
            int t2 = valm * sud2 % MOD;
            int t3 = umv * sa2 % MOD;
            int t4 = saud2;
            int c2 = (t1 - t2 + t3 - t4 + 2 * MOD) % MOD;
            ans = (ans + c2) % MOD;
        }

        bit_cnt.add(id, 1);
        sa.add(id, valm);
        suv.add(id, upv);
        sauv.add(id, valm * upv % MOD);
        sud.add(id, umv);
        saud.add(id, valm * umv % MOD);
    }

    ans = ans * inv(2) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
