#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

string cha(string s) {
    char maxx = *max_element(s.begin(), s.end());
    string a;
    for (char c : s) {
        a += c;
        if (c == maxx) {
            a += "(max)";
        }
    }
    return a;
}

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	string s;
	while(cin >> s){
		cout << cha(s) << endl;



	}
}

void solve(){

}