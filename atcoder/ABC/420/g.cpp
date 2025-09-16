#include <bits/stdc++.h>
//#include "atcoder/all"


#include "lib/tmpla.h"
#include "lib/misc/defs.h"
#include "lib/misc/io.h"
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

using I = int;
#define el '\n'

namespace sIsTiNeFiBeL {

  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/I(x);
    i64 Dorig = 4 * x - 1; 
    i64 absD = llabs(Dorig);
    vector<i64> res;

    if (absD != 0) {
        i64 L = (i64)floor(sqrt((long double)absD));
        F(div, 1, L + 1) {
            if ((div & 1) == 0) 
              continue;   
            if (absD % div != 0) 
              continue;
            i64 ot = absD / div;

            pll ord[2] = { {div, ot}, {ot, div} };
            for (auto pr : ord) {
                i64 a0 = pr.fi;
                i64 b0 = pr.se;

                pll cand1, cand2;
                if (Dorig > 0) {
                    cand1 = {a0, b0};
                    cand2 = {-a0, -b0};
                } 
                else {
                    cand1 = {a0, -b0};
                    cand2 = {-a0, b0};
                }

                auto work = [&](pll p){
                    i64 a = p.fi, b = p.se;
                    auto m4 = [](i64 v)->I { I r = (I)(v % 4); if (r < 0) r += 4; return r; };
                    if (m4(a + b) != 0) return;
                    if (m4(b - a - 2) != 0) return;
                    i64 n = (b - a - 2) / 4;
                    res.pb(n);
                };

                work(cand1);
                work(cand2);
            }
        }
    }

    sort(res);
    res.erase(unique(all(res)), res.end());
    cout << (I)res.size() << el;
    F(i, 0, res.size())
        cout << res[i] << ' ';
    
    // if (!res.empty()) cout << "\n";
return;};
}

#undef cin
signed main (){
    //FASTioMAGIC;
    int t = 1;
    // cin >> t;  //atc默认关闭，cf按需开启
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