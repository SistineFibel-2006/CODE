#include <bits/stdc++.h>
#define int long long
using namespace std;


const int INF = 0x3f3f3f3f;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1){
        cout << "Yes\n1\n";
        return; 
    }
    if(n > m || m > n * n - n+1){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if(n == m){
        for(int i = 1; i <= n; i ++){
            for(int j = n * (i - 1) + 1, cnt = 1; cnt <= n; j ++, cnt ++)
                cout << j << ' ';
            cout << endl;
        }
        return;
    }
    int k = m;
    int a[n][m];
    a[0][0] = k;
    int now = n * n;
    for(int i = 1; i < n; i ++){
        if(now != k)
            a[i][i] = now --;
        else {
            now --;
            a[i][i] = now --;
        }
    }
    int fr = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++){
            if(i == j) 
                continue;
            if(fr == k)
                fr ++;
            a[i][j] = fr ++;
        }

    for(int i = 0 ; i < n; i ++){
        for(int j = 0; j < n; j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
            
}

signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
