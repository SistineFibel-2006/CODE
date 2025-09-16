#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int m;
	double n;
	long double sum = 0;
	while(cin >> n >> m) {
		sum = 0;
		while(m--){
			sum += n;
			n = sqrt(n); 
		}
		printf("%.2llf\n", sum);
	}


	return 0;
}

void solve(){

}