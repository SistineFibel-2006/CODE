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
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i] * 2;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	// for(auto c : a)
	// 	cerr << c << ' ';
	// cerr <<endl;
	// for(auto c : b)
	// 	cerr << c << ' ';
	// cerr <<endl;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j ++){
			auto x = lower_bound(b.begin(), b.end(), a[i] + a[j]) - b.begin();
			if(b[x] == a[i] + a[j]){
				cnt ++;
				// cerr << "Ok " << a[i] << ' ' << a[j] <<endl;
			}
		}
	}

	cout << cnt << endl;


}

void solve(){

}