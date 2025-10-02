#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(size_t i = a; i < b; i ++)
#define F_(i,a,b) for(size_t i = a; i > b; i --)
#define pb push_back
#define fi first
#define se second
#define in insert
#define eb emplace_back
#define all(x) x.begin(),x.end()

void solve() {
	int n,m,k,w;
	vector<int>ans;
	cin>>n>>m>>k>>w;
	int a[n+1],b[m+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	int la=1,lb=1;
	int pre=0;;;
	while(la<=n&&lb<=m){
		int cur=a[la]+k-1;
		ans.push_back(a[la]);
		if(cur>w){cout<<-1<<"\n";return;}
		if(cur>=b[lb]){

		}
		while(a[la]<=cur) la++;
		while(b[lb]<=a[la]){
			lb++;
			if(b[lb]<=a[la]) pre=b[lb];
		}

	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<" ";cout<<"\n";
}

signed main() {
    int t=1; 
    cin >> t;
    while(t --)  solve();
}