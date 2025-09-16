#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//³¬¼¶°å×Ó
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
    int n, m;
    cin >> n >> m;
    cout << (m - 1 + n - 2) / (n - 1) ;
}
//test
/*
?
// ? (????) ?
*/