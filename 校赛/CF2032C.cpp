#include <bits/stdc++.h>
#define endl "\n"
#define min(x,y) x<y?x:y
#define int long long
using namespace std;


signed main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t;
cin >> t;
int n;
while (t--){
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a,a + n);
	int cnt = n - 1;
	for (int i = 0; i < n - 1; i++){
		int comp = lower_bound(a,a + n,a[i] + a[i + 1]) - a;
		cnt = min(n - comp + i, cnt);
	}
	cout << cnt << endl;
}
}
