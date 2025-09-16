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
	int x;
	int a[] = {1,2,3,5,6};
	int cnt = 0;
	for(int i = 1; i <= 7; i ++) {
		cin >> x;
		if(x==1 || x== 2|| x== 3 || x == 5 || x== 6)
			cnt ++;
	}
	if(cnt == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;



}

void solve(){

}