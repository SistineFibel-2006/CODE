#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;

using S = pair<int,int>; // {max_val, pos}
using F = int;

// op: 取较大值，若相等取左侧（pos 小）
S op(S a, S b) {
    if (a.first >= b.first) return a;
    return b;
}
// e(): 单位元（返回 S 类型）
S e() {
    return S{-(1<<30), INT_MAX}; // 充分小的值，pos 用大值避免被选中
}
// mapping: 将 lazy add 加到值上
S mapping(F f, S x) {
    x.first += f;
    return x;
}
// composition: 先应用 g，再应用 f -> 返回 f ∘ g
F composition(F f, F g) {
    return f + g;
}
// id(): 懒标记的单位元
F id() {
    return 0;
}

struct Event { int b1, b2_l, b2_r, add; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        map<int, vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            pos[v].push_back(i+1);
        }
        vector<Event> ev;
        for (auto &kv : pos) {
            auto &p = kv.second;
            if (p.size() < 3) continue;
            int last = p.back();
            ev.push_back({p[0]+1, p[1]+1, last, 1});
            for (size_t i = 1; i+1 < p.size(); ++i) {
                int b1pt = p[i]+1;
                ev.push_back({b1pt, p[i]+1, last, -1});
                ev.push_back({b1pt, p[i+1]+1, last, 1});
            }
        }
        sort(ev.begin(), ev.end(), [](const Event &a, const Event &b){
            if (a.b1 != b.b1) return a.b1 < b.b1;
            return a.add > b.add; // 同 b1 先加后减
        });

        // 初始化：下标 0..n-1 对应 b2 = 1..n
        vector<S> init(n);
        for (int i = 0; i < n; ++i) init[i] = {0, i+1};

        // 注意这里模板参数传入的是函数名 e, id（不是变量）
        atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

        int max_common = 0;
        int best_b1 = 2, best_b2 = 3;
        if (ev.empty()) {
            cout << 0 << '\n' << best_b1 << " " << best_b2 << '\n';
            continue;
        }
        int last_b1 = 1;
        for (size_t i = 0; i < ev.size(); ) {
            int cur_b1 = ev[i].b1;
            if (cur_b1 > last_b1) {
                auto all = seg.all_prod();
                if (all.first > max_common) {
                    max_common = all.first;
                    best_b1 = last_b1;
                    best_b2 = all.second;
                }
            }
            size_t j = i;
            while (j < ev.size() && ev[j].b1 == cur_b1) {
                auto &eobj = ev[j];
                int l = eobj.b2_l - 1, r = eobj.b2_r - 1;
                if (l <= r) seg.apply(l, r+1, eobj.add); // apply 是 [l, r)
                ++j;
            }
            auto all = seg.all_prod();
            if (all.first > max_common) {
                max_common = all.first;
                best_b1 = cur_b1;
                best_b2 = all.second;
            }
            i = j;
            last_b1 = cur_b1;
        }
        cout << max_common << '\n' << best_b1 << " " << best_b2 << '\n';
    }
    return 0;
}