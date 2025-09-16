#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;


signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(double i = 0.5; i <= a; i += 1){
        double y = i * b / a;
        if(y - (int)y >= 0.5)
            ans += (int)y + 1;
        else
            ans += (int)y;
    }
    cout << ans;
    return 0;
}