#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n; 
int fa[N];
void init() {
	for(int i = 1; i <= n; i ++)
		fa[i] = i;
}

int find(int x) {
	if(x == fa[x])
		return x;
	else return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	int faa = find(a), fab = find(b);
	fa[faa] = fab;
}


void solve(){ 
	init();
	cin >> n;
	string a, b, c; cin >> a >> b >> c;
	if(c < a || c < b) {puts("No"); return;}
	for(int i = 0; i < n; i ++)
		merge(a[i] - '0', b[i] - '0');
	for(int i = 0; i < c.length(); i ++)
		if(find(c[i] - '0') == find(a[i] - '0')) {puts("No"); return;}
	puts("Yes");
}

signed main(){
	int t = 1;
	// cin >> t; 
	while(t --)
		solve();
}