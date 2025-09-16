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
	
	int n, d;
	cin >> n >> d;
	vector<int > l(n);
	vector<int > t(n);
	for(int i = 0, c; i < n; i ++)
		cin >> l[i] >> t[i];

	for(int k = 1,ans; k <= d; k ++) {
		ans = 0;
		for(int i = 0; i < n; i ++)
			ans = max(ans, l[i] * (t[i] + k));
		cout << ans << endl;
	}


	return 0;
}

void solve(){

}