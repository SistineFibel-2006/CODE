#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
int n, k;

bool ok(int i, int j, int x){
    cout << "? " << i << ' ' << j << ' ' << x << endl;
    int in;
    cin >> in;
    return in;
}

bool check(int x){
    int cnt = 0;
    for(int i = 1, j = n; i <= n; i ++){
        while(j >= 1 && !ok(i, j, x)){
            j --;
        }
        cnt += n - j;
    }
    return cnt >= k;
}

signed main () {
    // cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;
    int l = 1, r = n * n;
    int ans = 0; 
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid))
            l = mid + 1;
        else{
            r = mid - 1;
            ans = mid;
        }
    }
    cout << "! " << ans;
    return 0;
}