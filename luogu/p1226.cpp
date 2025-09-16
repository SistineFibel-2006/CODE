#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

#define endl '\n'
int poww(int a, int b);
int mod;
signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int a, b;
	cin >> a >> b >> mod;
	int ans = poww(a,b);
	cout << a << "^" << b << " mod " << mod << "=" << ans;
	return 0;
}

int poww(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}