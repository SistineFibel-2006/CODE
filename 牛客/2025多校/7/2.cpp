#include <bits/stdc++.h>
#include <functional>
using namespace std;

//muban
// 使用 long long 作为基本类型
using i64 = long long;
// 使用 __i128 处理超大数乘法
using i128 = __int128;

const i64 MOD = 998244353;

// 大数的模乘 (a*b % m)
i64 mul_mod(i64 a, i64 b, i64 m) {
    return static_cast<i64>((i128)a * b % m);
}

// 大数的模幂 (base^exp % m)
i64 power_mod(i64 base, i64 exp, i64 m) {
    i64 res = 1;
    base %= m;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul_mod(res, base, m);
        base = mul_mod(base, base, m);
        exp /= 2;
    }
    return res;
}

// Miller-Rabin 素性测试
bool is_prime(i64 n) {
    if (n < 2) return false;
    // 针对 10^18 内的确定性测试基
    const static i64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    i64 d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (i64 a : bases) {
        if (n == a) return true;
        i64 t = d;
        i64 y = power_mod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = mul_mod(y, y, n);
            t *= 2;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

// Pollard's Rho 整数分解
i64 pollard(i64 n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;

    auto f = [&](i128 x, i128 c) {
        return (x * x + c) % n;
    };
    
    i128 x = 0, y = 0;
    i64 c = 1;
    i64 d = 1;
    
    while (true) {
        x = 2, y = 2;
        d = 1;
        while (d == 1) {
            x = f(x, c);
            y = f(f(y, c), c);
            d = std::gcd(std::abs(static_cast<i64>(x - y)), n);
        }
        if (d != n) return d;
        c++;
    }
}
//muban

void work(i64 n, map<i64,int>& M) {
    if (n<=1) return;
    while(n % 2 == 0)
        M[2] ++, n /= 2;
    while(n % 3 == 0)
        M[3] ++, n /= 3;
    for(i64 i = 5; i * i <= n && i <= 1000000; i += 6){
        while(n % i == 0)
            M[i] ++, n /= i;
        while(n % (i + 2) == 0)
            M[i + 2] ++, n /= (i + 2);
    }

    if(n <= 1) return;

    vector<i64> tt;
    tt.push_back(n);
    while(!tt.empty()) {
        i64 cur = tt.back();
        tt.pop_back();
        if(cur <= 1) continue;
        if(is_prime(cur)) {M[cur] ++; continue;}
        i64 pp = pollard(cur);
        tt.push_back(pp); tt.push_back(cur / pp);
    }
}


int main() {std::cin.tie(NULL)->sync_with_stdio(false);
	

	int _t; cin >> _t; while(_t --) 
	{
		i64 a, b, c, d; cin >> a >> b >> c >> d;
		i64 gc = gcd(a, c);
		if(gc == 1) {cout << 1 << endl; continue;}

		map<i64, int> factor;
		work(gc, factor);

		i64 ans = 1;
		for(auto &&[pr, _] : factor) {
            i64 p = pr;
            i64 cnta = 0;
            if(a > 0){
                i64 tta = a;
                while(tta > 0 && tta % p == 0)
                    cnta ++, tta /= p;
            }
            i64 cntc = 0;
            if(c > 0){
                i64 ttc = c;
                while(ttc > 0 && ttc % p == 0)
                    cntc ++, ttc /= p;
            }
            i128 ea  = (i128)cnta * b;
            i128 ec  = (i128)cntc * d;
            i128 mine = min(ea, ec);
            i64 ep = (i64)(mine % (MOD - 1));
            i64 tt = power_mod(p, ep, MOD);
            ans = mul_mod(ans, tt, MOD);
		}

		cout << ans << endl;

	}
}
