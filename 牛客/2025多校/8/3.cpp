#include <bits/stdc++.h>
using namespace std;

#define NO_TEMPLATE_IMPORT

#include "lib/misc/defs.h"

using ull = unsigned long long;

const I seg7[10] = {
    0b0111111,
    0b0000110,
    0b1011011,
    0b1001111,
    0b1100110,
    0b1101101,
    0b1111101,
    0b0000111,
    0b1111111,
    0b1101111,
};

void solv() {
    I n, m; cin >> n >> m;
    vector<string> a(n);
    for(auto &c : a)
        cin >> c;
    I M = m * 7;
    vector<ull> b(n);
    for(I i = 0; i < n; i ++) {
        ull c = 0;
        for(I k = 0; k < m; k ++) {
            ull s = seg7[a[i][k] - '0'];
            c |= (s << (k * 7));
        }
        b[i] = c;
    }

            bool ok = true;
    I ans = M;
    unordered_set<ull> vis;
    vis.reserve(128); vis.max_load_factor(0.5f);
    for(I k = 0; k <= M; k ++) {
        if(k == 0){
            if(n == 1) ans = 0;
            if(ans == 0) break;
            continue;
        }
       
        if(k > M) break;
        ull w = (ull(1) << k) - 1;
        ull l = (ull(1) << M);
        for(; w < l; ){
            vis.clear(); ok = false;
            for(int i = 0; i < n; i ++) {
                ull x = b[i] & w;
                if(!vis.insert(x).second){ok = 0; break;};
            }
            if(ok){ans = k; break;}
            ull c = w & -w; ull r = w + c;
            if(r == 0) break;
            w = (((r ^ w) >> 2) / c) | r;
        }
        if(ok) break;
    }
    cout << ans << endl;
}


I main() {
    ios::sync_with_stdio(0); cin.tie(0);

    I _; cin >> _; while(_ --) solv();
}