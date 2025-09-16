#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

	map <char, int> a;
signed main (){ 
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	string s;
	cin >> s;
	
	for(int i = 0; i < 8; i ++){
		a[s[i]] += 1;
	}
	
	if(a['c'] == 1 && 
		a['d'] == 1 &&
		a['e'] == 1 &&
		a['n'] == 1 &&
		a['o'] == 2 &&
		a['r'] == 1 &&
		a['w'] == 1)
		cout << "happy new year" << endl;
	else
		cout << "I AK IOI" << endl;


}

void solve(){

}