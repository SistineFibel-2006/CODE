#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const string f = "CHICKEN";

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
	string a;
	cin >> a;
	int p = 0;
	int cnt = n - 7;
	map<char, int> mp;
	for(auto c : a){
		mp[c] ++;
		if(c == f[p])
			p ++;
	}
	mp['C'] --;
	mp['H'] --;
	mp['I'] --;
	mp['C'] --;
	mp['K'] --;
	mp['E'] --;
	mp['N'] --;
	int maxx = 0;
	int maxc = 0;
	for(auto i : mp){
		// cerr << "1 " << i.first << " 2 " << i.second << endl;
		maxx += i.second;
		maxc = max(maxc, i.second);
	}
	// cerr << maxx << ' ' << maxc << endl;
	if(p == 7 && cnt % 2 == 0 && maxx % 2 == 0 && maxc <= (maxx - maxc))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}