#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int n, k, temp;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr[i] = temp % k;
	}
	sort(arr, arr + n);
	int minn = arr[0];
	int maxx = arr[n];
	for(int i = n; i >= 0; i--){
		
	}
}
