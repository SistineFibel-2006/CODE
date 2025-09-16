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

	int n, m;
	cin >> n >> m;
	int a[n + 1] = {0};
	int x;
	char y;
	while(m--){
		cin >> x >> y;
		if(a[x] == 0 && y == 'M'){
			cout << "Yes" << endl;
			a[x] = 1;
		}
		else
			cout << "No" << endl;

	}



}

void solve(){

}