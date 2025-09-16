#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'

std::map<int,bool> mp;
// set<int> vec;

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int m, n;
	cin >> m >> n;

	vector<int> a(m);
	vector<int> b(n);

	for(int i = 0; i < m; i ++)
		cin >> a[i];
	for(int i = 0; i < n; i ++)
		cin >> b[i], mp[b[i]] = 1;
	for(int i = 0; i < m; i ++)
		if(mp[a[i]] == 1)
			cout << a[i] << " ";	
	return 0;
}
