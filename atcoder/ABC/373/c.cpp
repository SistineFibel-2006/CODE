#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const i64 inf = 1e12;

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int n;
	cin >> n;
	i64 maxa = -inf;
	i64 maxb = -inf;
	for(int i = 0, x; i < n; i ++){
		cin >> x;
		maxa = max((i64)x, maxa);
	}
	for(int i = 0, x; i < n; i ++){
		cin >> x;
		maxb = max((i64)x, maxb);
	}
	cout << maxa + maxb << endl;

}

void solve(){

}