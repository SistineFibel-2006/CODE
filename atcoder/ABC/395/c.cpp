#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int& c : a)
		cin >> c;

	map<int, int> cnt;
	// for(auto c : a)
	// 	cnt[c] ++;

	int ans = 100000000;
	for(int i = 0; i < n; i++) {
		if(cnt.count(a[i])) {
			ans = min(i - cnt[a[i]] + 1, ans);
		}
		cnt[a[i]] = i;
	}

	if(ans == 100000000)
		cout << -1;
	else
		cout << ans;

}

void solve(){
	

}