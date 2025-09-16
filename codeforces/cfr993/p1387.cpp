#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
void solve();

int arr[110][110],a,b;
i64 dp[110][110];
int ans = 0;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	cin >> a >> b;
	for(int i = 1; i <= a; i ++)
		for(int j = 1; j <= b; j ++){
			cin >> arr[i][j];
			if(arr[i][j])
				dp[i][j] = min(min(dp[i][j - 1],dp[i - 1][j]),dp[i - 1][j - 1]) + 1;
			if(dp[i][j] > ans)
				ans = dp[i][j];
		}
	cout << ans << endl;
	return 0;
}

void solve(){

}