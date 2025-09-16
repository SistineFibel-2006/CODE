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
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1, 0);
	for(int i = 1; i <= m; i ++)
		cin >> a[i];
	sort(a.begin() + 1,a.end());
	i64 ans = 0;

	for(int i = 1; i <= (n / 2); i ++) {
		i64 lft = a.begin() + m + 1 - lower_bound(a.begin() + 1, a.end(), i);
		i64 rht = a.begin() + m + 1 - lower_bound(a.begin() + 1, a.end(), n - i);
		if(i == n - i)
			ans += (lft - 1) * rht / 2;
		else
			ans += (lft - 1) * rht;
	}

	cout << ans * 2 << endl;
}