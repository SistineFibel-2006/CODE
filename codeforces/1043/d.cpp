#include <bits/stdc++.h>
//#include "atcoder/all"

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

using I = int;
#define el '\n'

vl p(17), sum(17);
namespace sIsTiNeFiBeL {
  void init() {
    p[0] = 1;
    Fd(i, 1, 16) p[i] = p[i - 1] * 10;
    sum[0] = 0;
    Fd(i, 1, 16) sum[i] = i * 45LL * p[i - 1];
  }
  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/i64 k; cin >> k;

    auto cnt = [&](i64 n) -> i64 {
      if(n == 0) return 0;
      string s = std::to_string(n);
      i64 d = s.size(), res = 0;
      F(i, 1, d)
        res += i * 9 * p[i - 1];
      res += (n - p[d - 1] + 1) * d;
      return res;
    };

    std::function<i64(i64)> gsum = [&](i64 n) -> i64{
      if(n <= 0) return 0;
      if(n < 10) return n * (n + 1) / 2;
      string s = std::to_string(n);
      int d = s.size();
      i64 now = n / p[d - 1], res = n % p[d - 1];
      return now * sum[d - 1]
           + now * (now - 1) / 2 * p[d - 1]
           + now * (res + 1)
           + gsum(res);
    };

    i64 lft = 1, rt = 1e15, n = 0;
    while(lft <= rt){
      i64 mid = (lft + rt) / 2;
      if(cnt(mid) >= k)
        n = mid, rt = mid - 1;
      else
        lft = mid + 1;
    }

    i64 up = k - cnt(n - 1), ans = gsum(n - 1);
    string s = std::to_string(n);
    F(i, 0, up)
      ans += s[i] - '0';

    cout << ans << el;
return;};
}

#undef cin
signed main (){
    //FASTioMAGIC;
    int t = 1;
    cin >> t;  //atc默认关闭，cf按需开启
    sIsTiNeFiBeL::init();
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
