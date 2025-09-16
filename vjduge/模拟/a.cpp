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
	char a, b, c;
	// int a1, b1, c1;

	while(cin >> a >> b >> c) {
		if(a < b){
			if(b < c)
				printf("%c %c %c\n",a,b,c);
			else if(c < a)
				printf("%c %c %c\n",c,a,b);
			else
				printf("%c %c %c\n",a,c,b);
		}
		else {
			if(a < c)
				printf("%c %c %c\n",b,a,c);
			else if(c < b)
				printf("%c %c %c\n",c,b,a);
			else
				printf("%c %c %c\n",b,c,a);
		}

	}



	return 0;
}

void solve(){

}