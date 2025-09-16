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

	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);

	if(a[0] * a[1] == a[2])
		cout << "Yes";
	else
		cout << "No";



}

void solve(){

}