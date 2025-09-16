#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int m = 1e9 + 7;

long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

signed main (){ 
    std::ios::sync_with_stdio(false);std::cin.tie(0);

    int t;
    cin >> t;
    while(t --)
        solve();



}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(auto c : s){
        if(c == '?')
            cnt ++;
    }
    if(n == 1){
        if(cnt == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return;
    }


    i64 xd = (binpow(2, cnt) * (n - 2)) % m;
    i64 bxd = (2 * binpow(2, cnt)) % m;
    i64 bxd2 = (2 * binpow(2, cnt - 1)) % m;
    i64 xd2 = (binpow(2, cnt - 1) * (n - 2)) % m;
    i64 bxd3 = (2 * binpow(2, cnt - 2)) % m;
    i64 xd3 = (binpow(2, cnt - 2) * (n - 2)) % m;

    if(s[0] != '?' && s[n - 1] != '?'){
        if(s[0] == s[n - 1]){
            cout << (binpow(2, cnt) * (n - 2)) % m << endl;
            return; 
        }
        if(s[0] != s[n - 1]){
            cout << (2 * binpow(2, cnt)) % m << endl;
        }
    }
    else if((s[0] == '?' && s[n - 1] != '?') || (s[0] != '?' && s[n - 1] == '?')){
        cout << (xd2 + bxd2) % m << endl;
        return;
    }
    else{
        cout << (2 * ((xd3 + bxd3) % m) % m) % m << endl;
    }
}

