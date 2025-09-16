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

	int t;
	cin >> t;
	while(t--)
		solve();


	return 0;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int more = (int)(1e9 + 10), less = 0, b1;
	int flag = 0;
	for(int i = 0; i < n; i ++){
		cin >> b1;
		if(a[i] >= b1)
			more = min(more, a[i] - b1);
		else{
			less += (b1 - a[i]);
			flag += 1;
		}
	}

	if(flag > 1){
		cout << "NO" << endl;
		return;
	}

	if(more >= less)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}