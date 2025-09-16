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
	int t;
	cin >> t;
	while(t--)
		solve();	

	return 0;
}

void solve(){
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;

	int d1 = (int)(n / (a + b + c)) * 3;
	int d2 = n % (a + b + c);

	if(d2 == 0)
		cout << d1 << endl;
	else if(d2 <= a)
		cout << d1 + 1 << endl;
	else if(d2 <= a + b)
		cout << d1 + 2 << endl;
	else
		cout << d1 + 3 << endl;

}