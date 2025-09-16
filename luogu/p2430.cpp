#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'


int f[10010] = {0};

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int q1,q2;cin >> q1 >> q2;
	int Q = q2 / q1;
	int M, N, t;cin >> M >> N;

	std::vector<int > p(M + 1), q(M + 1);
	std::map<int, int> n;
	for(int i = 1; i <= N; i ++){
		cin >> n[i];
		n[i] *= Q;
	}
	for(int i = 1; i <= M; i ++)
		cin >> p[i] >> q[i];
	cin >> t;

	for(int i = 1; i <= M; i ++)
		for(int j = t; j >= n[p[i]]; j --)
			f[j] = max(f[j], f[j - n[p[i]]] + q[i]);

	cout << f[t];





	return 0;
}
