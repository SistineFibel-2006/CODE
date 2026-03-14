#include <bits/stdc++.h>
#define rep(i,a,b) for(long long i = a; i < (b); i ++)
#define all(a) a.begin(),a.end()
using namespace std;
using I = int;
using Int = long long;

queue<string> anss;

#define DUP anss.push("DUP");
#define ADD anss.push("ADD");
#define PUSH anss.push("PUSH");
int cnt = 1;
int cnt2 = 0;

signed main () {
    Int x; cin >> x;
    string s = "";
    while(x != 0) s.push_back(x%2==0?'0':'1'), x/=2;
    int sz = s.length();
    PUSH;
    for(int i = 0; i < sz - 1; i ++) {
        if(s[i] == '0') {
            DUP;
            ADD;
            cnt += 2;
        } else {
            DUP;
            DUP;
            ADD;
            cnt += 3;
            cnt2 ++;
        }
    }
    // cout << s << '\n';
    assert(cnt + cnt2 <= 250);
    cout << cnt + cnt2 << '\n';
    while(!anss.empty()) {
        cout << anss.front() << '\n';
        anss.pop();
    }
    while(cnt2 --) {
        puts("ADD");
    }
}

/*
 4 = 100
 1 * 2^2
 0 * 2^1
 0 * 2^0
 25 = 11001
 1 * 2^4 = 16
 1 * 2^3 = 8
 0
 0
 1 * 2^0 = 1

 1 + 8 + 16
 */
