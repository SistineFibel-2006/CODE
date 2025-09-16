#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n, 0), b;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    if(n <= 3) {cout << 1 << endl; return;}
    for(int i = 0; i < n - 2; i ++) 
        b.push_back(a[i] - 2 * a[i + 1] + a[i + 2]);
    int i = 0, ans = 0;
    while(i < n) {
        ans ++;
        if(i + 3 >= n)
            break;
        int j = i;
        while(j < b.size() && b[i] == b[j])
            j ++;
        i = j + 2;
    }
    for(auto c : b)
        cerr << c << ' ';
    cerr << endl;

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) 
      solve();
}