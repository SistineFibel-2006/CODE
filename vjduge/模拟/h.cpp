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
	int t;
	cin >> t;
	cin.ignore();
	for(int j = 0; j < t; j ++){
		string s;
		int a = 0,e = 0,i = 0,o = 0,u = 0;
		getline(cin,s);
		for(auto c : s){
			if(c == 'a')
				a++;
			if(c == 'e')
				e++;
			if(c == 'i')
				i++;
			if(c == 'o')
				o++;
			if(c == 'u')
				u++;
		}
		cout << "a:" << a << endl;
		cout << "e:" << e << endl;
		cout << "i:" << i << endl;
		cout << "o:" << o << endl;
		cout << "u:" << u << endl;
		if(j != t - 1)
			cout << '\n';
	}



}

void solve(){

}