#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
#define endl '\n'

struct arr {
	int b, c;
};

bool cmp(arr a, arr b){
	return a.c < b.c;
}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;

	// arr a[n];
	// for(int i = 0; i < n; i ++){
	// 	cin >> a[i].c;
	// 	a[i].b = i + 1;
	// }
	// sort(a, a + n);
	// int tt;cin >> tt;
	// int x, y;

	// auto erf = [&](int x) -> int {
	// 	int l = a[0].c; int r = a[n - 1].c;

	// 	while(l + 1 < r) {
	// 		int mid = (l + r) / 2;
	// 		if(a[mid].c < x) 
	// 			l = mid;
	// 		else
	// 			r = mid;
	// 	}

	// 	return r;
	// };

	// while(tt--){
	// 	cin >> x;
	// 	int ans = erf(x);
	// 	if(a[ans].c == x)
	// 		cout << a[ans].b << endl;
	// 	else
	// 		cout << "0\n"; 
	// }

	map<int, int> a;
	for(int i = 1,x; i <= n; i ++){
		cin >> x;
		a[x] = i;
	}

	int t; cin >> t;
	int x;
	while(t--){
		cin >> x;
		cout << a[x] << endl;
	}

	return 0;
}


// CE unaccepted
