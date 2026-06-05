#include <cstring>
#if defined(__GNUC__)
#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;
// #include "atcoder/all"
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

} 
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




}
using namespace atcoder;

bool switchdebug = 0;

namespace SistineFibel{
    // #define all(x) (x).begin(),(x).end()
    #define return(statement) return (statement),void();
    // bool YON(bool a,bool upp=false){if(a){std::cout<<(upp?"YES\n":"Yes\n");}else{std::cout<<(upp?"NO\n":"No\n");}return a;}
    using I = int;
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    using Int = long long;
    using ll = long long;
    using ld = long double;
    using ull = unsigned long long;
    using uint = unsigned;
    using pii = pair<int, int>;
    using pll = pair<ll, ll>;
    using pdd = pair<ld, ld>;
    using tuplis = array<ll, 3>;
    template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
    const ll LINF=0x1fffffffffffffff;
    const ll MINF=0x7fffffffffff;
    const int INF=0x3fffffff;
    const int MOD=1000000007;
    const int MODD=998244353;
    const ld DINF=INFINITY;
    const ld PI=3.14159265358979323846;
    const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
    const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
    #define overload5(a,b,c,d,e,name,...) name
    #define overload4(a,b,c,d,name,...) name
    #define overload3(a,b,c,name,...) name
    #define rep1(n) rep2(_,n)
    #define rep2(i,n) rep3(i,0,n)
    #define rep3(i,a,b) for(ll i=a;i<(b);i++)
    #define rep4(i,a,b,c) for(ll i=a;i<(b);i+=(c))
    #define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
    #define rrep1(n) rrep2(_,n)
    #define rrep2(i,n) for(ll i=n;i--;)
    #define rrep3(i,a,b) for(ll i=b;i-->(a);)
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
    #define each1(i,a) for(auto&&i:a)
    #define each2(x,y,a) for(auto&&[x,y]:a)
    #define each3(x,y,z,a) for(auto&&[x,y,z]:a)
    #define each4(w,x,y,z,a) for(auto&&[w,x,y,z]:a)
    #define each(...) overload5(__VA_ARGS__,each4,each3,each2,each1)(__VA_ARGS__)
    #define all1(i) begin(i),end(i)
    #define all2(i,a) begin(i),begin(i)+a
    #define all3(i,a,b) begin(i)+a,begin(i)+b
    #define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
    #define rall1(i) rbegin(i),rend(i)
    #define rall2(i,a) rbegin(i),rbegin(i)+a
    #define rall3(i,a,b) rbegin(i)+a,rbegin(i)+b
    #define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
    #define sum(...) accumulate(all(__VA_ARGS__),0LL)
    #define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
    #define Msum(...) accumulate(all(__VA_ARGS__),mint{})
    #define elif else if
    #define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
    #define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
    #define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
    #define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
    #define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
    #define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
    #define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
    #define vec(type,name,...) vector<type>name(__VA_ARGS__)
    #define arr(type,name,size) array<type,size>name
    #define VEC(type,name,size) vector<type>name(size);in(name)
    #define ARR(type,name,size) array<type,size>name;in(name)
    #define vv(type,name,h,...) vector name(h,vector<type>(__VA_ARGS__))
    #define VV(type,name,h,w) vector name(h,vector<type>(w));in(name)
    #define vvv(type,name,h,w,...) vector name(h,vector(w,vector<type>(__VA_ARGS__)))    

    template<class T> ll sz(const T& a){ return size(a); }
    template<class T, class U> ll count(const T& a, const U& b){ return count(all(a), b); }
    template<class T, class F> ll count_if(const T& a, F b){ return count_if(all(a), b); }
    template<class T, class F> void filter(T& a, F b){ a.erase(remove_if(all(a), not_fn(b)), a.end()); }
    template<class T, class F = less<>> void sor(T& a, F b = F{}){ sort(all(a), b); }
    template<class T> void rev(T& a){ reverse(all(a)); }
    template<class T> void uniq(T& a){ sor(a); a.erase(unique(all(a)), end(a)); }
    ll popcnt(ull a){ return __builtin_popcountll(a); }
    ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
    ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
    template<class T> T div_floor(T a, T b) { return a / b - ((a ^ b) < 0 && a % b); }
    template<class T> T div_ceil(T a, T b) { return a / b + ((a ^ b) > 0 && a % b); }
    template<class T> bool chmin(T& a, const T& b){ return a > b ? a = b, 1 : 0; }
    template<class T> bool chmax(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
    template<class T, class U> bool chmin(T& a, const U& b){ return a > b ? a = b, 1 : 0; }
    template<class T, class U> bool chmax(T& a, const U& b){ return a < b ? a = b, 1 : 0; }
    vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
    vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
    vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(i, ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
    template<class T> unordered_map<T, ll> press(vector<T> a){ uniq(a); unordered_map<T, ll> ans; rep(i, a.size()) ans[a[i]] = i; return ans; }
    template<class T> auto run_press(const T& a){ vector<pair<decay_t<decltype(a[0])>, ll>> ans; each(x, a){ if(ans.empty() || ans.back().first != x) ans.emplace_back(x, 1); else ans.back().second++; } return ans; }
    
    template<class... Ts> void in(Ts&... t);
    [[maybe_unused]] void print(){}
    template<class T, class... Ts> void print(const T& t, const Ts&... ts);
    template<class... Ts> void out(const Ts&... ts){ print(ts...); cout << '\n'; }
    namespace IO{
        #define VOID(a) decltype(void(a))
        struct S{ S(){ cin.tie(nullptr)->sync_with_stdio(0); fixed(cout).precision(12); } }S;
        template<int I> struct P : P<I-1>{};
        template<> struct P<0>{};
        template<class T> void i(T& t){ i(t, P<3>{}); }
        void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
        template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
        template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
        template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){ in(get<idx>(t)...); }
        template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){ ituple(t, make_index_sequence<tuple_size<T>::value>{}); }
        template<class T> void o(const T& t){ o(t, P<4>{}); }
        template<size_t N> void o(const char (&t)[N], P<4>){ cout << t; }
        template<class T, size_t N> void o(const T (&t)[N], P<3>){ o(t[0]); for(size_t i = 1; i < N; i++){ o(' '); o(t[i]); } }
        template<class T> auto o(const T& t, P<2>) -> VOID(cout << t){ cout << t; }
        template<class T> auto o(const T& t, P<1>) -> VOID(begin(t)){ bool first = 1; for(auto&& x : t) { if(first) first = 0; else o(' '); o(x); } }
        template<class T, size_t... idx> void otuple(const T& t, index_sequence<idx...>){ print(get<idx>(t)...); }
        template<class T> auto o(T& t, P<0>) -> VOID(tuple_size<T>{}){ otuple(t, make_index_sequence<tuple_size<T>::value>{}); }
        #undef VOID
    }
    template<class... Ts> void in(Ts&... t){ (IO::i(t), ...); }
    template<class T, class... Ts> void print(const T& t, const Ts&... ts){ IO::o(t); (IO::o((cout << ' ', ts)), ...); }
    #undef unpack
    constexpr ll debug_const(ll judge, ll debug) {
    #ifdef DEBUG
        return debug;
    #else
        return judge;
    #endif
    }
    #ifdef DEBUG
    ll __lg(ull x){ return 63 - __builtin_clzll(x); }
    #define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
    #else
    #define debug(...) void(0)
    #endif
    
    template<class T>
    using v = vector<T>; 
    template<class T, std::size_t N>
    using a = array<T, N>;
    template <typename T>
    T pop(deque<T> &que) {
      T a = que.front();
      que.pop_front();
      return a;
    }
    template <class T, class Container, class Compare>
    T pop(priority_queue<T, Container, Compare> &que) {
      T a = que.top();
      que.pop();
      return a;
    }
    template <typename T>
    T pop(v<T> &que) {
      T a = que.back();
      que.pop_back();
      return a;
    }
    template <typename T>
    T pop(stack<T> &que) {
      T a = que.top();
      que.pop();
      return a;
    }
    #define YESNO(yes,no) void yes(bool i = 1){ out(i?#yes:#no); } void no(){ out(#no); }
    YESNO(first, second)
    YESNO(First, Second)
    YESNO(Yes, No)
    YESNO(YES, NO)
    YESNO(possible, impossible)
    YESNO(Possible, Impossible)
    YESNO(POSSIBLE, IMPOSSIBLE)

    template <typename F>
    ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
      if (check_ok) assert(check(ok));
      while (llabs(ok - ng) > 1) {
        auto x = (ng + ok) / 2;
        (check(x) ? ok : ng) = x;
      }
      return ok;
    }
    template <typename F>
    double binary_search_real(F check, double ok, double ng, int iter = 100) {
      rep(iter) {
        double x = (ok + ng) / 2;
        (check(x) ? ok : ng) = x;
      }
      double ans = (ok + ng) / 2;
      return ans;
    }
    template <typename T, typename U>
    v<T> cumsum(const v<U> &A, int off = 1) {
      int N = A.size();
      v<T> B(N + 1);
      rep(i, N) { B[i + 1] = B[i] + A[i]; }
      if (off == 0) B.erase(B.begin());
      return B;
    }

    #ifndef DEBUG 
      #define assert(x) (void(0))
    #endif 

} //NAMESPCACE SistineFibel
using namespace SistineFibel;
#define defiM void init();void Mainsol()
#define pb push_back
#define fi first
#define se second
#define is insert
#define dbg debug
#define as(...) assert(__VA_ARGS__)
#define el '\n'


struct RuntimeClock{std::chrono::high_resolution_clock::time_point s;RuntimeClock(){s=std::chrono::high_resolution_clock::now();}~RuntimeClock(){cerr<<"[Time] "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-s).count()<<" ms\n";}};

int32_t main(signed argc, char * argv[]){
    //RuntimeClock _;
    if(argc > 1 && strcmp(argv[1], "D") == 0) switchdebug = 1;
    defiM;
    if(switchdebug) {
      while(1) {
        init(), Mainsol();
        cout.flush();
      }
    } else {
      int t = 1;
      in(t);  //atc默认关闭，cf按需开启
      while(t --) {
        init(), Mainsol();
      }
    }
    return 0;
}


 	const int mod = MODD;
  const ll INV2 = modpow(2, MODD-2, MODD);

  struct S {
    ll sum, sum2;
    ll len;
  };

  S op(S a, S b) {return{
    (a.sum + b.sum) % mod,
    (a.sum2 + b.sum2) % mod,
    a.len + b.len
  };}

  S e() {return{0,0,0};}

  using F = ll;

  S mapping(F f, S x) {
    if(f == 0) return x;
    ll v = f % mod;
    ll ss = (x.sum + v * x.len) % mod;
    ll ss2 = (x.sum2 + 2 * v % mod * x.sum % mod + v * v % mod * x.len) % mod;
    return {ss, ss2, x.len};
  }

  F comp(F f, F g) {
    F ans = (f + g) % mod;
    return ans;
  }

  F id() {return 0;}


void Mainsol() {
	INT(N, Q);
	v<S> init(N);
	rep(i, N) {
		INT(X);
		init[i] = {X % mod, (ll)X * X % mod, 1};
	}
	atcoder::lazy_segtree<S, op, e, F, mapping, comp, id> seg(init);

	rep(Q) {
		INT(op);
		if(op == 1) {
			INT(l, r, d); l --;
			seg.apply(l, r, d % mod);
		} else {
			INT(l, r);
			l --;
			auto [x, y, _] = seg.prod(l, r);
			ll ans = ((x * x % mod - y + mod) % mod) * INV2 % mod;
			out(ans);
		}
	}

}

void init() {

}

//test
/*

*/

//============================================================================//
//==                        SISTINE_FIBEL  システィーナ=フィーベル            ==//
//============================================================================//