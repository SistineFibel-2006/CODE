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
	int n;
	cin >> n;
	map<int, int> a;
	for(int i = 0, x, y; i < n - 1; i ++){
		cin >> x >> y;
		a[x] ++;
		a[y] ++;
	}
	int c = 0, d = 0;
	int cnt = 0;
	for(auto i = a.begin(); i != a.end(); i ++) {
		if(i->second % 2 == 1){
			if(c == 0){
				c = i->first;
				cnt ++;
			}
			else if(d == 0){
				d = i->first;
				cnt ++;				
			}
			else{
				cnt ++;
			}
		}
		// cerr << i->first << "  " << i->second <<endl;
	}
	// cerr << cnt << endl;
	if(cnt != 2)
		cout << "-1" << endl;
	else{
		cout << c << ' ' << d << endl;
	}
}

void solve(){

}