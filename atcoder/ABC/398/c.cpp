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
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n;
	cin >> n;
	vector<int > a(n);
	map<int, int> b;
	int ans = -1;
	int t = 1;
	for(auto &c : a){
		cin >> c;
		b[c] ++;
		if(b[c] == 1)
			ans = t;
		t ++;
	}
	int ans1 = -1;
	for(auto it : b)
		if(it.second == 1)
			ans1 = 1;
	if(ans1 == 1)
		cout << ans << endl;
	else
		cout << "-1";
}