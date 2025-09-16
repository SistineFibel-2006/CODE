#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

struct node {
	int v = 0;
	int b = 0;
};

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}

void solve(){
	int n;
	cin >> n;
	string s;
	node a[n];
	for(int i = 0; i < n; i ++){
		cin >> s;
		a[i].b = i + 1;
		for(auto c : s)
			if(c == '0')
				a[i].v ++;
		// cout << a[i].v << endl;
	}

	sort(a, a + n,
		[&](node x, node y){
			if(x.v != y.v)
				return x.v < y.v;
			else
				return x.b < x.b;
		});

	// for(int i = 0; i < n; i ++) {
	// 	cerr << ".b :" << a[i].b << " " << ".v :" << a[i].v << endl;
	// }


	for(int i = n - 1; i >= 0; i --)
		cout << a[i].b << " ";

 	cout << endl;
}