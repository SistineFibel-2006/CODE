#include <bits/stdc++.h>
#include "atcoder/all"

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

  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/int n; cin >> n;
    vl x(n), y(n);
    F(i, 0, n)
      cin >> x[i] >> y[i];
    int M = n * (n - 1) / 2;
    vector<pll> S, mids; S.reserve(M); mids.reserve(M);

    auto mygcd = [](int a, int b) {
      if(a < 0)
        a = -a;
      if(b < 0)
        b = -b;
      while(b) {int t = a % b; a = b; b = t;}
      return a;
    };

    F(i, 0, n)
      F(j, i + 1, n) {
        int dx = x[j] - x[i], dy = y[j] - y[i];
        int g = mygcd(dx, dy);
        dx /= g, dy /= g;
        if(dx < 0 || (dx == 0 && dy < 0))
          dx = -dx, dy = -dy;
        S.emplace_back(dx, dy);
        mids.emplace_back(x[i] + x[j], y[i] + y[j]);
      }

    sort(all(S)); sort(all(mids));

    int sum = 0;
    for(int l = 0; l < S.size();) {
      int r = l + 1;
      while(r < S.size() && S[r] == S[l])
        r ++;
      int cnt = r - l;
      sum += cnt * (cnt - 1) / 2;
      l = r;
    }

    int sum2 = 0;
    for(int l = 0; l < mids.size();) {
      int r = l + 1;
      while(r < mids.size() && mids[r] == mids[l])
        r ++;
      int cnt = r - l;
      sum2 += cnt * (cnt - 1) / 2;
      l = r;
    }    

    cout << sum - sum2;
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