#include <bits/stdc++.h>
using namespace std;
#define int long long
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
	while(t --)
		solve();
}

void solve() {
	int n;
	string a;
	cin >> n >> a;
	int cnt = 0;
	for(auto c : a)
		if(c == '-')
			cnt ++;

	cout << (cnt / 2) * (cnt - cnt / 2) * (n - cnt) << endl;
}