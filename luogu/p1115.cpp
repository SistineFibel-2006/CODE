#include <bits/stdc++.h>
using namespace std;


using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'



void solve(){}

i64 ans = -21473647;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	// int n;
	// cin >> n;
	// int sum = 0;
	// int temp;
	// for (int i = 1; i <= n; i ++){
	// 	cin >> temp;
	// 	if(i == 1)
	// 		sum = temp;
	// 	else
	// 		sum = max(temp, temp + sum);
	// 	ans = (ans, sum);
	// }
	// cout << ans << endl;

	int n; cin >> n;
	int a;
	int dp = 0;
	while(n -- ){
		cin >> a;
		dp += a;
		ans = dp>ans?dp:ans;
		dp = dp<0? 0 : dp;
	} 
	cout << ans <<endl;
	return 0;
}