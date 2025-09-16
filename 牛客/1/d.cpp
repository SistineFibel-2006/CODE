#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
void solve();
//超级板子
#define endl '\n'


signed main (){ std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();
}

void solve(){
    int n;
    cin >> n;
    vector<int > a(n);
    int f = 0;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
        if(a[i] == 1)
            f = 1;
    }

    if(f){
        cout << "-1" << endl;
        return;
    } else {
        cout << "2305843009213693951" <<endl;
    }
}