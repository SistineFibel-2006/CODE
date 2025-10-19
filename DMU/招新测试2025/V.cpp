#include <bits/stdc++.h>
using namespace std;
//#include "atcoder/all"

const int N = 1e5 + 10;
int fa[N];

int find(int x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fax = find(x), fay = find(y);
	if(fax != fay)
		fa[fax] = fay;
}

signed main (){
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t;
	for(int i = 1; i <= n; i ++)
		fa[i] = i;

	for(int i = 0; i < m; i ++) {
		int x, y; cin >> x >> y;
		merge(x, y);
	}

	if(find(s) == find(t)) 
		cout << 0 << endl;
	else
		cout << 1 << endl;
}
