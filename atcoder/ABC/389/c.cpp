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

	// int t;
	// cin >> t;
	// // deque <pair<int, int>> q;
	// int x, y;
	// int lst = 0;
	// int hd = 0;
	// int cntk = 0;
	// int cnt = 0;
	// vector<int > a,b;
	// while(t --) {
	// 	cin >> x;
	// 	if(x == 1){
	// 		cin >> y;
	// 		// if(a.empty()){
	// 		// 	a.push_back({0, y});
	// 		// 	hd ++;
	// 		// 	lst = y;
	// 		// }
	// 		// else {
	// 			a.push_back(lst);
	// 			lst += y;
	// 			// b.push_back(lst);
	// 			// cntk ++;
	// 		// }
	// 	}
	// 	else if(x == 2){ 
	// 		// hd = b[cnt];
	// 		cnt ++ ;
	// 	}
	// 	else {
	// 		cin >> y;
	// 		cout << a[y - 1 + cnt] - a[cnt] << endl;
	// 	}
	// }


	int t;
	cin >> t;
	i64 a[t + 1] = {0};
	i64 x, y;
	i64 hd = 0, cnt = 1;

	while(t --){
		cin >> x;
		if(x == 1) {
			cin >> y;
			a[cnt] = a[cnt - 1] + y;
			cnt ++;
		}
		else if(x == 2) {
			hd ++;
		}
		else {
			cin >> y;
			// cerr << "a[" << hd << "]:" <<a[hd] <<endl;
			cout << a[y + hd - 1] - a[hd] << endl;
		}
	}


}

void solve(){

}