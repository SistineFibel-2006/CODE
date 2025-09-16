#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int N = 3e5 + 10;

int f[N], arr[N], add[N];

void csh() {
	for(int i = 1; i <= N; i ++){
		f[i] = i;
		arr[i] = 0;
		add[i] ++;
	}
}

int find(int x) {
	if(f[x] != x){
		int r = find(f[x]);
		arr[x] += arr[f[x]];
		f[x] = r;
	}
	return f[x];
}


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	csh();
	int t;
	cin >> t;
	while(t --)
		solve();
}

void solve(){
	char a;
	int i, j;

	cin >> a >> i >> j;

	int x, y;
	if(a == 'M') {
		x = find(i);
		y = find(j);
		f[x] = y;
		arr[x] = add[y];
		add[y] += add[x];
	}
	else {
		x = find(i);
		y = find(j);
		if(x != y)
			cout << -1 << endl;
		else
			cout << abs(arr[i] - arr[j]) - 1 << endl;
	}
}