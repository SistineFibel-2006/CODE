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
	
	int n;
	cin >> n;
	vector<int > a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	i64 ans = 0;
	int point = 0;
	for(auto c : a) {
		int lastt = upper_bound(a.begin(), a.end(),	2 * c) - a.begin();
		ans += (lastt - point++);
	}
	cout << ans << endl;
	return 0;

}

void solve(){

}