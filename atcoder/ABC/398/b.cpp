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
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n = 7;
	map<int, int> a;
	int cnt1 = 0,cnt2 = 0;
	int x;
	while(n --) {
		cin >> x;
		a[x] ++;
		if(a[x] == 2)
			cnt2 ++;
		if(a[x] == 3){
			cnt1 ++;
			cnt2 --;
		}
	} 
	if(cnt1 >= 1 && cnt2 >= 1 && a.size() != 1)
		cout << "Yes";
	else
		cout << "No";
}