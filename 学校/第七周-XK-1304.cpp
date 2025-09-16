#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --)
		solve();
}

void solve(){
	int n;
	scanf("%d", &n);
	n /= 10;
	switch(n){
	case 10:
	case 9: puts("A");break;
	case 8: puts("B");break;
	case 7: puts("C");break;
	case 6: puts("D");break;
	default: puts("E");
	}
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/