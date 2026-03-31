#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	// int n,k;
	// cin >> n >> k;
	// int arr[k*2+10];
	// int total=0;
	// for(int i=0;i<k*2;i++){
	// 	cin >> arr[i];
	// 	total+=arr[i];
	// }
	// if(arr[0]!=n||arr[k*2-1]!=0||total!=n*k){
	// 	cout << "No" << endl;
	// 	return;
	// }
	// int now=0;
	// for(int i=0;i<k*2;i++){
	// 	now-=(n-arr[i]);
	// 	if(now<0){
	// 		cout << "No" << endl;
	// 		return;
	// 	}
	// 	now+=arr[i];
	// }
	// cout << "Yes" << endl;
	int n, k; cin >> n >> k;
	vector<int> a(k * 2);
	for(auto &c : a)
		cin >> c;
	int sum = 0;
	for(int i = k * 2 - 1; i >= 0; i --) {
		if(i % 2 == 0)
			sum += n;
		sum -= a[i];
		if(sum < 0) {cout << "No\n"; return;}
	}
	cout << ((sum == 0) ? "Yes\n" : "No\n");

}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin >> _;
	while(_--){
		solve();
	}
}