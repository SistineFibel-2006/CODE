#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子

#define endl '\n'
void solve();

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;

	i64 sum = 0;

	for(int i = 1; i <= n; i ++)
		sum += n/i;

	cout << sum;

	return 0;
}

void solve(){

}