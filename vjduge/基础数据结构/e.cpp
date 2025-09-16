#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

bool cmp(int a,int b){
	return a > b;
}

priority_queue<int ,vector<int > >K,D,M,F;

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
	int k, d, m, f;
	cin >> k >> d >> m >> f;
	for(int i = 0, a; i < k; i ++){
		cin >> a;
		K.push(a);
	}
	for(int i = 0, a; i < d; i ++){
		cin >> a;
		D.push(a);
	}
	for(int i = 0, a; i < m; i ++){
		cin >> a;
		M.push(a);
	}
	for(int i = 0, a; i < f; i ++){
		cin >> a;
		F.push(a);
	}
	int q;
	cin >> q;
	while(q --) {
		solve();
	}
}

void solve(){
	int kk = 0, dd = 0, mm = 0, ff = 0;
	int kt = 0, dt = 0, mt = 0, ft = 0;
	cin >> dt >> mt >> ft;
	kk = K.top();
	K.pop();
	for(int i = 0 ; i < dt; i ++){
		dd += D.top();
		D.pop();
	}
	for(int i = 0 ; i < mt; i ++){
		mm += M.top();
		M.pop();
	}
	for(int i = 0 ; i < ft; i ++){
		ff += F.top();
		F.pop();
	}
	printf("%.2f\n", (double)((kk + dd + mm + ff) / 11.0));
}