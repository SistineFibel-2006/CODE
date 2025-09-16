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

	int n;
	while(cin >> n && n != 0){
		vector<int> a(n);
		for(int i = 0; i < n; i ++)
			cin >> a[i];
		sort(a.begin(),a.end(),
			[&](int a, int b){
			return abs(a) > abs(b);
			});
		for(auto c : a){
			cout << c << ' ';
		}
		cout << '\n';
	}



}

void solve(){

}