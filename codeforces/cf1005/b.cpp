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
	while(t --)
		solve();
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &c : a)
		cin >> c;

	unordered_map <int, int> cnt, fi, ls;

	for(int i = 0; i < n; i ++) {
		int x = a[i];
		if(!fi.count(x))
			fi[x] = i;
		ls[x] = i;
		cnt[x] ++;
	}

	if(cnt.size() == n){
		cout << "1 " << n << endl;
		return;
	}

	vector<int > only;
	for(auto i : cnt) {
		if(i.second == 1)
			only.push_back(fi[i.first] + 1);
	}
	sort(only.begin(),only.end());
	// for(auto c : only)
	// 	cerr << c << " ";
	// cerr << endl;
	int nans = 1;
	int ans = 0;
	int l = 0, r = 0, np = 0;
	for(int i = 1; i < only.size(); i ++){
		if(only[i] == only[i - 1] + 1)
			nans ++;
		else if(only[i] != only[i - 1] + 1){
			if(nans > ans) {
				ans = nans;
				l = np;
			}
			nans = 1;
			np = i;
		}
	}

	if(nans > ans) {
		ans = nans;
		l = np;
	}
	r = l + ans - 1;

	if(only.empty() == 0){
		cout << only[l] << " " << only[r] << endl;
	}
	else
		cout << "0\n";

}