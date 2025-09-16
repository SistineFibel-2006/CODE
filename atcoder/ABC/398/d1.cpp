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
	if(n % 2) {
		for(int i = 0; i < n / 2; i ++)
			cout << '-';
		cout << "=";
		for(int i = 0; i < n / 2; i ++)
			cout << '-';		
	}
	else {
		for(int i = 0; i < n / 2 - 1; i ++)
			cout << '-';
		cout << "==";
		for(int i = 0; i < n / 2 - 1; i ++)
			cout << '-';
	}
}