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
	while(t --)
		solve();

	return 0;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k; 
	vector<int > a(m),q(k);
	for(auto &x : a)
		cin >> x;
	for(auto &x : q)
		cin >> x;


	if(k == n){
		for(int i = 0; i < m; i ++)
			cout << "1";
		cout << endl;
		return;
	}
	else if(k <= n - 2){
		for(int i = 0; i < m; i ++)
			cout << "0";
		cout << endl;
		return;
	}

	int p = 1;
	for(auto c : q){
		if(c != p++)
			break;
	}
	p--;

	for(int i = 1; i <= m; i ++)
		if(i != p)
			cout << "0";
		else
			cout << "1";

	cout << endl;

}