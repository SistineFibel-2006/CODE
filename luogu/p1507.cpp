#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int hh, tt, n;
	cin >> hh >> tt >> n;

	vector<int > h(n);
	vector<int > t(n);
	vector<int > k(n);
	int f[410][410] = {0};

	for(int i = 0; i < n; i ++)
		cin >> h[i] >> t[i] >> k[i];

	for(int i = 0; i < n; i ++)
		for(int j = hh; j >= h[i]; j--)
			for(int p = tt; p >= t[i]; p--)
				f[j][p] = max(f[j][p], f[j - h[i]][p - t[i]] + k[i]);

	cout << f[hh][tt];


	return 0;
}
