#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

//超级板子
#define endl '\n'
void solve();


bool f[51][1010] = {0};

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int n, b, m;
	cin >> n >> b >> m;
	f[0][b] = {1}; 

 	vector<int > a(n + 1);
	for(int i = 1, c; i <= n; i ++)
		cin >> a[i];

	for(int i = 1; i <= n; i ++)
		for(int j = m; j >= 0; j--) {
			if(j + a[i] <= m)
				f[i][j] |= f[i - 1][j + a[i]];
			if(j - a[i] >= 0)
				f[i][j] |= f[i - 1][j - a[i]];
		}
 
 	for(int i = m; i >= 1; i --)
 		if(f[n][i]){
 			cout << i <<endl;
 			return 0;
 		}

 	cout << "-1" << endl;
 	

	return 0;
}

void solve(){

}