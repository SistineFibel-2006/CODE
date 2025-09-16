#include <bits/stdc++.h>
#include <cinttypes>
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
struct E{
	int x, t, id;
	bool operator<(const E & o) const {
		if(x != o.x) return x < o.x;
		return t > o.t;
	}
};

  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/I(n);
  	vi s(n + 1), t(n + 1);
  	vector<E> ev; ev.reserve(2 * n);
  	F(i, 1, n + 1) {
  		cin >> s[i] >> t[i];
      ev.pb({ min(s[i],t[i]), 1, (I)i});
      ev.pb({ max(s[i],t[i]), -1, (I)i});  		
  	}
  	sort(ev);
  	auto cc = [&](int x) {return s[x] < t[x];};
  	vector<vi> g(n + 1);
  	vi ind(n + 1, 0);
  	vi stR, stL; stR.reserve(n); stL.reserve(n);

  	for(auto & e : ev) {
  		I id = e.id;
  		if(e.t == 1) {
  			if(!stR.empty()) {g[id].pb(stR.back()); ind[stR.back()] ++;}
  			if(!stL.empty()) {g[id].pb(stL.back()); ind[stL.back()] ++;}
  			if(cc(id))
  				stR.pb(id);
  			else
  				stL.pb(id);
  		} else {
  			if(cc(id)) {
  				if(!stR.empty() && stR.back() == id)
  					stR.pop_back();
  				else {
  					F_(i, stR.size() - 1, -1)
  						if(stR[i] == id){
  							stR.erase(stR.begin() + i);
  							break;
  						}
  				}
  			} else {
  				if(!stR.empty()) {g[id].pb(stR.back()); ind[stR.back()] ++;}
  				if(!stL.empty()) {
  					if(stL.back() == id) {
  						if(stL.size() >= 2) {
  							I p = stL[stL.size() - 2];
  							g[id].pb(p);
  							ind[p] ++;
  						}
  					} else {
  						F_(i, stL.size() - 1, -1) {
  							if(stL[i] == id) {
  								if(i >= -1) {
  									I p = stL[i - 1];
  									g[id].pb(p);
  									ind[p] ++;
  								}
  								stL.erase(stL.begin() + i);
  								break;
  							}
  						}
  					}
  				}
  			}
  		}
  	}

  	vi q(n);
  	F(i, 1, n + 1)
  		if(ind[i] == 0)
  			q.pb(i);
  	F(h, 0, q.size()){
  		I u = q[h];
  		for(auto v : g[u])
  			if(--ind[v] == 0)
  				q.pb(v);
  	}

  	if(q.size() != n)
  		return(puts("No"));

  	reverse(q);
  	F(i, 0, n)
  		cout << q[i] << " \n"[i == n - 1];

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