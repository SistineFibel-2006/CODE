#include <bits/stdc++.h>
#include "atcoder/all"

// #START - tmpla.h
namespace FFFFF{
	#define FASTioMAGIC std::cin.tie(NULL)->sync_with_stdio(false)
    #define I(...)   \
            int __VA_ARGS__; \
            io>>__VA_ARGS__
    #define i64(...)   \
            long long __VA_ARGS__; \
            io>>__VA_ARGS__
	#define debug(x) cerr << #x << " = " << (x) << endl
	#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
	#define all(x) (x).begin(),(x).end()
	#define return(statement) return (statement),void();
    bool YON(bool a,bool upp=false){if(a){std::cout<<(upp?"YES\n":"Yes\n");}else{std::cout<<(upp?"NO\n":"No\n");}return a;}
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
    using std::tuple;
namespace defines {
	std::mt19937_64 rg(std::chrono::steady_clock::now().time_since_epoch().count());
	struct chash {
		size_t operator()(uint64_t x) const {
			static const uint64_t R = rg();
			return x ^ R;
		}
	};
    using pii = std::pair<int, int>;
    using pll = std::pair<long long, long long>;
    using vi = std::vector<int>;
    using vd = std::vector<long double>;
    using vl = std::vector<long long>;
    using vb = std::vector<bool>;
    using vs = std::vector<std::string>;
    using umapii = std::unordered_map<int, int, chash>;
    using mapii = std::map<int, int>;
    using sti = std::set<int>;
    using usti = std::unordered_set<int, chash>;
    using umapll = std::unordered_map<long long, long long, chash>;
    using mapll = std::map<long long, long long>;
    using stl = std::set<long long>;
    using ustl = std::unordered_set<long long, chash>; 
    using iii = std::tuple<int, int, int>;
    using lll = std::tuple<long long, long long, long long>;
    using iil = std::tuple<int, int, long long>;
    using ii = std::array<int, 2>;
    using ll = std::array<long long, 2>;
    struct cmp {
        bool operator()(int a, int b) {
            return a > b; // 默认最小堆
        }
    };
    using pq = std::priority_queue<int, std::vector<int> , cmp>;
}using namespace defines;
} //NAMESPCACE FFFFF
using namespace FFFFF;
// #END - tmpla.h
// $START - misc/io.h
namespace io_lib {
#ifdef FREAD
#define MAXBUFFERSIZE 1000000
inline char fgetc() {
  static char buf[MAXBUFFERSIZE + 5], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXBUFFERSIZE, stdin), p1 == p2) ? EOF : *p1++;
}
#undef MAXBUFFERSIZE
#define getchar fgetc
#endif
#define gc getchar
struct IOReader {
  template <typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
  inline const IOReader& operator>>(T& a) const {
    a = 0;
    bool flg = false;
    char ch = gc();
    while (ch < '0' || ch > '9') {
      if (ch == '-') flg ^= 1;
      ch = gc();
    }
    while (ch >= '0' && ch <= '9') {
      a = (a << 3) + (a << 1) + (ch ^ '0');
      ch = gc();
    }
    if (flg) a = -a;
    return *this;
  }
  inline const IOReader& operator>>(string& a) const {
    a.clear();
    char ch = gc();
    while (isspace(ch) && ch != EOF) ch = gc();
    while (!isspace(ch) && ch != EOF) a += ch, ch = gc();
    return *this;
  }
  inline const IOReader& operator>>(char* a) const {
    char ch = gc();
    while (isspace(ch) && ch != EOF) ch = gc();
    while (!isspace(ch) && ch != EOF) *(a++) = ch, ch = gc();
    *a = '\0';
    return *this;
  }
  inline const IOReader& operator>>(char& a) const {
    a = gc();
    while (isspace(a)) a = gc();
    return *this;
  }
  template <typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
  inline const IOReader& operator>>(T& a) const {
    a = 0;
    bool flg = false;
    char ch = gc();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = gc();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = gc();
    }
    if (ch == '.') {
      ch = gc();
      T p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = gc();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  template <typename T1, typename T2>
  inline const IOReader& operator>>(std::pair<T1, T2>& p) const {
    return operator>>(p.first), operator>>(p.second), *this;
  }
  template <typename T, const unsigned long long N>
  inline const IOReader& operator>>(std::array<T, N>& p) const {
    for (unsigned long long i = 0; i < N; i ++)
      operator>>(p[i]);
    return *this;
  }
  template <typename... Ts>
  inline const IOReader& operator>>(std::tuple<Ts...>& p) const;
#undef importRealReader
};
const IOReader io;
#undef gc
template <typename T>
void read(T& val) { io >> val; }
template <typename T>
void read(int l, int r, T& A) { for (int i = l; i <= r; i++) io >> A[i]; }
template <typename T>
void write(const T& A, int l, int r, const char* sp, const char* end = "") { for (int i = l; i <= r; i++) printf(sp, A[i]); printf("%s", end); }
template <typename T>
void write(const auto& A, const T* sp, const char* end = "") {for (auto e : A) printf(sp, e); printf("%s", end); }
template <typename T = int>
T read() { T res; io >> res; return res; }
template <typename T, int N>
std::array<T, N> read() { return read<std::array<T, N>>(); }
template <typename Tuple, typename Func, size_t... N>
void func_call_tuple(Tuple& t, Func&& func, std::index_sequence<N...>) { static_cast<void>(std::initializer_list<int>{(func(std::get<N>(t)), 0)...}); }
template <typename... Args, typename Func>
void travel_tuple(std::tuple<Args...>& t, Func&& func) { func_call_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{}); }
template <typename... Ts>
tuple<Ts...> reads() {
  tuple<Ts...> res;
  travel_tuple(res, [&](auto&& val) { io >> val; });
  return res;
}
template <typename... Ts>
inline const IOReader& IOReader::operator>>(std::tuple<Ts...>& p) const { return p = reads<Ts...>(), *this; }
template <typename T = int>
vector<T> getv(int n, int start = 0) {
  vector<T> res(start + n);
  for (int i = start; i < start + n; i++) io >> res[i];
  return res;
}
template <typename T, typename T1, typename... Ts>
vector<tuple<T, T1, Ts...>> getv(int n, int start = 0) {
  vector<tuple<T, T1, Ts...>> res(start + n);
  for (int i = start; i < start + n; i++) io >> res[i];
  return res;
}
}  // namespace io_lib
using namespace io_lib;
// $END - misc/io.h
// #START - misc/defs.h
namespace defs {
inline void Yes(bool x, string str = "") { printf("%s%s", (x) ? "Yes" : "No", str.c_str()); }
inline void YES(bool x, string str = "") { printf("%s%s", (x) ? "YES" : "NO", str.c_str()); }
inline void yes(bool x, string str = "") { printf("%s%s", (x) ? "yes" : "no", str.c_str()); }
inline void Yes(bool x, char ch) { printf("%s%c", (x) ? "Yes" : "No", ch); }
inline void YES(bool x, char ch) { printf("%s%c", (x) ? "YES" : "NO", ch); }
inline void yes(bool x, char ch) { printf("%s%c", (x) ? "yes" : "no", ch); }
#define openFile(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)
#define closeFile() fclose(stdin), fclose(stdout)
#define ALL(x) std::begin(x), std::end(x)
#define multiCase()         \
  int totCases; cin >> totCases; \
  for (int currCase = 1; currCase <= totCases; currCase++)
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __uint128_t;
using f32 = float;
using f64 = double;
template <typename T>
void sort(T& v) { sort(ALL(v)); }
template <typename T>
T sorted(T v) { return sort(v), v; }
template <typename T>
void sort(T& v, auto compare) { sort(ALL(v), compare); }
template <typename T>
T sorted(T v, auto compare) { return sort(v, compare), v; }
template <typename T>
void reverse(T& v) { reverse(ALL(v)); }
template <typename T>
T reversed(T v) { return reverse(v), v; }
template <typename T>
void unique(vector<T>& v) { v.erase(unique(ALL(v)), v.end()); }
template <typename T>
vector<T> uniqued(vector<T> v) { return unique(v), v; }
bool in(char ch, string str) {
  for (auto x : str)
    if (ch == x)
      return true;
  return false;
}
template <typename T>
bool in(T v, vector<T> V) {
  for (auto x : V)
    if (v == x)
      return true;
  return false;
}
template <typename T>
auto index(const vector<T>& v, int n = 0) {
  vector<pair<int, T>> res;
  for (int i = 0; i < (int) v.size(); i++)
    res.push_back({n++, v[i]});
  return res;
}
template <typename T>
auto pairwise(const vector<T>& v) {
  vector<pair<T, T>> res;
  for (int i = 1; i < (int)v.size(); i ++)
    res.push_back({v[i - 1], v[i]});
  return res;
}
auto index(const string& v, int n = 0) {
  return index(vector<char>(v.begin(), v.end()), n);
}
auto pairwise(const string& v) {
  return pairwise(vector<char>(v.begin(), v.end()));
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? (a = b, true) : false;
}
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? (a = b, true) : false;
}
template <typename T, typename T2>
bool ckmax(T& a, T2 b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename T2>
bool ckmin(T& a, T2 b) {
  return b < a ? (a = b, true) : false;
}
}  // namespace defs
using namespace defs;
// #END - misc/defs.h

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

  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/I(n); I(k);
  	if(n == 1) return(puts(k==1?"1":"-1"));
  	if(n == 2) return(puts(k==2?"1 2":"-1"));
  	if(n == 3) {
  		if(k == 2) return(puts("2 1 3"));
  		if(k == 3) return(puts("1 2 3"));
  		return(puts("-1"));
  	}
  	if(n == 4) {
  		if(k == 2) return(puts("4 3 1 2"));
  		if(k == 3) return(puts("4 1 2 3"));
  		if(k == 4) return(puts("1 2 3 4"));
  		return(puts("-1"));
  	} //n >= 5

  	if(k == 0) {
  		if(n < 8) return(puts("-1"));
  		const vi base = {3,4,8,7,2,1,5,6};
  		vi ans;
  		F(i, 0, n / 8)
  			for(auto c : base)
  				ans.pb(c + i * 8);
  		F(i, n / 8 * 8 + 1, n + 1)
  			ans.pb(i);
  		F(i, 0, n)
  			cout << ans[i] << " \n"[i == n - 1];
  		return;
  	}

  	if(k == 1) {
  		if(n == 5) return(puts("2 5 3 1 4"));
  		if(n == 6) return(puts("1 3 6 4 2 5"));
  		if(n == 7) return(puts("1 2 4 7 5 3 6"));
  		if(n < 8) return(puts("-1"));
  		const vi base = {3,4,8,7,2,1,5,6};
  		vi ans;
  		F(i, 0, n / 8)
  			for(auto c : base)
  				ans.pb(c + i * 8);
  		F(i, n / 8 * 8 + 1, n + 1)
  			ans.pb(i);

  		swap(ans[4], ans[0]);

  		F(i, 0, n)
  			cout << ans[i] << " \n"[i == n - 1];
  		return;
  	}

  	if(k >= 2) {
  		for(int i = n; i > k; i --)
  			cout << i << ' ';
  		for(int i = 1; i <= k; i ++)
  			cout << i << " \n"[i == k];
  		return;
  	}


return;};
}

struct RuntimeClock{std::chrono::high_resolution_clock::time_point s;RuntimeClock(){s=std::chrono::high_resolution_clock::now();}~RuntimeClock(){cerr<<"[Time] "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-s).count()<<" ms\n";}};


#undef cin
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
//==            POWERED BY     SISTINE_FIBEL  システィーナ=フィーベル         ==//
//============================================================================//