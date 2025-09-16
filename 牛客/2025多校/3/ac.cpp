// #include <bits/stdc++.h>
// using namespace std;
/*
    ______  __  ______  ______ __  __   __  ______       ______ __  ______  ______  __        
   /\  ___\/\ \/\  ___\/\__  _/\ \/\ "-.\ \/\  ___\     /\  ___/\ \/\  == \/\  ___\/\ \       
   \ \___  \ \ \ \___  \/_/\ \\ \ \ \ \-.  \ \  __\     \ \  __\ \ \ \  __<\ \  __\\ \ \____     
    \/\_____\ \_\/\_____\ \ \_\\ \_\ \_\\"\_\ \_____\    \ \_\  \ \_\ \_____\ \_____\ \_____\ 
     \/_____/\/_/\/_____/  \/_/ \/_/\/_/ \/_/\/_____/     \/_/   \/_/\/_____/\/_____/\/_____/ 
*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()

void solve();

namespace stds {
	using std::cin;
	using std::cout;
	using std::min;
	using std::max;
	using std::upper_bound;
	using std::lower_bound;
	using std::abs;
	using std::ceil;
	using std::floor;
	using std::free;
	using std::cerr;
	using std::vector;
	using std::pair;
	using std::priority_queue;
	using std::set;
	using std::unordered_map;
	using std::map;
	using std::unordered_set;
	using std::string;
	using std::unordered_multimap;
	using std::unordered_multiset;
	using std::queue;
	using std::malloc;
	using std::sqrt;
	using std::sort;
	using std::stable_sort;
	using std::swap;
	using std::asin;
	using std::atan;
	using std::acos;
}

namespace defines {
	using pii = std::pair<int, int>;
	using pll = std::pair<long long, long long>;
	using vi = std::vector<int>;
	using vd = std::vector<long double>;
	using vl = std::vector<long long>;
	using vb = std::vector<bool>;
	using umapii = std::unordered_map<long long, long long>;
	using mapii = std::map<long long, long long>;
	using sti = std::set<long long>;
	using usti = std::unordered_set<long long>;
	
	struct cmp {
		bool operator()(int a, int b) {
			return a > b; // 默认最小堆
		}
	};
	using pq = std::priority_queue<int, std::vector<int> , cmp>;
	
}

namespace reads {
	std::vector<long long> getvi(int n, int start) {
		std::vector<long long> v(n);
		for (int i = start; i < (start == 0 ? n : n + 1); i ++) std::cin >> v[i];
		return v;
	}
}

namespace autos {

}

namespace Edge {

}

namespace Fenwick {
	int lowb(int x) {return (x & -x);}
	struct Fenwick {
		int n;
		std::vector<int> f;
		Fenwick (int x): n(x), f(n + 1, 0){}
		void reset() {std::fill(all(f), 0);}
		void update(int i){
			for(; i <= n; i += lowb(i))
				f[i] ++;
		}

		int query(int i) {
			int s = 0;
			for(; i > 0; i -= lowb(i))
				s += f[i];
			return s;
		}
	};
}


//============================================================================//
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  システィーナ=フィーベル         ==//
//============================================================================//
using namespace stds;
using namespace defines;
using namespace reads;

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
// const long long MOD = 998244353;

#define pb push_back
#define fi first
#define se second
#define in insert
#define F(i, a, n) for(auto i = (a); (i) < (n); (i) ++)
#define F_(i, a, n) for(auto i = (a); (i) > (n); (i) --)

#define int long long
#define endl '\n'



signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

int gain(int k, int a) {
	if(a + 1 <= 0)
		return 0;
	return (k / (a + 1)) * (a + 1);
}

void solve(){
	int n, a; cin >> n >> a;
	string s; cin >> s;

	bool isok = 0;
	int maxL = 0, now = 0;
	for(auto c : s)
		if(c == '0')
			now ++;
		else
			maxL = max(maxL, now), now = 0;

	maxL = max(maxL, now);
	if(maxL >= a + 1)
		isok = 1;

	if(!isok) {
		int st = -1;
		F(i, 0, n) {
			if(s[i] == '1' && st == -1)
				st = i;
			if(s[i] == '0' || i == n - 1) {
				if(st != -1) {
					int r = (s[i] == '1') ? i : i - 1;
					int len = r - st + 1;
					if(len >= a) {
						bool c1 = (st > 0 && s[st - 1] == '0');
						bool c2 = (r < n - 1 && s[r + 1] == '0');
						if(c1 || c2) {
							isok = 1; break;
						}
					}
				}
				st = -1;
			}
		}
	}

	if(isok) {
		cout << n << endl; return;
	}

	// /// // //

	int po = 0;
	for(auto c : s)
		if(c == '1')
			po ++;

	vl zs, os;
	int cnt = 0; char nowc = ' ';

	F(i, 0, n) {
		if(s[i] == '0') {
			if(i > 0 && s[i - 1] == '1') {
				os.pb(cnt);
				cnt = 0;
			}
			cnt ++;
		}
		else {
			if(i > 0 && s[i - 1] == '0') {
				zs.pb(cnt);
				cnt = 0;
			}
			cnt ++;
		}
	}
	if(cnt > 0)
		if(s.back() == '0')
			zs.pb(cnt);

	int bo = po;
	for(auto c : zs)
		bo += gain(c, a);

	if(zs.size() <= 1) {
		cout << bo << endl; return;
	}

	int m = zs.size();
	vl dp(m + 1, 0);

	F(i, 1, m + 1) {
		dp[i] = dp[i - 1];
		if(i >= 2) {
			if(i - 2 < os.size() && os[i - 2] == a) {
				int tt1 = gain(zs[i - 2] + zs[i - 1] + a, a) - gain(zs[i - 1], a) - gain(zs[i - 2], a) - a;
				int nn = (i > 2) ? dp[i - 2] : 0;
				dp[i] = max(dp[i], nn + tt1);
			}
		}
	}

	cout << bo + dp[m] << endl;
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
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  システィーナ=フィーベル         ==//
//============================================================================//
