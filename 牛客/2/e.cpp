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

	int n, q;
	cin >> n >> q;
	vector<i64 > a(n + 1);
	vector<i64 > f(n + 1, 0);

	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}

	// for(auto c : a)
	// 	cerr << c << ' ';
	// cerr << endl;
	// for(auto c : f)
	// 	cerr << c << ' ';
	// cerr << endl;


	int l, r;
	// i64 ans = 0;
	// i64 temp = 0;
	while(q--) {
		i64 ans = 0;
		i64 temp = 0;
		cin >> l >> r;
		for(int i = l; i < r; i ++){
			temp += a[i];
			if(temp < a[i + 1]){
				// cerr << "ok" << " ";
				// cerr << a[i + 1] - temp <<	endl;
				ans += (a[i + 1] - temp);
				temp += (a[i + 1] - temp);

				// cerr << temp << " " << ans << endl;
			}
		}
		cout << ans << endl;
	}

}

void solve(){

}