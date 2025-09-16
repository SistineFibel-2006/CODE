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
	string a;
	cin >> a;
	int cnt = 0;
	int n = a.size();
	// vector <int > fa, fb, fc;
	// for(int i = 0; i < a.length(); i ++) {
	// 	if(a[i] == 'A')
	// 		fa.push_back(i);
	// 	if(a[i] == 'B')
	// 		fb.push_back(i);
	// 	if(a[i] == 'C')
	// 		fc.push_back(i);
	// }
	// for(auto c : fa)
	// 	cerr << c;
	// cerr << endl;
	// for(auto c : fb)
	// 	cerr << c;
	// cerr << endl;
	// for(auto c : fc)
	// 	cerr << c;
	// cerr << endl;
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			for(int k = j + 1; k < n; k ++)
				if(j - i == k - j && a[i] == 'A' && a[j] == 'B' && a[k] == 'C')
					cnt ++;


	cout << cnt;
}

void solve(){

}