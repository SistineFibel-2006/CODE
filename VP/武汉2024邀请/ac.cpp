#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;


signed main () {
    cin.tie(NULL)->sync_with_stdio(false);
    string s;
    cin >> s;
    const int n = s.length();
    int ans = 0;
    for(int i = 1; i < n; i ++){
        if(s[i] == '0' && s[i - 1] == '1')
            ans ++;
    }
    cout << ans;
    
    return 0;
}