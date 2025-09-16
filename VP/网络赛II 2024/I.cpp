#include <bits/stdc++.h>
#include <compare>
#include <functional>
using namespace std;
#define int long long


void solve() {
	int n,nn;
	cin>>n;
	nn=n;
	int a[33];
	if(n==0||(n&-n)>=4) {cout<<"NO\n";return;}
	else cout<<"YES\n";
	for(int i=1;i<=32;i++) a[i]=-1;
	a[32]=1;
	while(n){
		a[__lg(n)]=1;
		n-=(1<<__lg(n));
	}
	if(nn%2==0) a[1]=0;
	for(int i=1;i<=32;i++) cout<<a[i]<<" ";cout<<"\n";
	int ans=0;
	for(int i=32;i>=1;i--){
		ans+=a[i]*(1ll<<(i-1));
	}
	// cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}