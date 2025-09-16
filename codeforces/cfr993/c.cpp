#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
void solve();

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}

void solve(){
	int m, a, b, c;
	int ans = 0;
	cin >> m >> a >> b >> c;
	int cnt = 2 * m;
	if(a > m) {
		ans += m;
		cnt -= m;
	}else{
		ans += a;
		cnt -= a;
	}
	if(b > m) {
		ans += m;
		cnt -= m;
	}else{
		ans += b;
		cnt -= b;
	}
	if(c > cnt) {
		ans += cnt;
	}else{
		ans += c;
	}
	cout << ans << endl;
}