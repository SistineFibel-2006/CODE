#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, x;
	cin >> n >> x;

	vector<int > l(n+1);
	vector<int > w(n+1);
	vector<int > u(n+1);

	vector<int > dp(n+10, 0);

	for(int i = 1; i <= n; i ++)
		cin >> l[i] >> w[i] >> u[i];

	for(int j = 1; j <= x; j ++){
			for(int i = x; i >= u[j]; i--){
			//	if(i >= w[j])
					dp[i] = max(dp[i] + l[j], dp[i - u[j]] + w[j]);
			//	else
			//		dp[i] += l[j];
			}
			for(int i = u[j] - 1; i >= 0; i --)
				dp[i] += l[j];
		}

	cout << dp[x] * 5 << endl;

	return 0;
}

void solve(){

}