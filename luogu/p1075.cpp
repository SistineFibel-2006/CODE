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
	int n;cin >> n;
	for(int i = 2; i <= n; i++){
		if(n % i == 0){
			cout << n/i;
			return 0;
		}
	}

	return 0;
}

void solve(){

}