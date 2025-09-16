#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


bool ifsq(int x){
	int t = sqrtl((x * (x + 1) / 2));
	if(t * t != x * (x + 1) / 2)
		return 1;
	else 
	 	return 0;
}

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t --)
		solve();
}

void solve() {
	int n;
	cin >> n;
	if(!ifsq(n)) {
		cout << "-1\n";
		return;
	}

	int a[n + 1];
	for(int i = 1; i <= n; i ++)
		a[i] = i;

	int tt = 0;
	for(int i = 1; i <= n; i ++){
		for(;tt * tt < i * (i + 1) / 2;)
			tt ++;
		if(tt * tt == i * (i + 1) / 2)
			swap(a[i], a[i + 1]);
		cout << a[i] << ' ';
	}
	cout << endl;
}