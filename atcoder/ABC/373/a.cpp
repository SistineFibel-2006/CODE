#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
	string s;
	int ans = 0;
	for(int i = 1; i <= 12; i ++){
		cin >> s;
		if(s.length() == i)
			ans ++;
	}

	cout << ans << endl;


}

void solve(){

}