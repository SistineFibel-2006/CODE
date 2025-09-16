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
	u64 k;
	cin >> n >> k;
	k = k ^ (k >> 1);
	while(n--) cout << (k >> n & 1);

	return 0;
}

void solve(){

}