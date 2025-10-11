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


#define el '\n'

namespace sIsTiNeFiBeL {


  inline void Tempest_Flare__The_Wind_Splitting_Magic_Bullet() {
/**/INT(n, k);
  	I g = ceil(n * 0.1);
  	I s = g * 3;
  	I b = g * 6;
  	if(k <= g)
  		out("Gold Medal");
  	elif(k <= s)
  		out("Silver Medal");
  	elif(k <= b)
  		out("Bronze Medal");
  	else
  		out("Da Tie");

return;};
}

struct RuntimeClock{std::chrono::high_resolution_clock::time_point s;RuntimeClock(){s=std::chrono::high_resolution_clock::now();}~RuntimeClock(){cerr<<"[Time] "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-s).count()<<" ms\n";}};

signed main (){
    //FASTioMAGIC;
    RuntimeClock _;
    int t = 1;
    //in(t);  //atc默认关闭，cf按需开启
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
//==                        SISTINE_FIBEL  システィーナ=フィーベル            ==//
//============================================================================//