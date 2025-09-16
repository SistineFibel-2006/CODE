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
	string a,b;
	getline(cin, a);
	getline(cin, b);

	for(auto c : a)
		c = tolower(c);
	for(auto c : b)
		c = tolower(c);	

	istringstream arr(b);
	string s;

	int cnt = 0, ans = -1, po = 0;

	while(arr >> s){
		if(s == a){
			cnt ++;
			if(ans == -1)
				ans = po;
		}
		po += sizeof(s) + 1;
	}

	if(cnt == 0)
		cout << "-1" << endl;
	else
		cout << cnt << " " << ans << endl;
}

void solve(){

}