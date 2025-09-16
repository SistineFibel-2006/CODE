#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	string a, b;
	cin >> a >> b;

	if(a[0] == 'f' && b[0] == 'f')
		cout << 4;
	else if(a[0] == 's' && b[0] == 's')
		cout << 1;
	else if(a[0] == 'f' && b[0] == 's')
		cout << 3;
	else
		cout << 2;




}

void solve(){

}