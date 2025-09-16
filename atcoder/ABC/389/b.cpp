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

	u64 n;
	cin >> n;

	u64 x = 1;
	u64 i;
	for(i = 2; x != n; i ++)
		x *= i;

	cout << i - 1 << endl;

}

void solve(){

}