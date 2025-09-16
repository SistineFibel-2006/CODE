// #include <bits/stdc++.h>
// using namespace std;

//  ______  __  ______  ______ __  __   __  ______       ______ __  ______  ______  __        
// /\  ___\/\ \/\  ___\/\__  _/\ \/\ "-.\ \/\  ___\     /\  ___/\ \/\  == \/\  ___\/\ \       
// \ \___  \ \ \ \___  \/_/\ \\ \ \ \ \-.  \ \  __\     \ \  __\ \ \ \  __<\ \  __\\ \ \____  
//  \/\_____\ \_\/\_____\ \ \_\\ \_\ \_\\"\_\ \_____\    \ \_\  \ \_\ \_____\ \_____\ \_____\ 
//   \/_____/\/_/\/_____/  \/_/ \/_/\/_/ \/_/\/_____/     \/_/   \/_/\/_____/\/_____/\/_____/ 

#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

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

namespace autos {

}

namespace Edge {

}
//============================================================================//
//==		A SINGLE BIG LINE USED TO BREAK THE F**KING TEMPLATE!!!!        ==//
//==			POWERED BY     SISTINE_FIBEL  �����ƥ��`��=�ե��`�٥�           ==//
//============================================================================//
using namespace stds;
using namespace defines;

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //ģ��
// const long long MOD = 998244353;

#define pb push_back
#define fi first
#define se second
#define F(i, a, n) for(register auto (i) = (a); (i) < (n); (i) ++)
#define F_(i, a, n) for(register auto (i) = (a); (i) > (n); (i) --)

#define int long long
#define endl '\n'



signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atcĬ�Ϲرգ�cf���迪��
	while(t --)
		solve();
}
#define t(i) ((i) * (i) * (i))
void solve(){
	int n; cin >> n;
    int x = 1, y = 1;
    while(x <= 577350269){
        if(t(x) - t(y) > n)
            y ++;
        else if(t(x) - t(y) < n)
            x ++;
        else {
            cout << x << ' ' << y << endl;
            return;
        }
    }
	cout << -1;
}
//test
/*


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
//==			POWERED BY     SISTINE_FIBEL  �����ƥ��`��=�ե��`�٥�           ==//
//============================================================================//