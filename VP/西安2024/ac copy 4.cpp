#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define min(x, y) x<y?x:y
const int INF = 0x3f3f3f3f3f3f3f3f;

int a[200050], b[200050];

signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    for(int i = 0; i < n; i ++)
        cin >> b[i];

    int minn = INF;

    for(int st = 0 ; st <= 1050; st ++)
    for(int k = 0; k < min(1050LL, 1000000 / n); k ++){
        int now = 0;
        bool up = 1;
        for(int j = 0; j < n; j ++){
            if(st + j * k != a[j])
                now += b[j];
            if(now > minn){
                up = 0;
                break;
            }
        }
        if(up)
            minn = min(minn, now);
    }
    cout << minn;


    return 0;
}