#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int qpow(int a,int b){
	int ans=1,base=a;
	while(b){
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
int inv(int x) {
	return qpow(x, mod - 2);
}

void solve() {
	cout << qpow(2,10);
}

signed main() {
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}