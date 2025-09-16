#include <bits/stdc++.h>
using namespace std;

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;
// using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
//void solve();

signed main (){
	//std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;

	int a[n + 1], q[n + 1] = {0}, f[n + 1] = {0}; 
	for(int i = 1; i <= n; i ++){
		scanf("%d",&a[i]);
		q[i] = a[i] + q[i - 1];
	}
	if(q[n] < 0){
		cout << "Impossible" << endl;
		return 0;
	}
	int ans = 1;
	for(int i = 1; i <= n; i ++)
		if(q[i] >= 0)
			for(int j = 0; j <= i - 1; j ++)
				if(q[i] - q[j] >= 0)
					f[i] = max(f[j] + 1, f[i]);

	cout << f[n];

	return 0;
}

//