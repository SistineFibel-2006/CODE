#include <bits/stdc++.h>
using namespace std;


using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

void solve(){}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n;
	cin >> n;
	u64 temp = n * (n - 1) / 2;
	cout << temp * 2 + n - 1 << endl;

	return 0;
}