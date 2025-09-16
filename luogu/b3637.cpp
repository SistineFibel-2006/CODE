#include <iostream>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
//超级板子
#define endl '\n'

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	vector<int > arr(n + 1, 0), f(n + 1, 1);

	for(int i = 1; i <= n; i ++)
		cin >> arr[i];

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= i - 1; j ++) {
			if(arr[j] < arr[i])
				f[i] = max(f[i], f[j] + 1);
		}

	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(f[i], ans);

	cout << ans;


	return 0;
}


