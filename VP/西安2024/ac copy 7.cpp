#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f;



signed main () {
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int k, z;
    cin >> k >> z;
    vector<int > a(k, 0), b(k, 0);
    int c = 0;
    for(int i = 0; i < k; i ++)
        cin >> a[i];
    for(int i = k - 1; i >= 0; i --){
        if(a[i] == 1){
            c ++;
            if(c & 1)
                b[i] = 1;
            a[i] = 0;
        }
    }
    for(int i = k - 1; i >= 0; i --){
        if(a[i] & 1)
            c ++;
    }
    c += (z & 1);
    for(int i = k - 1; i >= 0; i --){
        if(!a[i])
            continue;
        if(c & 1)
            b[i] = 1;
    }
    for(int i = k - 1; i >= 0; i --)
        cout << b[i];
    return 0;
}