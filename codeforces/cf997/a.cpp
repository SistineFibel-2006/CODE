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



}

void solve(){
	int n;
	int m;
	cin >> n >> m;
	int x, y;
	i64 ans = 4 * m;
	// if(n == 1){
	// 	cin >> x >> y; 
	// 	cout << 4 * m << endl;
	// 	return;
	// }
	cin >> x >> y;
	n--;
	while(n --){
		cin >> x >> y;
		ans += (4 * m - 2 * (m - x) - 2 * (m - y));
	}
	cout << ans << endl;
}