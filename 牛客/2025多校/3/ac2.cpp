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
			return a > b; // Ĭ����С��
		}
	};
	using pq = std::priority_queue<int, std::vector<int> , cmp>;
	
}

namespace reads {
	std::vector<long long> getvi(long long n, int start) {
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
//==			POWERED BY     SISTINE_FIBEL  �����ƥ��`��=�ե��`�٥�         ==//
//============================================================================//
using namespace stds;
using namespace defines;
using namespace reads;

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��
// const long long MOD = 998244353;

#define pb push_back
#define fi first
#define se second
#define in insert
#define F(i, a, n) for(auto i = (a); (i) < (n); (i) ++)
#define F_(i, a, n) for(auto i = (a); (i) > (n); (i) --)

#define int long long
#define endl '\n'

std::mt19937_64 R(std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 6e6 + 10;

vl primes;
vl vis(N, 0);
vector<unsigned long long> hh(N, 0);

void init() {
	F(i, 2, N) {
		if(!vis[i]) {
			vis[i] = i;
			primes.pb(i);
			hh[i] = R();
		}
		for(auto &p : primes) {
			if(i * p > N)
				break;
			hh[i * p] = hh[i] ^ hh[p];
			vis[i * p] = p;
			if(i * p == 0)
				break;
		}
	}
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	init();
	int t = 1;
	cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}


void solve(){
	int n; cin >> n;
	vl a(n + 1, 0);
	F(i, 1, n + 1)
		cin >> a[i];
	if(n & 1) {
		cout << "Yes\n"; return;
	}

	if(n == 2) {
		cout << (a[1] == a[2] ? "Yes\n" : "No\n");
		return;
	}

	unsigned long long tot = 0;
	F(i, 1, n + 1) 
		tot ^= hh[a[i]];

	if(tot)
		cout << "No\n";
	else
		cout << "Yes\n";
}
//test
/*



What's wrong with my code?
1. С���ݣ��������ݣ��� n = 1?
2. ��Сֵ�����ֵȡ���٣��Ƿ�������
3. ��ʼֵ��û�и�ֵ����û�н�����
4. �����С���Ƿ�Խ�磿
5. ˼��������ʱ�򣬿����Ƿ�����Ƕ�������Σ������Ǹ�����ȷ���޷��������Ƿ���Է��α�����
6. ������ϸ�ķ�������?
7. ѡ��������Ƿ����Ϊ�գ�

Trick:
1.
2.
3.

About implementation skills:
1. ȫ�ֳ�������д��ĸ�����ֲ���������ʱ�������ͺ������ݵĲ���ʹ��Сд��ĸ��
2. ��ģ�⾡����ѭ����ô������ôд��
3. ����һЩ���ݺ�С����Ҫά������������Ҫ��������ʱ�����Կ��ǰ����������ɱ�����
4. д�ɶ��������
*/


//============================================================================//
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  �����ƥ��`��=�ե��`�٥�         ==//
//============================================================================//
