#include <bits/stdc++.h>
using namespace std;
//#include "atcoder/all"

#define pb push_back
#define fi first
#define se second
#define is insert
#define dbg debug


#define el '\n'
#define rep(i, a) for(int i = 0; i < a; i ++)

namespace sIsTiNeFiBeL {


  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/int n; cin >> n;
  	vector<int > a(n), b(n);
  	rep(i, n) cin >> a[i];
  	rep(i, n) cin >> b[i];
  	int mn = a[0];
  	for(int i = 1; i < n; i ++) {
  		if(mn > b[i]) {
  			cout << "No\n";
  			return;
  		}
  		mn = max(mn, a[i]);
  	}
  	cout << "Yes\n";

return;};
}

struct RuntimeClock{std::chrono::high_resolution_clock::time_point s;RuntimeClock(){s=std::chrono::high_resolution_clock::now();}~RuntimeClock(){cerr<<"[Time] "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-s).count()<<" ms\n";}};

signed main (){
    //FASTioMAGIC;
    RuntimeClock _;
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
//==                        SISTINE_FIBEL  システィーナ=フィーベル            ==//
//============================================================================//