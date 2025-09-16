#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

i64 s = 0;
i64 k = 0;

signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();


	cout << s << endl;

}

void solve(){
	char a;
	cin >> a;
	if(a == '0'){
		k += 10;
		s += k;
	}
	else if(a == '1'){
		k -= 5;
		if(k < 0)
			k = 0;
		s += k;
	}
	else{
		i64 temp = k;
		k -= 10;
		if(k < 0)
			k = 0;
		s += k;
		k = temp;
	}
}