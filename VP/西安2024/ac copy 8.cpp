#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;

void press(int x, int n, bool light[]){
    light[x] ^= 1;
    for(int y = x + x; y <= n; y += x)
        press(y, n, light);
}


signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin >> t;
    for(;t --;){
        int n, k;
        cin >> n >> k;
        if(k != 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }


    return 0;
}