// #include <bits/stdc++.h>
// using namespace std;
/*
    ______  __  ______  ______ __  __   __  ______       ______ __  ______  ______  __        
   /\  ___\/\ \/\  ___\/\__  _/\ \/\ "-.\ \/\  ___\     /\  ___/\ \/\  == \/\  ___\/\ \       
   \ \___  \ \ \ \___  \/_/\ \ \ \ \ \-.  \ \  __\     \ \  __\ \ \ \  __<\ \  __\ \ \____     
    \/\_____\ \_\/\_____\ \ \_\ \_\ \_\"\_\ \_____\    \ \_\  \ \_\ \_____\ \_____\ \_____\ 
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
		std::vector<long long> v(n + start);
		for (int i = start; i < n + start; i ++) std::cin >> v[i];
		return v;
	}
}

namespace autos {

}

namespace Edge {

}

#define int long long

namespace Fenwick {
	int lowb(int x) {return (x & -x);}
	struct Fenwick {
		int n;
		std::vector<int> f;
		Fenwick (int x): n(x), f(n + 1, 0){}
		void reset() {std::fill(all(f), 0);}
		void update(int i, int val){
			for(; i <= n; i += lowb(i))
				f[i] += val;
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
const long long MOD = 1e9 + 7; //模数
// const long long MOD = 998244353;

#define pb push_back
#define fi first
#define se second
#define in insert
#define F(i, a, n) for(auto i = (a); (i) < (n); (i) ++)
#define F_(i, a, n) for(auto i = (a); (i) > (n); (i) --)


#define endl '\n'

using Fen = Fenwick::Fenwick;

int qpow(int a, int b) {
	int r = 1;
	a %= MOD;
	while(b) {
		if(b & 1)
				r = r * a % MOD;
			a = a * a % MOD;
			b >>= 1;
	}
	return r;
}

int inv2 = qpow(2, MOD - 2);

struct P {
	int x, y, a, u, v;
};

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
	int n; cin >> n;
	vector<P> p(n);
	vl vs;
	F(i, 0, n) {
		cin >> p[i].x >> p[i].y >> p[i].a;
		p[i].u = p[i].x + p[i].y;
		p[i].v = p[i].x - p[i].y;
		vs.pb(p[i].v);
	}

	sort(all(vs));
	vs.erase(unique(all(vs)), vs.end());

	auto get = [&](int v) {
		return lower_bound(all(vs), v) - vs.begin() + 1;
	};

	sort(all(p), [](P a, P b){
		return a.u != b.u ? a.u < b.u : a.v < b.v;
	});

	int M = vs.size();
	Fen c(M), sa(M), suv(M), sauv(M), sud(M), saud(M);

	int ans = 0;

	F(i, 0, n) {
		int u = p[i].u, v = p[i].v, a = p[i].a;
		int id = get(v);
		a %= MOD;
		int uv = (u + v + 2 * MOD) % MOD;
		int ud = (u - v + 2 * MOD) % MOD;

		int cnt1 = c.query(id);
		if(cnt1) {
			int sa1 = sa.query(id), suv1 = suv.query(id), sauv1 = sauv.query(id);
			int t1 = a * uv % MOD * cnt1 % MOD;
			int t2 = a * suv1 % MOD;
			int t3 = uv * sa1 % MOD;
			int t4 = sauv1;
			int cur = (t1 - t2 + t3 - t4 + 2 * MOD) % MOD;
			ans = (ans + cur) % MOD;
		}

		int cnt2 = i - cnt1;
		if(cnt2) {
			int sa2 = (sa.query(M) - sa.query(id) + MOD) % MOD;
			int sud2 = (sud.query(M) - sud.query(id) + MOD) % MOD;
			int saud2 = (saud.query(M) - saud.query(id) + MOD) % MOD;

			int t1 = a * ud % MOD * cnt2 % MOD;
			int t2 = a * sud2 % MOD;
			int t3 = ud * sa2 % MOD;
			int t4 = saud2;
			int cur = (t1 - t2 + t3 - t4 + 2 * MOD) % MOD;
			ans = (ans + cur) % MOD;

		}

		c.update(id, 1);
		sa.update(id, a);
		suv.update(id, uv);
		sauv.update(id, a * uv % MOD);
		sud.update(id, ud);
		saud.update(id, a * ud % MOD);

	}
	cout << ans * inv2 % MOD << endl;


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