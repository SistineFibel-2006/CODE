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
	string T, U;
    cin >> T >> U;
    int lenT = T.size();
    int lenU = U.size();
    bool possible = false;

    for (int i = 0; i <= lenT - lenU; ++i) {
        bool match = true;
        for (int j = 0; j < lenU; ++j) {
            if (T[i + j] != '?' && T[i + j] != U[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << endl;
}
//test
/*
ඞ
// ٩ (◕‿◕｡) ۶
*/