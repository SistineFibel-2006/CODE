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
	while(t--)
		solve();



}

void solve(){

	i64 a,b,c,d;
	cin >> a >> b >> c >> d;

	int z = b - a;
	int h = d - c;

	if(z > h){
		cout << b << ' ' << d << endl;
		cout << b - 1 << ' ' << d << endl;
		cout << a << ' ' << d - 1 << endl;
	}
	else {
		cout << b << ' ' << d << endl;
		cout << b << ' ' << d - 1 << endl;
		cout << b - 1 << ' ' << c << endl;
	}
}