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
	int n, k;
	cin >> n >> k;
	i64 a[5000];
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	i64 ans = 0;
	if(k == 1)
	{
		for(int i = 1; i < n; i ++)
			ans = max(ans, a[i] + a[0]);
		for(int i = 0; i < n - 1; i ++)
			ans = max(ans, a[i] + a[n - 1]);
		cout << ans << '\n';
		return;
	}
	sort(a, a + n);
	ans=0;
	for(int i = n - k - 1; i < n; i ++)
		ans += a[i];
	cout<<ans<<'\n';	
}