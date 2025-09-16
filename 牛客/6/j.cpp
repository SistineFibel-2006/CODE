#include <bits/stdc++.h>
using namespace std;
#define int long long
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
	i64 n, x, y;
	cin >> n >> x >> y;
    long long sum = 0;
    if (y >= n) {
        sum = (x + n / 2) * (n - n / 2 + 1);
    } 
    else {
    	i64 mid = n / 2;
    	if(y <= mid){
    		// cerr << "OK__";
    		if(x + y + y - n <= 1){
    			// cerr << "*";
    			sum = (x + y) * (x + y + 1) / 2;
    			cout << sum << endl;
    			return;
    		}
    		sum = ((2 * x + 3 * y - n) * (n - y)) / 2;
    		cout << sum << endl;
    		return;
    	}
    	// cerr << "OK";
    	i64 nowm = x + mid;
    	i64 tt = y - mid;
    	sum = (x + mid) * (y - mid) + (nowm);
    	nowm --;
    	if(n - y >= nowm){
    		sum += (nowm) * (nowm + 1) / 2;
    		cout << sum << endl;
    		return;
    	}
    	i64 ls = nowm - (n - y) + 1;
    	sum += (nowm + ls) * (n - y) / 2;
    }
    cout << sum << endl;	

    // i64 ans = 0;
    // i64 mid = n / 2;
    // i64 ns = min(mid + x, x + y);
    // if(mid >= y){
    // 	if(ns - (n - y) >= 0){
    // 		ans += ns * (ns + 1) / 2;
    // 		cout << ans << endl;
    // 		return;
    // 	}
    // 	i64 ls = ns - (n - y);
    // 	ans += (ns + ls) * (n - y + 1) / 2;
    // 	cout << ans << endl;
    // 	return;
    // }

    // ans += ns * (y - mid  + 1);
    // ns --;

    // if(ns - (n - y) <= 1){
    // 	ans += ns * (ns + 1) / 2;
    // 	cout << ans << endl;
    // 	return;
    // }

    // i64 ls = ns - (n - y);
    // ans += (ns + ls) * (n - y + 1) / 2;
    // cout << ans << endl;
    // return;    
}
