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
	int n;
	cin >> n;
	int maxx = 0;
	int minn = 1e9;
	vector<int > a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] <= minn)
			minn = a[i];
		if(a[i] - minn > maxx) 
			maxx = a[i] - minn;
	}

	cout << maxx ;

	return 0;
}

void solve(){

}