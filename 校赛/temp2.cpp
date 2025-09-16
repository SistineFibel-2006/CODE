#include<bits/stdc++/h>

#define int long long

using namespace std;

signed main (){
	int n , t;
	cin >> n >> t;
	int arr[n + 1] = {0}; // arrd[n + 1] = 0;
	int l , r;
	while(t--){
		cin >> l >> r;
		arr[l] ++ ;
		arr[r + 1] --;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		arr[i] += arr[i - 1]; // arrd[i] = arr[i] + arr[i - 1];
		if(arr[i] % 2 == 0)
			ans ++;
	}

	cout << n - ans << endl;


}