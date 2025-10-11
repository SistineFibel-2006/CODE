#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long
const int mod=1000000007;
void sol() {
	int n,m;
	cin>>n>>m;
	int a[max(n, m) + 1]{0},ans=0;
	vector<int>pre(m+1, 0);
	for(int i=1;i<=n;i++) cin>>a[i];
	// pre.push_back(a[1]);
	for(int i=1;i<=m;i++){
		pre[i] = a[i];
		for(int j=1;j <= i;j++) pre[i]=(pre[i] + pre[i - j] * a[j])%mod;
		// pre.push_back(a[]);
	}
	// for(int i=0;i<pre.size();i++) ans=(ans+pre[i])%mod;
	cout<<pre[m] % mod<<"\n";
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    	sol();
}