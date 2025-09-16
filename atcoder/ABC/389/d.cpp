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
    double R;
    cin >> R;

    int cnt = 0;
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= R; ++j) {
            double d1 = sqrt((i + 0.5) * (i + 0.5) + (j + 0.5) * (j + 0.5));
            double d2 = sqrt((i + 0.5) * (i + 0.5) + (j - 0.5) * (j - 0.5));
            double d3 = sqrt((i - 0.5) * (i - 0.5) + (j + 0.5) * (j + 0.5));
            double d4 = sqrt((i - 0.5) * (i - 0.5) + (j - 0.5) * (j - 0.5));  
            if (d1 <= R && d2 <= R && d3 <= R && d4 <= R) {
                if (i == 0 || j == 0) {
                    cnt += 2; 
                } else {
                    cnt += 4; 
                }
            }
        }
    }
    cnt -= 1;
    cout << cnt << endl;
    return 0;
}

void solve(){

}