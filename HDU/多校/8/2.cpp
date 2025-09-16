
#include <bits/stdc++.h>

// #include "atcoder/all"

#include "lib/tmpla.h"
#include "lib/misc/defs.h"

#define F(i, a, n) for(long long i = (a); (i) < (n); (i) ++)
#define Fd(i, a, n) for(long long i = (a); (i) <= (n); (i) ++)
#define F_(i, a, n) for(long long i = (a); (i) > (n); (i) --)
#define F_d(i, a, n) for(long long i = (a); (i) >= (n); (i) --)

#define pb push_back
#define fi first
#define se second
#define in insert

#define cin io

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
// const long long MOD = 998244353;

#define int long long
#define endl '\n'

namespace sIsTiNeFiBeL {
	auto rd = [](i128 &x) {
    string s; cin >> s; x = 0;
    bool neg = 0; int i = 0;
    if (s[0] == '-') neg = 1, i = 1;
    for (; i < (int)s.size(); i++) x = x * 10 + (s[i] - '0');
    if (neg) x = -x;
	};
	auto wt = [](i128 x) {
	    if (x == 0) { cout << 0; return; }
	    if (x < 0) { cout << '-'; x = -x; }
	    string s; while (x) { s += char('0' + x % 10); x /= 10; }
	    reverse(s.begin(), s.end());
	    cout << s;
	};
  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/i128 n, w; rd(n), rd(w);
		i128 m = n, ans = 0;
		while(1) {
			i128 q = m / w;
			if(q == 0){ans += m * n - m * (m - 1) / 2; break;}
			i128 minm = q * w;
			i128 s = (m - minm) / q + 1;
			i128 sum1 = s * m - q * (s * (s - 1) / 2);
			i128 sum2 = s * m * m - 2 * m * q * (s * (s - 1) / 2)
									+ q * q * (s * (s - 1) * (2 * s - 1) / 6);
			i128 ls = -sum2 + (2 * n + 1) * sum1;
      
			ans += ls / 2;
			m = m - s * q;
		}
		wt(ans); puts("");

return;};
}

#undef cin
signed main (){
    //FASTioMAGIC;
    int t = 1;
    cin >> t;  //atc默认关闭，cf按需开启
    while(t --)
        sIsTiNeFiBeL::Tempest_Flare__The_Wind_Splitting_Magic_Bullet();
    return 0;
}

//test
/*



What's wrong with my code?
1. 小数据？特殊数据？如 n = 1?
2. 最小值，最大值取多少？是否会溢出？
3. 初始值有没有赋值？有没有建树？
4. 数组大小？是否越界？
5. 思考暴力的时候，考虑是否可能是多个连续段？或者是个数不确定无法暴力？是否可以分治暴力？
6. 进行详细的分类讨论?
7. 选择的区间是否可以为空？

Trick:
1.
2.
3.

About implementation skills:
1. 全局常量均大写字母，而局部变量，临时变量，和函数传递的参数使用小写字母。
2. 大模拟尽量遵循：怎么方便怎么写。
3. 对于一些数据很小的需要维护的量并且需要大量讨论时，可以考虑把数组拆掉换成变量。
4. 写成多个函数。
*/


//============================================================================//
//==            POWERED BY     SISTINE_FIBEL  システィーナ=フィーベル         ==//
//============================================================================//

