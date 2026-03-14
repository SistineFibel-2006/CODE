#include <bits/stdc++.h>
#define rep(i,a,b) for(long long i = a; i < (b); i ++)
#define all(a) a.begin(),a.end()
using namespace std;
using I = int;
using Int = long long;


signed main () {
    Int x; cin >> x;
    int cnt = 0;
    while(x != 1) {
        if(x&1) x=x*3+1;
        else x /= 2;
        cnt ++;
    }
    cout << cnt;
}

/*
 * 4 = 100
 * 1 * 2^2
 * 0 * 2^1
 * 0 * 2^0
 * 25 = 11001
 * 1 * 2^4 = 16
 * 1 * 2^3 = 8
 * 0
 * 0
 * 1 * 2^0 = 1
 *
 * 1 + 8 + 16
 */
