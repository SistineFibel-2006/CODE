#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();



}

void solve(){
        i64 n, t, k;
        cin >> n >> t >> k;
        i64 m = n - k;
        if (m <= 0) {
            cout << "0\n";
            return;
        }
        i64 s1 = m / t;
        i64 s2 = k + 1;
        cout << min(s1, s2) << endl;
}