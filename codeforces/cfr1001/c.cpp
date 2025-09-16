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

	int t;
	cin >> t;
	while(t--)
		solve();



}

void solve(){

	int n;
	cin >> n;
	vector<int > a(n);
	int flag = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] <= 0)
			flag = 1;
	}
	i64 sum = accumulate(a.begin(),a.end(),0);

	if(flag == 0){
		cout << sum << endl;
		return;
	}

	

}