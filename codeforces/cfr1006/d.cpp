#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'
// #define max(x, y) x>y?x:y


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
}

void solve(){
	int n;
	cin >> n;
	vector<int > a(n);
	for(auto &c : a)
		cin >> c;

	int l = 0, r = 0, p = 0;

	for(int i = 0 ; i < n ; i ++) {
		int x = 0, d = 0;
		for(int j = i; j < n; j ++){
			if(a[j] > a[i])
				d ++;
			else if(a[j] < a[i])
				x ++;

			if(x - d > p) {
				p = x - d;
				l = i, r = j;
			}
		}
	}

	cout << l + 1 << ' ' << r + 1 << endl;
}