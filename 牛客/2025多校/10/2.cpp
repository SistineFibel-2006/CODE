#include <bits/stdc++.h>
// $START - internal_bit.hpp
namespace atcoder {
namespace internal {
#if __cplusplus >= 202002L
using std::bit_ceil;
#else
// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}
#endif
// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
}  // namespace internal
}  // namespace atcoder
// $END - internal_bit.hpp
// $START - internal_bit
// $END - internal_bit
// #START - lazysegtree.hpp
namespace atcoder {
#if __cplusplus >= 201703L
template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct lazy_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
        "mapping must work as F(F, S)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "compostiion must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");
#else
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
#endif
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() { return d[1]; }
    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
}  // namespace atcoder
// #END - lazysegtree.hpp

// #START - tmpla.h
namespace FFFFF{
  #define FASTioMAGIC std::cin.tie(NULL)->sync_with_stdio(false)
  #define debug(x) cerr << #x << " = " << (x) << endl
  #define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
  #define all(x) (x).begin(),(x).end()
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
    using umapii = std::unordered_map<int, int, chash>;
    using mapii = std::map<int, int>;
    using sti = std::set<int>;
    using usti = std::unordered_set<int, chash>;
    using umapll = std::unordered_map<long long, long long, chash>;
    using mapll = std::map<long long, long long>;
    using stl = std::set<long long>;
    using ustl = std::unordered_set<long long, chash>; 
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

#define F(i, a, n) for(long long i = (a); (i) < (n); (i) ++)
#define Fd(i, a, n) for(long long i = (a); (i) <= (n); (i) ++)
#define F_(i, a, n) for(long long i = (a); (i) > (n); (i) --)
#define F_d(i, a, n) for(long long i = (a); (i) >= (n); (i) --)

#define pb push_back
#define fi first
#define se second
#define in insert

#define cin io

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
// const long long MOD = 998244353;

#define endl '\n'

namespace sIsTiNeFiBeL {
	using S = pii;
	using F = int;
	S op(S a, S b) {
		if(a.fi >= b.fi)
			return a;
		return b;
	}
	S e() { return S{-(1 << 30), INT_MAX};}
	S mapping(F f, S x) {
		x.fi += f;
		return x;
	}
	F composition(F f, F g) {return f + g;}
	F id() {return 0;}
	struct Event {int b1, b2l, b2r, add;};
  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/int n; cin >> n;
  	map<int, vi> pos;
  	F(i, 0, n) {
  		int v; cin >> v;
  		pos[v].pb(i + 1);
  	}
  	vector<Event> ev;
  	for(auto &c : pos) {
  		auto &p = c.se;
  		if(p.size() < 3) continue;
  		int lst = p.back();
  		ev.pb({p[0] + 1, p[1] + 1, lst, 1});
  		F(i, 1, p.size() - 1) {
  			int tt = p[i] + 1;
  			ev.pb({tt, p[i] + 1, lst, -1});
  			ev.pb({tt, p[i + 1] + 1, lst, 1});
  		}
  	}

  	sort(all(ev), [](Event a, Event b){
  		if(a.b1 != b.b1) return a.b1 < b.b1;
  		return a.add > b.add;
  	});

  	vector<S> init(n);
  	F(i, 0, n) init[i] = {0, i + 1};
  	atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

  	int ans = 0;
  	int bb1 = 2, bb2 = 3;
  	if(ev.empty())
  		return cout << 0 << endl << bb1 << ' ' << bb2 << endl, void();

  	int lstb1 = 1;
  	for(size_t i = 0; i < ev.size(); ) {
  		int nowb1 = ev[i].b1;
  		if(nowb1 > lstb1) {
  			auto all = seg.all_prod();
  			if(all.fi > ans) {
  				ans = all.fi;
  				bb1 = lstb1;
  				bb2 = all.se;
  			}
  		}
  		size_t j = i;
  		while(j < ev.size() && ev[j].b1 == nowb1) {
  			auto &tt = ev[j];
  			int l = tt.b2l - 1, r = tt.b2r - 1;
  			if(l <= r)
  				seg.apply(l, r + 1, tt.add);
  			j ++;
  		}
  		auto all = seg.all_prod();
  		if(all.fi > ans) {
  			ans = all.fi;
  			bb1 = nowb1;
  			bb2 = all.se;
  		}
  		i = j;
  		lstb1 = nowb1;
  	}
  	cout << ans << endl;
  	cout << bb1 << ' ' << bb2 << endl;
return;};
}

#undef cin
signed main (){
    //FASTioMAGIC;
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