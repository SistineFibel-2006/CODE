#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();


const int N = 1e9+1;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

void solve(){
	int n, k;
	cin >> n >> k;
	map<int , int > ap;
	int cnt1 = 0;
	int cnt = 0;
	for(int i = 0, a; i < n; i ++) {
		cin >> a;
		ap[a] ++;
	}
	
	int arr[sizeof(ap) + 1];
	int i = 0;
	for(auto c = ap.begin(); c != ap.end(); c ++) {
		arr[i++] = c->second;
	}
	sort(arr, arr + sizeof(ap) + 2);
	cnt = i;
	for(int i = 0; i < cnt - 1; i ++){
		if(k >= arr[i]){
			cnt1 ++;
			k -= arr[i];
		}
	}

	cout << cnt - cnt1 << endl;
}