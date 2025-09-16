/*
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
	i64 a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	i64 more = d * e;
	if(d >= 2)
		more += d * (d - 1) / 2;

	i64 ans = a * b * c * more;

	cout << ans << endl;

}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/

