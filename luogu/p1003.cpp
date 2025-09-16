#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'

const int N = 1e9;


signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n; cin >> n;

	vector<int > a(n);
	vector<int > b(n);
	vector<int > g(n);
	vector<int > k(n);

	for(int i = 0; i < n; i ++)
		cin >> a[i] >> b[i] >> g[i] >> k[i];

	int x, y;
	cin >> x >> y;
	int ans = -1;

	for(int i = 0; i <= n; i ++)
		if(a[i] + g[i] >= x && a[i] <= x && b[i] + k[i] >= y && b[i] <= y)
			ans = i + 1;

	// if(ans == 0) {
	// 	cout << "-1" << endl; 
	// 	return 0;
	// }

	cout << ans;

	return 0;
}
