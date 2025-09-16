#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const string keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Bool",
        "_Complex", "_Imaginary"
    };

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	while(t--)
		solve();



}

void solve(){

	string s;
	getline(cin, s);
	bool flag = false;
	if((s[0] >= '0' && s[0] <= '9'))
		flag = 1;
	for(auto c : s){
		if((c >= '0' && c <= '9') || (c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c == '_'))
			continue;
		else 
			flag = 1;
	}

	// for(auto c : keywords){
	// 	if(s == c)
	// 		flag = 1;
	// }

	if(flag)
		cout << "no" << endl;
	else
		cout << "yes" << endl;
}