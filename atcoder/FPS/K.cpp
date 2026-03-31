#include <bits/stdc++.h>
using namespace std;
//#include "atcoder/all"

namespace atcoder{}
using namespace atcoder;


namespace SistineFibel{
    // #define all(x) (x).begin(),(x).end()
    #define return(statement) return (statement),void();
    // bool YON(bool a,bool upp=false){if(a){std::cout<<(upp?"YES\n":"Yes\n");}else{std::cout<<(upp?"NO\n":"No\n");}return a;}
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
    #define VEC(type,name,size) vector<type>name(size);in(name)
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
    #define YESNO(yes,no) void yes(bool i = 1){ out(i?#yes:#no); } void no(){ out(#no); }
    YESNO(first, second)
    YESNO(First, Second)
    YESNO(Yes, No)
    YESNO(YES, NO)
    YESNO(possible, impossible)
    YESNO(Possible, Impossible)
    YESNO(POSSIBLE, IMPOSSIBLE)

    using I = int;
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;

    template<class T>
    using v = vector<T>;
} //NAMESPCACE SistineFibel
using namespace SistineFibel;

#define pb push_back
#define fi first
#define se second
#define is insert
#define dbg debug

const ll mod = 998244353;
struct mm {
   ll x;
   mm(ll x_ = 0) : x(x_ % mod) {
      if(x < 0) x += mod;
   }
   friend mm operator+(mm a, mm b) { return a.x + b.x; }
   friend mm operator-(mm a, mm b) { return a.x - b.x; }
   friend mm operator*(mm a, mm b) { return a.x * b.x; }
   friend mm operator/(mm a, mm b) { return a * b.inv(); }

   friend mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }
   friend mm& operator-=(mm& a, mm b) { return a = a.x - b.x; }
   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x; }
   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }
   mm inv() const { return pow(mod - 2); }
   mm pow(ll b) const {
      mm a = *this, c = 1;
      while(b) {
         if(b & 1) c *= a;
         a *= a;
         b >>= 1;
      }
      return c;
   }
};

// modint を u32 にして加減算を真面目にやると速い
mm g = 3;  // 原始根
void fft(vector<mm>& a) {
   ll n = sz(a), lg = __lg(n);
   static auto z = [] {
      vector<mm> z(30);
      mm s = 1;
      rep(i, 2, 32) {
         z[i - 2] = s * g.pow(mod >> i);
         s *= g.inv().pow(mod >> i);
      }
      return z;
   }();
   rep(l, 0, lg) {
      ll w = 1 << (lg - l - 1);
      mm s = 1;
      rep(k, 0, 1 << l) {
         ll o = k << (lg - l);
         rep(i, o, o + w) {
            mm x = a[i], y = a[i + w] * s;
            a[i] = x + y;
            a[i + w] = x - y;
         }
         s *= z[countr_zero<uint64_t>(~k)];
      }
   }
}
// コピペ
void ifft(vector<mm>& a) {
   ll n = sz(a), lg = __lg(n);
   static auto z = [] {
      vector<mm> z(30);
      mm s = 1;
      rep(i, 2, 32) {  // g を逆数に
         z[i - 2] = s * g.inv().pow(mod >> i);
         s *= g.pow(mod >> i);
      }
      return z;
   }();
   for(ll l = lg; l--;) {  // 逆順に
      ll w = 1 << (lg - l - 1);
      mm s = 1;
      rep(k, 0, 1 << l) {
         ll o = k << (lg - l);
         rep(i, o, o + w) {
            mm x = a[i], y = a[i + w];  // *s を下に移動
            a[i] = x + y;
            a[i + w] = (x - y) * s;
         }
         s *= z[countr_zero<uint64_t>(~k)];
      }
   }
}
vector<mm> conv(vector<mm> a, vector<mm> b) {
   if(a.empty() || b.empty()) return {};
   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);
   // if(min(sz(a), sz(b)) <= 60) 愚直に掛け算
   a.resize(n);
   b.resize(n);
   fft(a);
   fft(b);
   mm inv = mm(n).inv();
   rep(i, 0, n) a[i] *= b[i] * inv;
   ifft(a);
   a.resize(s);
   return a;
}

v<mm> polyinv(const v<mm> &A, int n) {
  assert(!empty(A) && A[0].x != 0);
  v<mm> B(1, A[0].inv());
  int nowl = 1;
  while(nowl < n) {
    nowl <<= 1;
    v<mm> aa(A.begin(), A.begin() + min((int)sz(A), (int)nowl));
    v<mm> ab = conv(aa, B);
    ab.resize(nowl);
    v<mm> abb(nowl);
    abb[0] = mm(2);
    rep(i, 0, nowl) {
      abb[i] = abb[i] - ab[i];
    }
    B = conv(B, abb);
    B.resize(nowl);
  }
  B.resize(n);
  return B;
}

struct Comb {
private:
    vector<mm> fact;
    vector<mm> invf;
public:
    Comb(int _n) {
        fact.resize(_n + 1);
        invf.resize(_n + 1);
        fact[0] = 1;
        rep(i, 1, _n + 1) fact[i] = fact[i - 1] * i;
        invf[_n] = fact[_n].inv();
        for(int i = _n; i > 0; i --) invf[i - 1] = invf[i] * i;
    }
    mm C(int n, int k) {
        if(k < 0 || k > n) return 0;
        return fact[n] * invf[k] * invf[n - k];
    }
};

#define el '\n'

namespace sIsTiNeFiBeL {

/*
  max != i <=> 
  1 2 3 4 5 6 7
  n n n n n n n 
  2 1 4 3 6 5 7
  y n y n y n n
  3 2 1 4 5 6 7
  y n n n n n n 
  3 1 4 5 6 2 7
  y y y y y n n
  4 2 3 5 1 6 7
  y y y y n n n
  3 1 4 5 2 7 6
  y y y y n y n
  2 4 1 3 7 6 5
  y y y n y y n
  permu => bad + bad + ... + bad
  permu => permu (s)
  P(x) = \sum_(n>=0) (n! x^n)
  唯一确定，拼接（无交并）
  1
  F(x)
  F^2 (x)
  F^k (x)
  F^N (x)
  1 + F(x) +  F(X)^2 + F(X) ^3 +.. + F(X) ^ INF = P(x) = \sum_(n>=0) (n! x^n)
  1 / (1 - F(x)) = P(x)
  F(x) = 1 - 1/P(x)
  [x^N] -P(x).inv()
*/
  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/INT(N);
    v<mm> G(N + 1);
    G[0] = 1;
    rep(i, 1, N + 1) G[i] = G[i - 1] * mm(i);
    v<mm> invG = polyinv(G, N + 1);
    out((mm(0) - invG[N]).x);

return;};
}

struct RuntimeClock{std::chrono::high_resolution_clock::time_point s;RuntimeClock(){s=std::chrono::high_resolution_clock::now();}~RuntimeClock(){cerr<<"[Time] "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-s).count()<<" ms\n";}};

signed main (){
    //FASTioMAGIC;
    RuntimeClock _;
    int t = 1;
    // in(t);  //atc默认关闭，cf按需开启
    while(t --)
        sIsTiNeFiBeL::Tempest_Flare__The_Wind_Splitting_Magic_Bullet();
    return 0;
}



//============================================================================//
//==                        SISTINE_FIBEL  システィーナ=フィーベル            ==//
//============================================================================//
