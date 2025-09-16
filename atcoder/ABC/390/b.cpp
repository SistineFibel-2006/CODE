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

	int t;
	cin >> t;
	std::vector<int > a(t);

	for(auto &c : a)
		cin >> c;

	// for(auto c : a)
	// 	cerr << c << " ";

	// cout << endl;

	for(int i = 0; i <= t - 3; i ++){
		if((long double)(a[i + 1] / a[i]) == (long double)(a[i + 2] / a[i + 1]))
			continue;
		else{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;



}

void solve(){

}