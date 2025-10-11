#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long

void sol() {
	int n; cin >> n;
	vector<double> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i + 1; j <= n; j ++) {
			if((i%2)==(j%2))
				cnt += a[i] > a[j];
			else
				cnt += a[i] < a[j];
		}
	
	cout << cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    	sol();
}