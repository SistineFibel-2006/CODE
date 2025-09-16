#include <bits/stdc++.h>
//#include "atcoder/all"

#include "lib/tmpla.h"
#include "lib/misc/defs.h"

#define F(i, a, n) for(size_t i = (a); (i) < (n); (i) ++)
#define Fd(i, a, n) for(size_t  i = (a); (i) <= (n); (i) ++)
#define F_(i, a, n) for(size_t  i = (a); (i) > (n); (i) --)
#define F_d(i, a, n) for(size_t  i = (a); (i) >= (n); (i) --)

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
struct trie {
    int nex[2000 * 75 + 5][26], cnt;
    bool exist[2000 * 75 + 5];  // 该结点结尾的字符串是否存在

    trie() {
        memset(nex, 0, sizeof(nex));
        memset(exist, 0, sizeof(exist));
        cnt = 0;
    }

    void insert(const string &s) {  // 插入字符串
        int p = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = true;
    }

    int dfs(int u) {
        int res = exist[u] ? 1 : 0;
        int best = res;
        for (int c = 0; c < 26; c++) {
            int v = nex[u][c];
            if (!v) continue;
            int child = dfs(v);
            if (exist[u]) best = max(best, 1 + child);
            else best = max(best, child);
        }
        return best;
    }
};

  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/int n; cin >> n;
  	trie T;
  	F(i, 0, n) {
  		string s; cin >> s;
  		T.insert(s);
  	}
  	cout << T.dfs(0) << el;
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