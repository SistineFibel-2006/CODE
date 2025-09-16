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
	i64 x, y;
	cin >> x >> y;

	if(x % 2 == 1){
		if(y % 4 == 3){
			cout << "YES" << endl;
			return;
		}
		cout << "NO" << endl;
	}
	else if(x % 2 == 0){
		if(y % 4 == 1 || y == 1){
			cout << "YES" << endl;
			return;
		}
		cout << "NO" << endl;
	}
}