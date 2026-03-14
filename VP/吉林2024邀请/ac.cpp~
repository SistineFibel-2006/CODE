#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;


void solve() {
    string s; cin >> s;
    int cnt = 0;
    for(auto c : s) if(c == '1') cnt ++;
    vector<int> fib(1e7+10, 1);
    for(int i = 3; i <= 1e7; i++) {
	fib[i] = (fib[i - 1] + fib[i - 2]) % (mod);
    }
    cout << fib[cnt];
}

signed main() {
    int t = 1;
    //cin >> t;
    while(t --) solve();
}
