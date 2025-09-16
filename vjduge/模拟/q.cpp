#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'

const int MAXN = 1000000;
bool b[MAXN + 1] = {0};
int sum[MAXN + 1];

signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);

	auto check = [&](int a) -> bool{
		string s = to_string(a);
		for(auto c : s){
			if (c == '4') 
				return 1;
		}
		for(int i = 0; i < s.length() - 1; ++ i){
			if(s[i] == '6' && s[i + 1] == '2')
				return 1;
		}
		return 0;
	};


	sum[0] = 0;
    for (int i = 1; i <= MAXN; i += 1) {
        b[i] = check(i);
        sum[i] = sum[i - 1] + b[i];
    }	


	int n, m;
	while(cin >> n >> m && n != 0 && m != 0) {
		int ansq = sum[m] - sum[n - 1];
		int ans = m + 1 - n - ansq;
		cout << ans << endl;
	}
}

void solve(){

}