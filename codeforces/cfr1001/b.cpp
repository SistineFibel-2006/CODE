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

	int t;
	cin >> t;
	while(t--)
		solve();



}

void solve(){

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	for(int i = 1; i <= n; i ++)
		if(a[i] - 2 * max((n - i), i - 1) <= 0){
			// cerr << i << " " << max((n - i), i - 1) << endl;
			cout << "NO" << endl;
			return;
		}

	cout << "YES" << endl;

}