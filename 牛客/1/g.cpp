#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ 
std::ios::sync_with_stdio(false);std::cin.tie(0);
    solve();
}

void solve(){
    int n;
    cin >> n;
    i64 tot = ((1 + n) * n) / 2;
    vector<int> arr(n);
    i64 sum = 0;
    for(int i = 0 ; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum != tot){
        cout << "-1" << endl;
        return;
    }
    sort(arr.begin(),arr.end());
    double tt = 0;
    for(int i = 0 ; i < n ; i ++)
        tt += abs(arr[i] - (i + 1));

    if((int)(abs(tt)) % 2 != 0){
        cout << "-1\n";
        return;
    }

    int ans = abs(tt / 2);

    cout << ans << endl;
}