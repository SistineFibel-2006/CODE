
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);

//     int T;
//     cin >> T;
//     while (T--) {
//         int n, m;
//         cin >> n >> m;

//         int max1 = INT_MIN, min1 = INT_MAX;
//         int max2 = INT_MIN, min2 = INT_MAX;

//         for (int i = 0; i < n; ++i) {
//             int x, y;
//             cin >> x >> y;
//             int s = x + y;
//             int d = x - y;

//             if (s > max1) max1 = s;
//             if (s < min1) min1 = s;
//             if (d > max2) max2 = d;
//             if (d < min2) min2 = d;
//         }

//         int ans = INT_MAX;

//         for (int j = 0; j < m; ++j) {
//             int a, b;
//             cin >> a >> b;
//             int s_ab = a + b;
//             int d_ab = a - b;

//             int v1 = s_ab - min1;
//             int v2 = max1 - s_ab;
//             int v3 = d_ab - min2;
//             int v4 = max2 - d_ab;

//             int nowm = max(max(v1, v2), max(v3, v4));

//             if (nowm < ans) {
//                 ans = nowm;
//             }
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
const int maxn = 1e7;
#define endl '\n'
int n,m;
string a;
int f[maxn][10];


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
    cin>>n>>m;
    int ans=0;
    for(int i=1,ok=1,charac=0;i<=n;++i){
        string s;cin>>s;
        if(ok && charac+s.size() <= m) ans ++,charac+=s.size();
        else ok=0;
    }
    cout<<ans<<'\n';
}
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// const int MOD = 998244353;

// vector<int> gb(int x) {
//     vector<int> v;
//     if (!x) return {0};
//     while(x) v.push_back(x%2), x/=2;
//     reverse(v.begin(),v.end());
//     return v;
// }

// int qpow(int e) {
//     if (!e) return 1;
//     int r=1,b=2;
//     while(e) {
//         if(e&1) r=r*b%MOD;
//         b=b*b%MOD;
//         e>>=1;
//     }
//     return r;
// }

// int calc(int a, int L) {
//     if(L >= a) return qpow(__builtin_popcountll(a));
    
//     auto a_b=gb(a), l_b=gb(L);
//     int ml=max(a_b.size(), l_b.size());
//     while(a_b.size()<ml) a_b.insert(a_b.begin(),0);
//     while(l_b.size()<ml) l_b.insert(l_b.begin(),0);
    
//     int t=1, nt=0;
//     for(int i=0;i<ml;++i) {
//         int ab=a_b[i], lb=l_b[i];
//         int new_t=0, new_nt=0;
        
//         if(!ab) {
//             lb ? new_nt+=t : new_t+=t;
//         } else {
//             new_nt += t;
//             if(lb) new_t += t;
//         }
        
//         new_nt = (new_nt + nt*(ab+1)) % MOD;
//         t = new_t % MOD;
//         nt = new_nt % MOD;
//     }
//     return (t + nt) % MOD;
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     int T; cin>>T;
//     while(T--) {
//         int n; cin>>n;
//         vector<int> a(n), L(n);
//         for(auto &x:a) cin>>x;
//         for(auto &x:L) cin>>x;
        
//         int ans=1;
//         for(int i=0;i<n;++i) 
//             ans = ans * calc(a[i], L[i]) % MOD;
//         cout<<ans<<'\n';
//     }
//     return 0;
// }