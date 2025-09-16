// #include <bits/stdc++.h>
// using namespace std;
/*
   ___|   _ _|    ___|   __ __|  _ _|    \  |   ____|       ____|  _ _|   __ )    ____|   |     
 \___ \     |   \___ \      |      |      \ |   __|         |        |    __ \    __|     |     
       |    |         |     |      |    |\  |   |           __|      |    |   |   |       |     
 _____/   ___|  _____/     _|    ___|  _| \_|  _____|      _|      ___|  ____/   _____|  _____| 
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

#define FASTioMAGIC std::cin.tie(NULL)->sync_with_stdio(false)
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()

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
	using std::multiset;
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
	template <typename Container>
	inline long long S(const Container& c) {
    	return static_cast<long long>(c.size());
	}
}

namespace Edge {

template <typename T = int> // 默认边权为int类型
struct Graph {
    struct Edge {
        int to;     // 边的终点
        T w;        // 边权
        int next;   // 下一条边的索引
        Edge() : to(0), w(T()), next(-1) {}
        Edge(int _to, T _w, int _next) : to(_to), w(_w), next(_next) {}
    };

    std::vector<int> head;  // 每个节点的第一条边索引
    std::vector<Edge> edges; // 边存储数组
    int edgeCount;          // 当前边的数量

    // 构造函数：初始化节点数量
    Graph(int n) : head(n, -1), edgeCount(0) {}

    // 添加边 (u -> v, 权值为w)
    void addEdge(int u, int v, T w = T()) {
        edges.emplace_back(v, w, head[u]);
        head[u] = edgeCount++;
    }

    // 遍历节点u的所有出边 (使用函数回调)
    void forEach(int u, const std::function<void(int, T)> &func) {
        for (int i = head[u]; ~i; i = edges[i].next) {
            func(edges[i].to, edges[i].w);
        }
    }

    // 清空图 (保留内存)
    void clear() {
        std::fill(head.begin(), head.end(), -1);
        edges.clear();
        edgeCount = 0;
    }

    // 获取节点u的出边数量
    int degree(int u) const {
        int cnt = 0;
        for (int i = head[u]; ~i; i = edges[i].next) cnt++;
        return cnt;
    }
};

}

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
using namespace autos;

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
// const long long MOD = 998244353;

#define pb push_back
#define fi first
#define se second
#define in insert
#define F(i, a, n) for(long long i = (a); (i) < (n); (i) ++)
#define Fd(i, a, n) for(long long i = (a); (i) <= (n); (i) ++)
#define F_(i, a, n) for(long long i = (a); (i) > (n); (i) --)
#define F_d(i, a, n) for(long long i = (a); (i) >= (n); (i) --)

#define int long long
#define endl '\n'

namespace sIsTiNeFiBeL {
	vl ans;
	void init() {
		F(i, 2, 1<<10) {
			int t = 0;
			F_d(j, 9, 0)
				if(i & (1 << j))
					t *= 10, t += j;
			ans.pb(t);
		}
		sort(all(ans));
	}

	inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/init();
		int t; cin >> t;
		cout << ans[t - 1];
return;};
}

signed main (){
	FASTioMAGIC;
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
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  システィーナ=フィーベル         ==//
//============================================================================//