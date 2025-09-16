#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();


	return 0;
}

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	if((abs(b - a)) % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}