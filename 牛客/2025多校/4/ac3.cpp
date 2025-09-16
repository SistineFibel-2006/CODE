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
// #include <array>
// #include <bitset>
// #include <cassert>
// #include <chrono>
// #include <cmath>
// #include <complex>
// #include <deque>
// #include <forward_list>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
#include <iostream>
// #include <limits>
// #include <list>
// #include <map>
// #include <memory>
// #include <numeric>
// #include <optional>
// #include <queue>
// #include <random>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <string>
// #include <tuple>
// #include <type_traits>
// #include <unordered_map>
// #include <unordered_set>
// #include <utility>
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
	// using std::ceil;
	// using std::floor;
	using std::free;
	using std::cerr;
	using std::vector;
	// using std::pair;
	// using std::priority_queue;
	// using std::set;
	// using std::unordered_map;
	// using std::map;
	// using std::unordered_set;
	// using std::string;
	// using std::unordered_multimap;
	// using std::unordered_multiset;
	// using std::queue;
    // using std::multiset;
	// using std::malloc;
	// using std::sqrt;
	// using std::sort;
	// using std::stable_sort;
	// using std::swap;
	// using std::asin;
	// using std::atan;
	// using std::acos;
}

namespace defines {
	using pii = std::pair<int, int>;
	using pll = std::pair<long long, long long>;
	using vi = std::vector<int>;
	using vd = std::vector<long double>;
	using vl = std::vector<long long>;
	using vb = std::vector<bool>;
	// using umapii = std::unordered_map<long long, long long>;
	// using mapii = std::map<long long, long long>;
	// using sti = std::set<long long>;
	// using usti = std::unordered_set<long long>;
	
	// struct cmp {
	// 	bool operator()(int a, int b) {
	// 		return a > b; // Ĭ����С��
	// 	}
	// };
	// using pq = std::priority_queue<int, std::vector<int> , cmp>;
	
}


namespace Edge {

}

namespace Fenwick {
	int lowb(int x) {return x & -x;}
    struct Fenwick {
        int n;
        std::vector<int> f;
        Fenwick(int _n): n(_n), f(n+2, 0) {}
        void add(int i, int v){
            for(int x = i+1; x <= n; x += lowb(x)) 
                f[x] += v;
        }
        int sum(int i) const {
            int s = 0;
            for(int x = i+1; x > 0; x -= lowb(x))
                s += f[x];
            return s;
        }
        int sum(int l, int r) const {
            if(l > r) return 0;
            return sum(r) - (l>0 ? sum(l-1) : 0);
        }
        int findByPrefix(int k) const {
            int idx = 0;
            int bitMask = 1 << (31 - __builtin_clz(n)); 
            for(; bitMask; bitMask >>= 1){
                int t = idx + bitMask;
                if(t <= n && f[t] < k){
                    idx = t;
                    k -= f[t];
                }
            }
            return idx;
        }
    };
}


//============================================================================//
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  �����ƥ��`��=�ե��`�٥�         ==//
//============================================================================//
using namespace stds;
using namespace defines;



const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��
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
using namespace Fenwick;

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (auto &c : a)
        cin >> c;
        
    // sort(a.begin(), a.end());

    while (q--) {
        int x, y;
        cin >> x >> y;
        vector<int> d;
        for (auto v : a)
            if (v > x)
                d.push_back(v - x);
        int m = d.size();
        
        if (m <= y - 1) {
            cout << 0 << endl;
            continue;
        }

        int D = *max_element(d.begin(), d.end());
        Fenwick::Fenwick bitCnt(D + 1), bitSum(D + 1);
        for (int v : d) {
            bitCnt.add(v, 1);
            bitSum.add(v, v);
        }

        auto check = [&](int k) -> bool {
            int ptr = 0;
            for (int step = 0; step < k; step++) {
                int lst = bitCnt.sum(0, D);
                if (lst <= y - 1)
                    return true;
                int c0 = bitCnt.sum(ptr);
                int now = lst - c0;
                if (now <= 0)
                    return true;
                int v = bitCnt.findByPrefix(c0 + 1);
                ptr++;
                bitCnt.add(v, -1);
                bitSum.add(v, -v);
                if (v - 1 > ptr) {
                    bitCnt.add(v - 1, 1);
                    bitSum.add(v - 1, v - 1);
                }
            }
            return (bitCnt.sum(0, D) <= y - 1);
        };

        int l = 0, r = D + m, ans = r;
        auto cntBak = bitCnt.f;
        auto sumBak = bitSum.f;

        while (l <= r) {
            int mid = (l + r) >> 1;
            bitCnt.f = cntBak;
            bitSum.f = sumBak;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
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


