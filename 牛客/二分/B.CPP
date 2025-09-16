#include <bits/stdc++.h>
using namespace std;

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

#define endl '\n'

//超级板子（无 std前缀 ， endl = '\n' , 但是用真正endl可加std::）

void solve(){
	u64 l, r;
	cin >> l >> r;
	if((int)sqrt(l) == sqrt(l))
		cout << (int)sqrt(r) - (int)sqrt(l) + 1<< endl;
	if((int)sqrt(l) != sqrt(l))
		cout << (int)sqrt(r) - (int)sqrt(l)<< endl;

}

signed main (){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;cin >>t;
	while(t--)
		solve();
	return 0;
}