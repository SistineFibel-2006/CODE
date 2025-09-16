#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
const int mod=998244353;

int qpow(int a,int b){
    a %= mod;
    if (a < 0) a += mod;
    long long ans = 1;
    long long base = a;
    long long e = b;
    while(e){
        if(e & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }
    return (int)ans;
}
int inv(int x) {
	return qpow(x, mod - 2);
}

void solve() {
	int x,y;
	cin >> x >> y;
	int a0,a1,b;
	cin >> a0 >> a1 >> b;
	b=a0+a1;
	int now=1,ans=0;
	while(x!=0&&y!=0){
		if(x>=y){
			
			int temp=((1-qpow((a1*inv(b)),x/y))%mod);
			if(temp<0)temp+=mod;
			ans=(ans+temp*now%mod)%mod;
			now=(now*qpow((a1*inv(b))%mod,x/y)%mod)%mod;
			x=x%y;
		}
		else{
			now=(now*(qpow((a0*inv(b))%mod,y/x)%mod))%mod;
			y=y%x;
		}
	}
	if (y == 0) {
        ans = (ans + now) % mod;
    }
	cout << ans << endl;
}

signed main() {
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}