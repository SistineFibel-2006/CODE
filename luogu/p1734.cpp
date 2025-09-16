#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
void solve();

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	auto ys = [](int n) -> int {
		int ans = 0;
		for(int i = 1; i < n; i ++)
			if(n % i == 0)
				ans += i;
		return ans;
	};
	vector<int > a(n + 1);
	vector<int > f(n + 1, 0);
	for(int i = 1; i <= n; i ++)
		a[i] = ys(i);

	for(int i = 1; i <= n; i ++)
		for(int j = n; j >= i; j --)
			f[j] = max(f[j], f[j - i] + a[i]);

	// for(auto c : a)
	// 	cout << c << endl;

	cout << f[n];


	return 0;
}

void solve(){

}