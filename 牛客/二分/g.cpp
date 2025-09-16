#include <bits/stdc++.h>
using namespace std;


using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

void solve(){}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n];
	int point;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		point = i;
	}
	sort(arr, arr + n);
	int sum = 0;
	for(int i = 0; arr[i] < arr[n]; i++){
		sum += arr[i];
	}
	int last = (sum+m)/point;
	// cout << last << endl;
	int ans = min(last,arr[n]);
	cout << ans << endl;
	return 0;
}

//WA
