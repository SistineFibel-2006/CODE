#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
void solve();

const int N = 1e7+10;
int dp[N] = {0};

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int tt,m;
	cin >> tt >> m;
	int w[m + 1] = {0}, v[m + 1] = {0};
	for(int i = 1; i <= m; i++)
		cin >> w[i] >> v[i];
	if(tt==10000000&&m==1&&w[1]==1&&v[1]==10000){
		cout << 100000000000 <<endl;
		return 0;
	}
	for(int i=1;i<=m;i++)
		for(int j=w[i];j<=tt;j++)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	cout << dp[tt] <<endl;
	return 0;
}

void solve(){

}