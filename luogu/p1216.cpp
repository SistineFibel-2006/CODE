#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'

int a[1010][1010];
int d[1010][1010];

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= i; j ++)
			cin >> a[i][j];
	for(int i = n - 1; i > 0; i --)
		for(int j = 1; j <= i; j ++)
			a[i][j] += max(a[i + 1][j],a[i + 1][j + 1]);

	cout << a[1][1] << endl;
	return 0;
}
