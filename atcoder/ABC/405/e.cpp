#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

// 快速幂
int qp(int a, int b = MOD-2) {
    int r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

// 预处理到 N 最大可能的阶乘/逆阶乘
int NMAX = 4000000;
vector<int> fac, ifac;
void init(int N) {
    fac.assign(N+1, 1);
    for (int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % MOD;
    ifac.assign(N+1, 1);
    ifac[N] = qp(fac[N]);
    for (int i = N; i > 0; i--) ifac[i-1] = ifac[i] * i % MOD;
}

// 计算 C(n,k)
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}

// 合并：先 P 串 Q
// 返回 pair{size(P→Q), e(P→Q)}
pair<int,int> series(const pair<int,int>& P, const pair<int,int>& Q) {
    int sz = P.first + Q.first;
    int ways = (int)C(sz, P.first) * P.second % MOD * Q.second % MOD;
    return {sz, ways};
}

// 合并：P 并 Q
pair<int,int> parallel(const pair<int,int>& P, const pair<int,int>& Q) {
    // 并联和串联在多重集里是同公式
    return series(P, Q);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A,B,Cc,D;
    cin >> A >> B >> Cc >> D;
    int N = A + B + Cc + D;
    init(N);

    // 单节点 Poset: k 个相同元素，扩张数 = 1，大小 = k
    auto PA = make_pair((int)A, 1LL);
    auto PB = make_pair((int)B, 1LL);
    auto PC = make_pair((int)Cc, 1LL);
    auto PD = make_pair((int)D, 1LL);

    // 1) A || B
    auto P1 = parallel(PA, PB);
    // 2) (A||B) → C
    auto P2 = series(P1, PC);
    // 3) P2 → D
    auto P3 = series(P2, PD);

    // P3.second 就是线性扩张数
    cout << P3.second << "\n";
    return 0;
}