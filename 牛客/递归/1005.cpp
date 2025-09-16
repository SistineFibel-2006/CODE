#include <bits/stdc++.h>
using namespace std;


inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

void solve(){
	int n = read();
	int k = read();
	int arr[n + 1];
	for(int i = 1; i <= n; i++){
		arr[i] = read();
	}
	sort(arr + 1, arr + n + 1);
	cout << arr[k] << '\n';
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = read();
	while(t--)
		solve();
}