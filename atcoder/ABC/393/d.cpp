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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 0;
	for(auto c : s)
		if(c == '1')
			cnt ++;
	int p = 0;
	i64 ans = 0;
	for(auto c : s)
		if(c == '0')
			ans += minmax(p, cnt - p).first;
		else
			p ++;


	cout << ans << endl;




}

void solve(){

}