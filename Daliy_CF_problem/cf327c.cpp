#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7; //模数

long long binpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}


signed main (){ 
    std::cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
    while(t --)
    solve();
}

void solve(){
    int k, ans = 0;
    string s;
    cin >> s >> k;
    for(int i = 0; i < s.length(); i ++) {
        if(s[i] == '0' || s[i] == '5') {
            int fi = binpow(2, i);
            int plus = (binpow(binpow(2, s.size()), k) + MOD - 1) % MOD;
            int mins = (binpow(2, s.size()) + MOD - 1) % MOD;
            int se = plus * binpow(mins, MOD - 2) % MOD;
            ans = (fi * se % MOD + ans) % MOD;
        }
    }
    cout << ans << '\n';
}
//test
/*
ඞ
// ٩ (◕‿◕�?) ۶
*/

