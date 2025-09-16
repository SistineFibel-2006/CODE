#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}

void solve() {
    double n;
    cin >> n;
    int res = n * 100;
    int pos = 100000;
    for(int i = 0; i < 10010; i ++){
        for(int j = 1; j < 10010; j ++){
            //  if((int)(j/double(i)*10000+0.5)==n){
            //      cout<<i; 
            //      return;
            //  }
            double x = 1.0 * i / j * 100;
            x += 0.005;
            int yes = x * 100;
            if(yes == res)
                pos = min(pos, j);
        }
    }
    cout << pos << endl;
}