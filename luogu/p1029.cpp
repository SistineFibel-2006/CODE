#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();

// i64 gcd(int a, int b){
// 	if(b == 0)
// 		return a;
// 	else
// 		return gcd(b, a % b);
// }

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	i64 n, m;
	cin >> n >> m;
	i64 a = n * m;
	int ans;
	for(int i = 1; i <= sqrt(a); i ++)
		if(__gcd(i, n / i) == m && n % i == 0)
			ans += 2;

	cout << ans;

	return 0;
}

void solve(){

}