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
	while(t --)
		solve();




}

void solve(){
	int n;
	cin >> n;
	if(n % 3 == 1)
		cout << "YES" <<endl;
	else
		cout << "NO" <<endl;
}