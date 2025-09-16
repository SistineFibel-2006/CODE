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
	string s;
	cin >> s;
	i64 cnt = 0;
	for(auto c : s)
		if(c == '1')
			cnt++;
	cout << cnt << endl;
}