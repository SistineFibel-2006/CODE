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

	int a[6];
	for(int i = 1; i <= 5; i ++)
		cin >> a[i];


	int f = 0;
	for(int i = 1; i <= 5; i ++){
		if(a[i] == i)
			continue;
		else{
			if(a[i] == i + 1 && a[i + 1] == i){
				cout << "Yes" << endl;
				return 0;
			}
			else{
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

}

void solve(){

}